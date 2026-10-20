"""AICE Associate 모의고사 채점 모듈

노트북에서 사용하는 함수
    start(회차)   회차 시작, 90분 타이머 시작
    check(번호)   바로 위에서 실행한 답안 셀을 채점
    hint(번호)    오픈북 위치, 필요한 지식, 학습 순서 안내
    answer(번호)  정답 예시 보기
    setup(번호)   앞 문항을 못 풀었을 때 이 문항에 필요한 변수를 준비
    score()       현재 점수와 오답 학습 목록
"""
import json, os, re, time, html, warnings

_DIR = os.path.dirname(os.path.abspath(__file__))
with open(os.path.join(_DIR, 'aice_bank.json'), encoding='utf-8') as f:
    _BANK = json.load(f)
_D, _GUIDE, _ROUNDS = _BANK['D'], _BANK['GUIDE'], _BANK['rounds']
_ST = {'r': None, 't0': None, 'res': {}}
_SKIP = ('check(', 'hint(', 'answer(', 'setup(', 'score(', 'start(', 'from aice_grader', 'import aice_grader')

try:
    from IPython.display import display, HTML
    from IPython import get_ipython
except ImportError:  # pragma: no cover
    display = HTML = get_ipython = None


def _out(h, text):
    if display and get_ipython and get_ipython() is not None:
        display(HTML(h))
    else:
        print(text)


def _e(s):
    return html.escape(str(s))


def _norm(code):
    lines = []
    for l in code.split('\n'):
        l = re.sub(r'#.*$', '', l).replace('"', "'")
        l = re.sub(r'[ \t]', '', l)
        l = re.sub(r'\\$', '', l)
        if l:
            lines.append(l)
    out, depth = '', 0
    for l in lines:
        out += ('\n' if out and depth <= 0 else '') + l
        for ch in l:
            if ch in '([{':
                depth += 1
            elif ch in ')]}':
                depth -= 1
    return out


def _flags(f):
    v = 0
    if 'm' in f: v |= re.M
    if 'i' in f: v |= re.I
    return v


def _hit(n, rule):
    kind, pat, fl, _ = rule
    if kind == 'lit':
        return pat in n
    return re.search(pat, n, _flags(fl)) is not None


def _q(n):
    if _ST['r'] is None:
        raise RuntimeError('먼저 start(회차번호)를 실행하세요.')
    if not 1 <= n <= 14:
        raise ValueError('문항 번호는 1~14입니다.')
    return _ROUNDS[_ST['r']][n - 1]


def _timer():
    if not _ST['t0']:
        return ''
    left = _ST['t0'] + 90 * 60 - time.time()
    m, s = divmod(int(abs(left)), 60)
    return f'남은 시간 {m:02d}:{s:02d}' if left >= 0 else f'시간 초과 +{m:02d}:{s:02d}'


def _links_html(q):
    return ''.join(f'<li><a href="{_e(u)}" target="_blank">{_e(t)}</a></li>' for t, u in q['links'])


def _links_text(q):
    return '\n'.join(f'  - {t}: {u}' for t, u in q['links'])


def start(r):
    """회차 시작 (1~10). 90분 타이머가 시작됩니다."""
    if not 1 <= r <= 10:
        raise ValueError('회차는 1~10입니다.')
    _ST['r'], _ST['t0'] = r - 1, time.time()
    _ST['res'] = _load()
    d = _D[r - 1]
    task = {'reg': '회귀', 'bin': '이진분류', 'multi': '다중분류'}[d['task']]
    _out(f'<div style="border-left:4px solid #0D6B59;padding:6px 12px"><b>{r}회 · {_e(d["n"])}</b> ({task})<br>'
         f'데이터 <code>{_e(d["f"])}</code> · 타깃 <code>{_e(d["y"])}</code><br>90분 타이머를 시작했습니다. 남은 시간은 score()로 확인합니다.</div>',
         f'{r}회 · {d["n"]} ({task}) — 90분 타이머 시작')


def _path():
    return os.path.join(_DIR, 'results', f'round_{_ST["r"] + 1:02d}.json')


def _load():
    try:
        with open(_path(), encoding='utf-8') as f:
            return {int(k): v for k, v in json.load(f).items()}
    except Exception:
        return {}


def _save():
    try:
        os.makedirs(os.path.dirname(_path()), exist_ok=True)
        with open(_path(), 'w', encoding='utf-8') as f:
            json.dump(_ST['res'], f, ensure_ascii=False, indent=1)
    except Exception:
        pass


def _last_cell():
    ip = get_ipython() if get_ipython else None
    if ip is None:
        return None
    hist = ip.user_ns.get('In', [])
    for src in reversed(hist[:-1]):
        s = src.strip()
        if s and not s.startswith(_SKIP):
            return src
    return None


def _grade(q, code):
    if q['t'] == 'text':
        ok = re.search(q['ok'][0], code, _flags(q['ok'][1])) is not None
        bad = [] if ok else [m for k, p, fl, m in q['b'] if re.search(p, code, _flags(fl))]
        return ok, [], bad
    n = _norm(code)
    miss = [r[3] for r in q['c'] if not _hit(n, r)]
    bad = [r[3] for r in q['b'] if _hit(n, r)]
    return (not miss and not bad and bool(n)), miss, bad


def check(n, code=None):
    """바로 위에서 실행한 답안 셀을 채점합니다. code='...'로 직접 넘길 수도 있습니다."""
    q = _q(n)
    if code is None:
        code = _last_cell()
    if not code:
        _out('<b>채점할 답안 셀을 찾지 못했습니다.</b> 답안 셀을 먼저 실행한 뒤 check()를 실행하세요.', '채점할 답안 셀을 찾지 못했습니다.')
        return
    ok, miss, bad = _grade(q, code)
    _ST['res'][n] = {'ok': ok, 'code': code}
    _save()
    col = '#1E7A3B' if ok else '#B23628'
    h = [f'<div style="border-left:4px solid {col};padding:6px 12px;line-height:1.6">',
         f'<b style="color:{col}">{n}번 {"정답입니다" if ok else "오답입니다"}</b> <span style="opacity:.6">· {_e(q["stage"])} · {_timer()}</span>']
    t = [f'{n}번 {"정답" if ok else "오답"}']
    if not ok:
        if bad:
            h.append('<div><b>잘못된 부분</b><ul>' + ''.join(f'<li>{_e(x)}</li>' for x in bad) + '</ul></div>')
            t += ['잘못된 부분:'] + [f'  - {x}' for x in bad]
        if miss:
            h.append('<div><b>빠졌거나 다른 부분</b><ul>' + ''.join(f'<li>{_e(x)}</li>' for x in miss) + '</ul></div>')
            t += ['빠졌거나 다른 부분:'] + [f'  - {x}' for x in miss]
        h.append(f'<div><b>필요한 학습</b><br>{_e(q["s"])}</div>')
        h.append(f'<div><b>오픈북에서 찾기</b><br>{_e(q["ob"])}<ul>{_links_html(q)}</ul></div>')
        h.append('<div style="opacity:.7">정답 예시는 answer(%d), 학습 순서는 hint(%d)로 확인합니다. 같은 결과를 내는 다른 표현으로 썼다면 정답 처리: ok(%d)</div>' % (n, n, n))
        t += [f'필요한 학습: {q["s"]}', f'오픈북: {q["ob"]}', _links_text(q), f'정답 예시: answer({n}) / 학습 순서: hint({n})']
    h.append('</div>')
    _out(''.join(h), '\n'.join(t))


def ok(n):
    """자동 채점이 오답으로 판정했지만 같은 의미로 작성한 경우 정답 처리합니다."""
    _q(n)
    if n in _ST['res']:
        _ST['res'][n]['ok'] = True
        _ST['res'][n]['ov'] = True
        _save()
    print(f'{n}번을 정답 처리했습니다.')


def hint(n):
    """오픈북 경로, 필요한 지식, 모를 때의 학습 순서를 보여줍니다."""
    q = _q(n)
    g = _GUIDE[q['si']]
    h = (f'<div style="border-left:4px dashed #0D6B59;padding:6px 12px;line-height:1.6"><b>{n}번 힌트 · {_e(q["stage"])}</b>'
         f'<div><b>오픈북에서 찾는 경로</b><br>{_e(q["ob"])}<ul>{_links_html(q)}</ul></div>'
         f'<div><b>이 문제에 필요한 지식</b><br>{_e(q["s"])}</div>'
         f'<div><b>지식이 없다면 이 순서로 학습</b><ol>' + ''.join(f'<li>{_e(x)}</li>' for x in g) + '</ol></div>'
         '<div style="opacity:.7">Jupyter에서 함수명 일부를 입력하고 Tab을 누르면 자동완성, 함수 괄호 안에서 Shift+Tab을 누르면 파라미터 설명이 나옵니다.</div></div>')
    t = '\n'.join([f'{n}번 힌트 · {q["stage"]}', f'오픈북: {q["ob"]}', _links_text(q), f'필요한 지식: {q["s"]}', '학습 순서:'] + [f'  {i + 1}. {x}' for i, x in enumerate(g)])
    _out(h, t)


def answer(n):
    """정답 예시를 보여줍니다."""
    q = _q(n)
    _out(f'<div style="border-left:4px solid #5A6762;padding:6px 12px"><b>{n}번 정답 예시</b><pre>{_e(q["a"])}</pre></div>', f'{n}번 정답 예시\n{q["a"]}')


def score():
    """현재 점수, 남은 시간, 오답 학습 목록을 보여줍니다."""
    if _ST['r'] is None:
        raise RuntimeError('먼저 start(회차번호)를 실행하세요.')
    res = _ST['res']
    okn = sum(1 for v in res.values() if v['ok'])
    pt = round(okn * 100 / 14)
    wrong = sorted(k for k, v in res.items() if not v['ok'])
    todo = [k for k in range(1, 15) if k not in res]
    passed = '합격 기준 통과' if pt >= 80 else '합격 기준 80점 미달'
    h = [f'<div style="border-left:4px solid #0D6B59;padding:6px 12px;line-height:1.6"><b style="font-size:1.3em">{pt}점</b> · 정답 {okn} / 제출 {len(res)} / 14문항'
         + (f' · <b>{passed}</b>' if len(res) == 14 else '') + f' · {_timer()}']
    t = [f'{pt}점 (정답 {okn} / 제출 {len(res)} / 14) {_timer()}']
    if todo:
        h.append(f'<div>미제출: {", ".join(map(str, todo))}번</div>')
        t.append(f'미제출: {todo}')
    if wrong:
        h.append('<div><b>오답 학습 목록</b><ol>')
        t.append('오답 학습 목록:')
        for k in wrong:
            q = _ROUNDS[_ST['r']][k - 1]
            h.append(f'<li value="{k}"><b>{_e(q["stage"])}</b><br>{_e(q["s"])}<br><span style="opacity:.7">오픈북: {_e(q["ob"])}</span></li>')
            t.append(f'  {k}. {q["stage"]} — {q["s"]} (오픈북: {q["ob"]})')
        h.append('</ol></div>')
    h.append('</div>')
    _out(''.join(h), '\n'.join(t))


def reset():
    """현재 회차의 채점 기록을 지우고 타이머를 다시 시작합니다."""
    _ST['res'] = {}
    _ST['t0'] = time.time()
    _save()
    print('채점 기록을 지우고 타이머를 다시 시작했습니다.')


def setup(n):
    """앞 문항을 못 풀었을 때 실행합니다. n번 문항을 풀기 전 상태(변수)를 정답 코드 기준으로 만들어 줍니다."""
    d = _D[_q(n) and _ST['r']]
    ns = get_ipython().user_ns if get_ipython and get_ipython() is not None else globals()
    warnings.filterwarnings('ignore')
    import pandas as pd, numpy as np, seaborn as sns, matplotlib.pyplot as plt
    from sklearn.model_selection import train_test_split
    from sklearn.preprocessing import StandardScaler, MinMaxScaler, RobustScaler, LabelEncoder
    from sklearn.tree import DecisionTreeRegressor, DecisionTreeClassifier
    from sklearn.ensemble import RandomForestRegressor, RandomForestClassifier
    from sklearn.metrics import (mean_absolute_error, mean_squared_error, r2_score, accuracy_score,
                                 classification_report, confusion_matrix)
    v = dict(pd=pd, np=np, sns=sns, plt=plt, train_test_split=train_test_split, StandardScaler=StandardScaler,
             MinMaxScaler=MinMaxScaler, RobustScaler=RobustScaler, LabelEncoder=LabelEncoder,
             DecisionTreeRegressor=DecisionTreeRegressor, DecisionTreeClassifier=DecisionTreeClassifier,
             RandomForestRegressor=RandomForestRegressor, RandomForestClassifier=RandomForestClassifier,
             mean_absolute_error=mean_absolute_error, mean_squared_error=mean_squared_error, r2_score=r2_score,
             accuracy_score=accuracy_score, classification_report=classification_report, confusion_matrix=confusion_matrix)
    if n >= 13:
        from tensorflow.keras.models import Sequential
        from tensorflow.keras.layers import Dense, Dropout
        from tensorflow.keras.callbacks import EarlyStopping, ModelCheckpoint
        v.update(Sequential=Sequential, Dense=Dense, Dropout=Dropout, EarlyStopping=EarlyStopping, ModelCheckpoint=ModelCheckpoint)
    made = ['pd', 'np', 'sns', 'plt', '각종 import']
    if n >= 2:
        fp = os.path.join(_DIR, d['f'])
        df = pd.read_json(fp) if d['f'].endswith('.json') else pd.read_csv(fp)
        v['df'] = df; made.append('df')
    if n >= 6:
        df_temp = df[df[d['out']] <= d['T']].copy()
        v['df_temp'] = df_temp; made.append('df_temp')
    if n >= 7:
        a, b = d['na']
        df_temp[a] = df_temp[a].fillna(df_temp[a].median())
        df_na = df_temp.dropna()
        v['df_na'] = df_na; made.append('df_na')
    if n >= 8:
        df_del = df_na.drop(columns=[d['id']])
        v['df_del'] = df_del; made.append('df_del')
    if n >= 9:
        df_preset = pd.get_dummies(df_del, columns=d['enc'], dtype=int)
        X = df_preset.drop(d['y'], axis=1); y = df_preset[d['y']]
        v.update(df_preset=df_preset, X=X, y=y); made += ['df_preset', 'X', 'y']
    if n >= 10:
        strat = y if d['task'] != 'reg' else None
        X_train, X_valid, y_train, y_valid = train_test_split(X, y, test_size=0.2, stratify=strat, random_state=42)
        made += ['X_train', 'X_valid', 'y_train', 'y_valid']
    if n >= 11:
        scaler = StandardScaler()
        X_train = scaler.fit_transform(X_train); X_valid = scaler.transform(X_valid)
        v['scaler'] = scaler; made += ['scaler(적용됨)']
    if n >= 10:
        v.update(X_train=X_train, X_valid=X_valid, y_train=y_train, y_valid=y_valid)
    if n >= 12:
        reg = d['task'] == 'reg'
        K = 'Regressor' if reg else 'Classifier'
        dt = (DecisionTreeRegressor if reg else DecisionTreeClassifier)(max_depth=5, random_state=120).fit(X_train, y_train)
        rf = (RandomForestRegressor if reg else RandomForestClassifier)(n_estimators=100, random_state=42).fit(X_train, y_train)
        v.update(dt=dt, rf=rf); made += ['dt', 'rf']
        if d.get('mv') == 'xgb':
            import xgboost
            xgb = getattr(xgboost, 'XGB' + K)(n_estimators=100, random_state=42).fit(X_train, y_train)
            v['xgb'] = xgb; made.append('xgb')
    if n >= 13:
        v['pred'] = v[d.get('mv', 'rf')].predict(X_valid); made.append('pred')
    if n >= 14:
        out_layer = Dense(1) if reg else Dense(1, activation='sigmoid') if d['task'] == 'bin' else Dense(d['k'], activation='softmax')
        loss = 'mse' if reg else 'binary_crossentropy' if d['task'] == 'bin' else 'sparse_categorical_crossentropy'
        metric = 'mae' if reg else 'accuracy'
        from tensorflow.keras import Input
        model = Sequential([Input(shape=(X_train.shape[1],)), Dense(64, activation='relu'), Dropout(0.2), Dense(32, activation='relu'), out_layer])
        model.compile(optimizer='adam', loss=loss, metrics=[metric])
        history = model.fit(X_train, np.asarray(y_train), epochs=30, batch_size=16,
                            validation_data=(X_valid, np.asarray(y_valid)), verbose=0)
        v.update(model=model, history=history); made += ['model(학습 완료)', 'history']
    ns.update(v)
    print(f'{n}번 준비 완료: ' + ', '.join(made))


__all__ = ['start', 'check', 'hint', 'answer', 'setup', 'score', 'ok', 'reset']

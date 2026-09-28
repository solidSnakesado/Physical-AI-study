"""
AICE Associate 스타일 모의 문항 - 카시트 판매량 예측 자동 채점 모듈
(공식 샘플 문항의 14문항 구조를 참고해 새로 만든 연습 문제)

노트북에서:  from aice_grader_carseats import check, hint, score
  check(n) : n번 문항 채점      hint(n) : 힌트      score() : 전체 점수
채점은 '코드 문장'이 아니라 '결과 변수'를 확인합니다.
"""
import math
import os

import numpy as np
import pandas as pd

_DIR = os.path.dirname(os.path.abspath(__file__))
_STORE = os.path.join(_DIR, "carseats_store.csv")
_SALES = os.path.join(_DIR, "carseats_sales.csv")
_TOTAL = 14
_passed = set()
_ref = {}

_TITLES = {
    1: "scikit-learn import", 2: "pandas import", 3: "파일 읽기·병합",
    4: "지역 분포 시각화·'-' 행 삭제", 5: "가격-판매량 jointplot",
    6: "이상치 삭제·열 삭제", 7: "결측치 확인·삭제", 8: "불필요한 열 삭제",
    9: "원-핫 인코딩", 10: "데이터 분할·RobustScaler", 11: "DT·RF 모델 학습",
    12: "MAE 평가·모델 비교", 13: "딥러닝 모델 학습", 14: "학습 곡선 시각화",
}

_HINTS = {
    1: "import sklearn as sk",
    2: "import pandas as pd",
    3: "pd.read_csv(...) 2번 → pd.merge(df_store, df_sales, on='StoreID')  (기본값 how='inner')",
    4: "ax4 = sns.countplot(data=df, x='Region') → df = df[df['Region'] != '-']",
    5: "g5 = sns.jointplot(data=df, x='Price', y='Sales')",
    6: "df_temp = df[df['Price'] < 300].drop(columns='StoreID')",
    7: "df_temp.isnull().sum().sum() → df_na = df_temp.dropna()",
    8: "df_del = df_na.drop(columns=['Open_Date', 'Survey_Date'])",
    9: "object 열 목록: df_del.select_dtypes('object').columns → pd.get_dummies(df_del, columns=...)",
    10: "train_test_split(X, y, test_size=0.2, random_state=42) → RobustScaler: fit_transform(X_train), transform(X_valid)",
    11: "DecisionTreeRegressor(max_depth=5, min_samples_split=3, random_state=120) / RandomForestRegressor(같은 값)",
    12: "from sklearn.metrics import mean_absolute_error → mean_absolute_error(y_valid, 예측값)",
    13: "Sequential([Dense(..., input_shape), Dense(...), Dropout(0.2), ..., Dense(1)]) → compile(loss='mse', metrics=['mse']) → fit(..., epochs=30, batch_size=16, validation_data=(X_valid, y_valid))",
    14: "plt.plot(history.history['mse'], label='mse') / plt.plot(history.history['val_mse'], label='val_mse') / plt.legend() → ax14 = plt.gca()",
}

# 문항 4 보기 (정답: 3)
Q4_CHOICES = [
    "1. North 지역 매장 수가 가장 많다.",
    "2. 지역 정보가 '-' 로 기재된 매장이 있다.",
    "3. East 지역 매장 수가 West 지역 매장 수보다 많다.",
    "4. North 와 South 의 매장 수 차이는 10개 미만이다.",
]


# ------------------------------------------------------------------ 내부 도구
def _ns():
    try:
        from IPython import get_ipython
        ip = get_ipython()
        if ip is not None:
            return ip.user_ns
    except ImportError:
        pass
    import inspect
    return inspect.stack()[2].frame.f_globals


class _Fail(Exception):
    pass


def _need(ns, *names):
    for n in names:
        if n not in ns:
            raise _Fail(f"`{n}` 변수가 없습니다. 해당 문항의 코드 셀을 먼저 실행하세요.")
    return [ns[n] for n in names] if len(names) > 1 else ns[names[0]]


def _expect(cond, msg):
    if not cond:
        raise _Fail(msg)


def _np(a):
    return a.to_numpy() if hasattr(a, "to_numpy") else np.asarray(a)


def _same_frame(a, b):
    """행 순서·index 와 무관하게 내용이 같은지 비교"""
    if list(a.columns) != list(b.columns) or a.shape != b.shape:
        return False
    key = list(a.columns)
    a2 = a.sort_values(key).reset_index(drop=True)
    b2 = b.sort_values(key).reset_index(drop=True)
    return a2.equals(b2)


def _reference():
    if _ref:
        return _ref
    from sklearn.model_selection import train_test_split
    from sklearn.preprocessing import RobustScaler
    from sklearn.tree import DecisionTreeRegressor
    from sklearn.ensemble import RandomForestRegressor
    from sklearn.metrics import mean_absolute_error

    store, sales = pd.read_csv(_STORE), pd.read_csv(_SALES)
    df = pd.merge(store, sales, on="StoreID")
    df4 = df[df["Region"] != "-"]
    temp = df4[df4["Price"] < 300].drop(columns="StoreID")
    na = temp.dropna()
    dele = na.drop(columns=["Open_Date", "Survey_Date"])
    obj = dele.select_dtypes("object").columns.tolist()
    preset = pd.get_dummies(dele, columns=obj)
    X, y = preset.drop(columns="Sales"), preset["Sales"]
    Xtr, Xva, ytr, yva = train_test_split(X, y, test_size=0.2, random_state=42)
    rs = RobustScaler().fit(Xtr)
    Xtr_s, Xva_s = rs.transform(Xtr), rs.transform(Xva)
    dt = DecisionTreeRegressor(max_depth=5, min_samples_split=3, random_state=120).fit(Xtr_s, ytr)
    rf = RandomForestRegressor(max_depth=5, min_samples_split=3, random_state=120).fit(Xtr_s, ytr)
    dt_mae = mean_absolute_error(yva, dt.predict(Xva_s))
    rf_mae = mean_absolute_error(yva, rf.predict(Xva_s))
    _ref.update(store=store, sales=sales, df=df, df4=df4, temp=temp, na=na, dele=dele,
                preset=preset, Xtr_raw=Xtr, Xva_raw=Xva, ytr=ytr, yva=yva,
                Xtr=Xtr_s, Xva=Xva_s, dt_pred=dt.predict(Xva_s), rf_pred=rf.predict(Xva_s),
                dt_mae=dt_mae, rf_mae=rf_mae, best="rf" if rf_mae < dt_mae else "dt",
                na_cnt=int(temp.isnull().sum().sum()))
    return _ref


# ------------------------------------------------------------------ 문항별 채점
def _q1(ns):
    import types
    sk = _need(ns, "sk")
    _expect(isinstance(sk, types.ModuleType) and sk.__name__ == "sklearn",
            "`sk` 가 scikit-learn 모듈이 아닙니다.  import sklearn as sk")


def _q2(ns):
    import types
    pd_ = _need(ns, "pd")
    _expect(isinstance(pd_, types.ModuleType) and pd_.__name__ == "pandas",
            "`pd` 가 pandas 모듈이 아닙니다.  import pandas as pd")


def _q3(ns):
    r = _reference()
    s, a, df = _need(ns, "df_store", "df_sales", "df")
    _expect(isinstance(s, pd.DataFrame) and s.shape == r["store"].shape,
            f"df_store 크기가 {getattr(s, 'shape', None)} 입니다. carseats_store.csv 를 그대로 읽으세요.")
    _expect(isinstance(a, pd.DataFrame) and a.shape == r["sales"].shape,
            f"df_sales 크기가 {getattr(a, 'shape', None)} 입니다. carseats_sales.csv 를 그대로 읽으세요.")
    _expect(isinstance(df, pd.DataFrame), "`df` 가 DataFrame 이 아닙니다.")
    _expect("StoreID_x" not in df.columns,
            "StoreID_x / StoreID_y 가 생겼습니다 → on='StoreID' 로 병합 기준을 지정하세요.")
    _expect(len(df) != 404, "병합 결과가 404행입니다. 매장 정보가 없는 판매 기록까지 남았습니다 → how='inner' (기본값)")
    _expect(set(df.columns) == set(r["df"].columns), "병합 결과의 열 구성이 다릅니다.")
    # 문항 4를 먼저 푼 상태여도 인정
    _expect(len(df) in (len(r["df"]), len(r["df4"])),
            f"병합 결과가 {len(df)}행입니다. {len(r['df'])}행이어야 합니다.")


def _q4(ns):
    r = _reference()
    ax4, ans, df = _need(ns, "ax4", "답안04", "df")
    _expect(hasattr(ax4, "patches") and len(ax4.patches) >= 4,
            "`ax4` 가 countplot 결과가 아닙니다.  ax4 = sns.countplot(data=df, x='Region')")
    _expect("Region" in (ax4.get_xlabel(), ax4.get_ylabel()),
            "countplot 이 Region 열을 그리지 않았습니다.")
    _expect(len(df) != len(r["df"]), "df 에 Region 이 '-' 인 행이 아직 남아 있습니다.")
    _expect(not (df["Region"] == "-").any(), "df 에 Region 이 '-' 인 행이 남아 있습니다.")
    _expect(len(df) == len(r["df4"]), f"df 가 {len(df)}행입니다. '-' 행만 삭제했는지 확인하세요.")
    _expect(str(ans).strip() == "3", f"답안04 = {ans!r}. 그래프를 다시 보고 '옳지 않은' 설명을 고르세요.")


def _q5(ns):
    g5 = _need(ns, "g5")
    _expect(hasattr(g5, "ax_joint"), "`g5` 가 jointplot 결과가 아닙니다.  g5 = sns.jointplot(...)")
    xl, yl = g5.ax_joint.get_xlabel(), g5.ax_joint.get_ylabel()
    _expect((xl, yl) != ("Sales", "Price"), "x축과 y축이 뒤바뀌었습니다. x='Price', y='Sales'")
    _expect((xl, yl) == ("Price", "Sales"), f"x축='{xl}', y축='{yl}' 입니다. x='Price', y='Sales' 로 그리세요.")


def _q6(ns):
    r = _reference()
    t = _need(ns, "df_temp")
    _expect(isinstance(t, pd.DataFrame), "`df_temp` 가 DataFrame 이 아닙니다.")
    _expect("StoreID" not in t.columns, "df_temp 에 StoreID 열이 남아 있습니다.")
    _expect(not (t["Price"] >= 300).any(), "df_temp 에 Price 가 300 이상인 행이 남아 있습니다.")
    _expect(len(t) == len(r["temp"]),
            f"df_temp 가 {len(t)}행입니다. {len(r['temp'])}행이어야 합니다. (문항 4의 '-' 삭제 결과에서 시작)")
    _expect(_same_frame(t, r["temp"]), "df_temp 내용이 기대와 다릅니다.")


def _q7(ns):
    r = _reference()
    na, ans = _need(ns, "df_na", "답안07")
    _expect(np.ndim(ans) == 0, "답안07 은 숫자 하나여야 합니다. isnull().sum() 을 한 번 더 .sum() 하세요.")
    _expect(int(ans) == r["na_cnt"], f"답안07 = {ans}. df_temp 의 전체 결측치 개수와 다릅니다.")
    _expect(isinstance(na, pd.DataFrame) and na.isnull().sum().sum() == 0, "df_na 에 결측치가 남아 있습니다.")
    _expect(_same_frame(na, r["na"]), f"df_na 가 {na.shape} 입니다. 기대 크기는 {r['na'].shape} 입니다.")


def _q8(ns):
    r = _reference()
    d = _need(ns, "df_del")
    left = {"Open_Date", "Survey_Date"} & set(d.columns)
    _expect(not left, f"df_del 에 {sorted(left)} 열이 남아 있습니다.")
    _expect(_same_frame(d, r["dele"]),
            f"df_del 이 {d.shape} 입니다. 기대 크기는 {r['dele'].shape} 입니다. 두 열만 삭제하세요.")


def _q9(ns):
    r = _reference()
    p = _need(ns, "df_preset")
    obj = p.select_dtypes("object").columns.tolist()
    _expect(not obj, f"df_preset 에 아직 object 열이 있습니다: {obj}")
    _expect(set(p.columns) == set(r["preset"].columns),
            f"열 구성이 다릅니다. (현재 {p.shape[1]}개, 기대 {r['preset'].shape[1]}개) "
            "drop_first 등 옵션 없이 object 열 전체를 인코딩하세요.")
    _expect(len(p) == len(r["preset"]), "df_preset 의 행 수가 다릅니다.")


def _q10(ns):
    r = _reference()
    Xtr, Xva, ytr, yva = _need(ns, "X_train", "X_valid", "y_train", "y_valid")
    ntr, nva = len(r["ytr"]), len(r["yva"])
    _expect(not (len(Xtr) == nva and len(Xva) == ntr),
            "train 과 valid 가 뒤바뀌었습니다. 반환 순서: X_train, X_valid, y_train, y_valid")
    _expect(len(Xtr) == ntr and len(Xva) == nva,
            f"X_train {len(Xtr)}행 / X_valid {len(Xva)}행입니다. 80:20 이면 {ntr} / {nva} 행입니다.")
    _expect(np.shape(Xtr)[1] == r["Xtr"].shape[1], "X 에 Sales(정답 열)가 포함되었거나 열 수가 다릅니다.")
    _expect(np.allclose(np.sort(_np(ytr)), np.sort(r["ytr"].to_numpy())),
            "뽑힌 행이 다릅니다 → random_state=42 를 확인하세요.")
    _expect(not np.allclose(np.asarray(_np(Xtr), dtype=float), r["Xtr_raw"].to_numpy(dtype=float)),
            "X_train 이 스케일링되지 않았습니다 → RobustScaler 의 fit_transform 결과로 바꾸세요.")
    _expect(np.allclose(np.asarray(_np(Xtr), dtype=float), r["Xtr"]),
            "X_train 값이 기대와 다릅니다 → RobustScaler().fit_transform(X_train)  (StandardScaler 아님)")
    _expect(np.allclose(np.asarray(_np(Xva), dtype=float), r["Xva"]),
            "X_valid 값이 기대와 다릅니다 → 같은 scaler 로 transform(X_valid) 만 하세요. (다시 fit 하면 누수)")


def _q11(ns):
    r = _reference()
    from sklearn.tree import DecisionTreeRegressor
    from sklearn.ensemble import RandomForestRegressor
    dt, rf = _need(ns, "dt", "rf")
    for name, m, cls in (("dt", dt, DecisionTreeRegressor), ("rf", rf, RandomForestRegressor)):
        _expect(isinstance(m, cls), f"`{name}` 이 {cls.__name__} 가 아닙니다. (현재: {type(m).__name__})")
        p = m.get_params()
        _expect((p["max_depth"], p["min_samples_split"], p["random_state"]) == (5, 3, 120),
                f"{name} 의 하이퍼파라미터가 다릅니다: max_depth={p['max_depth']}, "
                f"min_samples_split={p['min_samples_split']}, random_state={p['random_state']}")
        _expect(hasattr(m, "n_features_in_"), f"{name} 이 아직 학습(fit)되지 않았습니다.")
    _expect(np.allclose(dt.predict(r["Xva"]), r["dt_pred"]) and np.allclose(rf.predict(r["Xva"]), r["rf_pred"]),
            "모델 예측이 기대와 다릅니다 → 스케일링된 X_train, y_train 으로 학습했는지 확인하세요.")


def _q12(ns):
    r = _reference()
    dm, rm, ans = _need(ns, "dt_mae", "rf_mae", "답안12")
    _expect(abs(float(dm) - r["dt_mae"]) < 1e-6,
            f"dt_mae = {dm}. mean_absolute_error(y_valid, dt.predict(X_valid)) 와 다릅니다.")
    _expect(abs(float(rm) - r["rf_mae"]) < 1e-6,
            f"rf_mae = {rm}. mean_absolute_error(y_valid, rf.predict(X_valid)) 와 다릅니다.")
    _expect(str(ans).strip().lower() == r["best"],
            f"답안12 = {ans!r}. MAE 는 '작을수록' 좋은 지표입니다. 'dt' 또는 'rf' 로 답하세요.")


def _q13(ns):
    r = _reference()
    model, history = _need(ns, "model", "history")
    _expect(type(model).__name__ == "Sequential", f"`model` 이 Sequential 이 아닙니다. (현재: {type(model).__name__})")
    layers = model.layers
    dense = [l for l in layers if type(l).__name__ == "Dense"]
    drops = [l for l in layers if type(l).__name__ == "Dropout"]
    _expect(len(dense) >= 3, f"Dense 층이 {len(dense)}개입니다. 히든 레이어 2개 이상 + 출력층 1개가 필요합니다.")
    _expect(dense[-1].units == 1 and layers[-1] is dense[-1], "마지막 층은 Dense(1) (값 1개를 예측하는 출력층) 이어야 합니다.")
    _expect(drops, "Dropout 층이 없습니다.")
    _expect(all(abs(d.rate - 0.2) < 1e-9 for d in drops), "Dropout 비율은 0.2 여야 합니다.")
    loss = model.loss if isinstance(model.loss, str) else getattr(model.loss, "name", str(model.loss))
    _expect(str(loss).lower() in ("mse", "mean_squared_error"), f"loss 가 {loss} 입니다. loss='mse' 로 compile 하세요.")
    h = history.history
    _expect("mse" in h and "val_mse" in h,
            f"history 에 {sorted(h)} 만 있습니다. metrics=['mse'] 와 validation_data=(X_valid, y_valid) 가 필요합니다.")
    _expect(len(h["mse"]) == 30, f"학습 epoch 가 {len(h['mse'])} 입니다. epochs=30")
    steps = history.params.get("steps")
    _expect(steps == math.ceil(len(r["ytr"]) / 16),
            f"한 epoch 의 step 수가 {steps} 입니다. batch_size=16 으로 X_train 전체를 학습하세요.")


def _q14(ns):
    ax = _need(ns, "ax14")
    _expect(hasattr(ax, "get_lines"), "`ax14` 가 그래프 축(Axes)이 아닙니다.  ax14 = plt.gca()")
    labels = [l.get_label() for l in ax.get_lines()]
    _expect(labels, "ax14 그래프가 비어 있습니다. plt.show() '이전에' ax14 = plt.gca() 를 실행하세요.")
    _expect("mse" in labels and "val_mse" in labels,
            f"선 이름(label)이 {labels} 입니다. label='mse', label='val_mse' 로 두 선을 그리세요.")
    _expect(ax.get_legend() is not None, "범례가 없습니다 → plt.legend()")
    n = {l.get_label(): len(l.get_xdata()) for l in ax.get_lines()}
    _expect(n["mse"] == 30 and n["val_mse"] == 30, "각 선의 점 개수가 epoch 수(30)와 다릅니다. history.history 값을 그리세요.")


_CHECKS = {i: f for i, f in enumerate(
    [_q1, _q2, _q3, _q4, _q5, _q6, _q7, _q8, _q9, _q10, _q11, _q12, _q13, _q14], 1)}


# ------------------------------------------------------------------ 공개 함수
def check(n):
    if n not in _CHECKS:
        print(f"문항 번호는 1~{_TOTAL} 입니다.")
        return
    head = f"[문항 {n}] {_TITLES[n]}"
    try:
        _CHECKS[n](_ns())
    except _Fail as e:
        _passed.discard(n)
        print(f"❌ {head} — 오답\n   {e}\n   (막히면 hint({n}) 실행)")
        return
    except Exception as e:
        _passed.discard(n)
        print(f"❌ {head} — 채점 중 오류: {type(e).__name__}: {e}\n   변수 형태를 확인하세요. (hint({n}))")
        return
    _passed.add(n)
    print(f"✅ {head} — 정답!")


def hint(n):
    print(f"💡 [문항 {n}] {_HINTS.get(n, '해당 문항이 없습니다.')}")


def score():
    pts = round(len(_passed) / _TOTAL * 100, 1)
    print("=" * 46)
    for i in range(1, _TOTAL + 1):
        print(f" {'✅' if i in _passed else '⬜'} 문항 {i:>2}  {_TITLES[i]}")
    print("-" * 46)
    print(f" 정답 {len(_passed)} / {_TOTAL}  →  {pts}점  {'합격' if pts >= 80 else '불합격'} (기준 80점)")
    print("=" * 46)

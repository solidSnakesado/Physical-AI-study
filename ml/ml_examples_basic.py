"""
분류 5개 / 회귀 5개 추가 예제 (성능 평가 없이 학습 → 예측까지)
- 회원가입 없이 받을 수 있는 공개 CSV (GitHub raw)
- 앞의 예제 16개와 겹치지 않는 데이터 사용
- 흐름: 데이터 읽기 → 전처리 → 모델 학습(fit) → 새 데이터 예측(predict)

[분류]
 17. Wine 와인 품종(3종)         : 선형 판별 분석(LDA)
 18. Breast Cancer 종양 양성/악성 : 에이다부스트(AdaBoost)
 19. Adult 연소득 5만 달러 초과   : 히스토그램 그래디언트 부스팅 (범주형 직접 처리)
 20. German Credit 신용 우량/불량 : 소프트 보팅 앙상블 (로지스틱 + 결정트리 + KNN)
 21. Ecoli 단백질 위치(8종)       : 선형 SVM
[회귀]
 22. Advertising 광고비 → 판매량  : 라쏘 회귀 (불필요한 특성 계수 0으로)
 23. Hitters 야구 선수 연봉       : 엑스트라 트리 회귀 (로그 변환 타깃)
 24. Carseats 카시트 판매량       : MLP 신경망 회귀
 25. Taxis 뉴욕 택시 요금         : 그래디언트 부스팅 회귀 (Huber 손실)
 26. Geyser 간헐천 분출 대기시간  : 다항 회귀 (3차)
"""
import numpy as np
import pandas as pd

from sklearn.preprocessing import StandardScaler, OneHotEncoder, PolynomialFeatures
from sklearn.compose import ColumnTransformer
from sklearn.pipeline import make_pipeline

from sklearn.discriminant_analysis import LinearDiscriminantAnalysis
from sklearn.ensemble import (
    AdaBoostClassifier, HistGradientBoostingClassifier, VotingClassifier,
    ExtraTreesRegressor, GradientBoostingRegressor,
)
from sklearn.linear_model import LogisticRegression, Lasso, LinearRegression
from sklearn.tree import DecisionTreeClassifier
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.neural_network import MLPRegressor

J = "https://raw.githubusercontent.com/jbrownlee/Datasets/master"
S = "https://raw.githubusercontent.com/mwaskom/seaborn-data/master"
V = "https://raw.githubusercontent.com/selva86/datasets/master"
SEED = 13


def title(text):
    print("\n" + "=" * 64 + f"\n{text}\n" + "=" * 64)


# ================================================================
# 분류 17. Wine 품종 : 선형 판별 분석(LDA)
#   - 이탈리아 같은 지역 3개 농장의 와인 178개, 화학 성분 13개
#   - LDA: 클래스끼리 가장 잘 떨어지는 방향(축)을 찾아 그 축 위에서 분류
# ================================================================
title("[분류 17] Wine 품종 - LinearDiscriminantAnalysis")

cols = ["alcohol", "malic_acid", "ash", "alcalinity", "magnesium", "phenols",
        "flavanoids", "nonflav_phenols", "proanthocyanins", "color_intensity",
        "hue", "od280_od315", "proline", "cultivar"]
wine = pd.read_csv(f"{J}/wine.csv", header=None, names=cols)

X = wine.drop("cultivar", axis=1)
y = wine["cultivar"]                       # 1, 2, 3
print("데이터 크기:", X.shape, "| 품종별 개수:", y.value_counts().sort_index().to_dict())

model = LinearDiscriminantAnalysis()
model.fit(X, y)

new_wine = X.sample(3, random_state=SEED)  # 예시 입력으로 3개 행 사용
print("\n예시 입력의 예측 품종:", model.predict(new_wine))
print("품종별 확률:\n", model.predict_proba(new_wine).round(3))


# ================================================================
# 분류 18. Breast Cancer : 에이다부스트
#   - 세포 검사 결과 9개 항목(1~10 점수) → 양성(0) / 악성(1)
#   - AdaBoost: 약한 모델(얕은 결정트리)을 차례로 학습하며,
#               앞 모델이 틀린 데이터에 가중치를 높여 다음 모델이 집중하도록 함
# ================================================================
title("[분류 18] Breast Cancer 양성/악성 - AdaBoostClassifier")

bc = pd.read_csv(f"{V}/BreastCancer.csv")
bc = bc.drop("Id", axis=1)                         # 환자 번호는 특성이 아님
bc["Bare.nuclei"] = bc["Bare.nuclei"].fillna(bc["Bare.nuclei"].median())

X = bc.drop("Class", axis=1)
y = bc["Class"]                                    # 0: 양성, 1: 악성
print("데이터 크기:", X.shape, "| 클래스별 개수:", y.value_counts().to_dict())

model = AdaBoostClassifier(n_estimators=100, learning_rate=0.5, random_state=SEED)
model.fit(X, y)

new_patient = pd.DataFrame([
    [2, 1, 1, 1, 2, 1, 2, 1, 1],       # 점수가 대부분 낮은 경우
    [8, 7, 8, 5, 6, 10, 7, 8, 2],      # 점수가 대부분 높은 경우
], columns=X.columns)
pred = model.predict(new_patient)
print("\n예측:", ["악성" if p == 1 else "양성" for p in pred])
print("악성일 확률:", model.predict_proba(new_patient)[:, 1].round(3))
print("\n특성 중요도 상위 3개:")
print(pd.Series(model.feature_importances_, index=X.columns)
      .sort_values(ascending=False).head(3).round(3))


# ================================================================
# 분류 19. Adult 소득 : 히스토그램 그래디언트 부스팅
#   - 인구 조사 데이터 4만 8천여 명 → 연소득 5만 달러 초과 여부
#   - 문자열 범주형 열을 category 자료형으로 바꾸면 원-핫 인코딩 없이 바로 학습 가능
#     (scikit-learn 1.4 이상의 categorical_features="from_dtype")
# ================================================================
title("[분류 19] Adult 연소득 >50K - HistGradientBoostingClassifier")

cols = ["age", "workclass", "fnlwgt", "education", "education_num",
        "marital_status", "occupation", "relationship", "race", "sex",
        "capital_gain", "capital_loss", "hours_per_week", "native_country", "income"]
adult = pd.read_csv(f"{J}/adult-all.csv", header=None, names=cols,
                    na_values="?", skipinitialspace=True)

adult = adult.drop(columns=["fnlwgt", "education"])   # 가중치 열, education_num과 중복
y = (adult["income"] == ">50K").astype(int)
X = adult.drop("income", axis=1)

cat_cols = X.select_dtypes(exclude="number").columns
X[cat_cols] = X[cat_cols].astype("category")          # 결측치(NaN)도 그대로 처리됨
print("데이터 크기:", X.shape, "| 범주형 열:", list(cat_cols))

model = HistGradientBoostingClassifier(categorical_features="from_dtype",
                                       max_iter=200, random_state=SEED)
model.fit(X, y)

new_person = pd.DataFrame([
    [28, "Private", 10, "Never-married", "Sales", "Not-in-family",
     "White", "Female", 0, 0, 40, "United-States"],
    [45, "Self-emp-inc", 14, "Married-civ-spouse", "Exec-managerial", "Husband",
     "White", "Male", 15000, 0, 55, "United-States"],
], columns=X.columns)
new_person = new_person.astype({c: X[c].dtype for c in cat_cols})  # 학습 때와 같은 범주로 맞춤

print("\n예측 (1: 5만 달러 초과):", model.predict(new_person))
print("5만 달러 초과 확률:", model.predict_proba(new_person)[:, 1].round(3))


# ================================================================
# 분류 20. German Credit : 소프트 보팅 앙상블
#   - 대출 신청자 1,000명의 계좌 상태·대출 기간·목적 등 20개 항목 → 신용 우량/불량
#   - 범주형 코드(A11, A12 ...)는 원-핫, 수치형은 표준화 → ColumnTransformer로 한 번에
#   - 소프트 보팅: 서로 다른 3개 모델의 예측 확률을 평균 내서 최종 결정
# ================================================================
title("[분류 20] German Credit 우량/불량 - VotingClassifier(soft)")

cols = ["status", "duration", "credit_history", "purpose", "amount", "savings",
        "employment", "installment_rate", "personal_status", "other_debtors",
        "residence_since", "property", "age", "other_installment", "housing",
        "existing_credits", "job", "people_liable", "telephone", "foreign_worker",
        "risk"]
credit = pd.read_csv(f"{J}/german.csv", header=None, names=cols)

X = credit.drop("risk", axis=1)
y = (credit["risk"] == 2).astype(int)              # 원본 1: 우량, 2: 불량 → 불량=1

cat_cols = X.select_dtypes(exclude="number").columns.tolist()
num_cols = X.select_dtypes(include="number").columns.tolist()
preprocess = ColumnTransformer([
    ("num", StandardScaler(), num_cols),
    ("cat", OneHotEncoder(handle_unknown="ignore"), cat_cols),
])

voting = VotingClassifier(
    estimators=[
        ("lr", LogisticRegression(max_iter=1000)),
        ("dt", DecisionTreeClassifier(max_depth=4, random_state=SEED)),
        ("knn", KNeighborsClassifier(n_neighbors=15)),
    ],
    voting="soft",
)
model = make_pipeline(preprocess, voting)
model.fit(X, y)

new_applicant = X.sample(3, random_state=SEED)     # 예시 입력으로 3개 행 사용
print("예시 입력 일부:\n", new_applicant[["status", "duration", "purpose", "amount", "age"]])
print("\n예측 (1: 불량):", model.predict(new_applicant))
print("불량일 확률:", model.predict_proba(new_applicant)[:, 1].round(3))

# 각 모델이 낸 확률도 따로 확인
Xt = model[0].transform(new_applicant)
for name, est in model[-1].named_estimators_.items():
    print(f"  {name:>3} 모델의 불량 확률:", est.predict_proba(Xt)[:, 1].round(3))


# ================================================================
# 분류 21. Ecoli 단백질 위치 : 선형 SVM
#   - 대장균 단백질 336개의 7개 측정값 → 세포 안 위치 8종류
#   - 선형 커널: 클래스 사이를 직선(초평면)으로 나눔. 클래스가 여러 개면 1:1 조합으로 확장
# ================================================================
title("[분류 21] Ecoli 단백질 위치 - SVC(kernel='linear')")

ecoli = pd.read_csv(f"{J}/ecoli.csv", header=None,
                    names=["mcg", "gvh", "lip", "chg", "aac", "alm1", "alm2", "site"])
X = ecoli.drop("site", axis=1)
y = ecoli["site"]
print("데이터 크기:", X.shape)
print("위치별 개수:", y.value_counts().to_dict())

model = make_pipeline(StandardScaler(), SVC(kernel="linear", C=1.0))
model.fit(X, y)

new_protein = X.sample(4, random_state=SEED)
print("\n예시 입력의 예측 위치:", model.predict(new_protein))


# ================================================================
# 회귀 22. Advertising : 라쏘 회귀
#   - TV·라디오·신문 광고비(천 달러) → 판매량(천 개)
#   - 라쏘(L1 규제): 영향이 작은 특성의 계수를 0으로 만들어 특성 선택 효과를 냄
# ================================================================
title("[회귀 22] Advertising 판매량 - Lasso")

ad = pd.read_csv(f"{V}/Advertising.csv", index_col=0)   # 첫 열은 행 번호
X = ad[["TV", "radio", "newspaper"]]
y = ad["sales"]
print("데이터 크기:", X.shape)

model = Lasso(alpha=1.0)
model.fit(X, y)

print("\n절편 :", round(model.intercept_, 3))
print("계수 :", {c: round(float(v), 4) for c, v in zip(X.columns, model.coef_)})
print("→ 계수가 0인 특성은 모델이 사용하지 않기로 한 특성")

new_budget = pd.DataFrame({"TV": [100, 250], "radio": [20, 40], "newspaper": [30, 10]})
print("\n새 광고비 조합:\n", new_budget)
print("예측 판매량(천 개):", model.predict(new_budget).round(2))


# ================================================================
# 회귀 23. Hitters : 엑스트라 트리 회귀
#   - 1986~87 메이저리그 타자 기록 → 연봉(천 달러)
#   - 연봉은 한쪽으로 치우친 분포라 log로 변환해 학습하고, 예측 후 exp로 되돌림
#   - 엑스트라 트리: 랜덤 포레스트와 비슷하지만 분할 기준값도 무작위로 골라 더 빠름
# ================================================================
title("[회귀 23] Hitters 연봉 - ExtraTreesRegressor")

hit = pd.read_csv(f"{V}/Hitters.csv").dropna(subset=["Salary"])   # 연봉 없는 선수 제외
hit = pd.get_dummies(hit, columns=["League", "Division", "NewLeague"], drop_first=True)

X = hit.drop("Salary", axis=1)
y = np.log(hit["Salary"])
print("데이터 크기:", X.shape)

model = ExtraTreesRegressor(n_estimators=300, min_samples_leaf=2, random_state=SEED)
model.fit(X, y)

new_player = X.sample(3, random_state=SEED)
pred_salary = np.exp(model.predict(new_player))
print("\n예시 선수 기록 일부:\n", new_player[["Hits", "HmRun", "Years", "CHits"]])
print("예측 연봉(천 달러):", pred_salary.round(0))
print("\n특성 중요도 상위 5개:")
print(pd.Series(model.feature_importances_, index=X.columns)
      .sort_values(ascending=False).head(5).round(3))


# ================================================================
# 회귀 24. Carseats : MLP 신경망 회귀
#   - 400개 매장의 가격·광고비·진열 위치 등 → 카시트 판매량(천 개)
#   - 신경망은 입력 크기에 민감하므로 수치형은 표준화, 범주형은 원-핫
# ================================================================
title("[회귀 24] Carseats 판매량 - MLPRegressor")

car = pd.read_csv(f"{V}/Carseats.csv")
X = car.drop("Sales", axis=1)
y = car["Sales"]

cat_cols = ["ShelveLoc", "Urban", "US"]
num_cols = [c for c in X.columns if c not in cat_cols]
preprocess = ColumnTransformer([
    ("num", StandardScaler(), num_cols),
    ("cat", OneHotEncoder(), cat_cols),
])
model = make_pipeline(
    preprocess,
    MLPRegressor(hidden_layer_sizes=(32, 16), alpha=1.0,
                 max_iter=3000, random_state=SEED),
)
model.fit(X, y)
print("데이터 크기:", X.shape)

# 진열 위치(ShelveLoc)만 바꿔서 판매량 예측이 어떻게 달라지는지 확인
base = X.iloc[[0]].copy()
new_store = pd.concat([base.assign(ShelveLoc=loc) for loc in ["Bad", "Medium", "Good"]])
print("\n같은 매장에서 진열 위치만 변경")
for loc, p in zip(new_store["ShelveLoc"], model.predict(new_store)):
    print(f"  {loc:>6} → 예측 판매량 {p:.2f} 천 개")


# ================================================================
# 회귀 25. Taxis : 그래디언트 부스팅 회귀 (Huber 손실)
#   - 2019년 3월 뉴욕 택시 운행 기록 → 기본 요금(fare)
#   - 탑승 시각에서 시간대·요일 특성을 만들어 사용
#   - Huber 손실: 아주 크게 벗어난 요금(이상치)의 영향을 줄여 줌
# ================================================================
title("[회귀 25] Taxis 요금 - GradientBoostingRegressor(loss='huber')")

taxi = pd.read_csv(f"{S}/taxis.csv", parse_dates=["pickup", "dropoff"]).dropna()
taxi["minutes"] = (taxi["dropoff"] - taxi["pickup"]).dt.total_seconds() / 60
taxi["hour"] = taxi["pickup"].dt.hour
taxi["weekday"] = taxi["pickup"].dt.dayofweek          # 0: 월요일
taxi = taxi[(taxi["distance"] > 0) & (taxi["minutes"] > 0)]

features = ["distance", "minutes", "passengers", "hour", "weekday",
            "color", "pickup_borough", "dropoff_borough"]
X = pd.get_dummies(taxi[features], columns=["color", "pickup_borough", "dropoff_borough"])
y = taxi["fare"]
print("데이터 크기:", X.shape)

model = GradientBoostingRegressor(loss="huber", n_estimators=300,
                                  max_depth=3, random_state=SEED)
model.fit(X, y)

trip = pd.DataFrame([
    {"distance": 2.0, "minutes": 12, "passengers": 1, "hour": 9, "weekday": 1,
     "color": "yellow", "pickup_borough": "Manhattan", "dropoff_borough": "Manhattan"},
    {"distance": 10.0, "minutes": 35, "passengers": 2, "hour": 18, "weekday": 4,
     "color": "yellow", "pickup_borough": "Manhattan", "dropoff_borough": "Queens"},
])
trip = pd.get_dummies(trip).reindex(columns=X.columns, fill_value=0)  # 학습 때와 열 맞춤
print("\n새 운행 2건 예측 요금(달러):", model.predict(trip).round(2))


# ================================================================
# 회귀 26. Geyser : 다항 회귀 (3차)
#   - 옐로스톤 올드페이스풀 간헐천의 분출 시간(분) → 다음 분출까지 대기 시간(분)
#   - 특성 x를 x, x², x³로 늘린 뒤 선형 회귀 → 곡선 형태의 관계를 표현
# ================================================================
title("[회귀 26] Geyser 대기 시간 - PolynomialFeatures + LinearRegression")

gey = pd.read_csv(f"{S}/geyser.csv")
X = gey[["duration"]]            # 2차원 형태 유지를 위해 대괄호 두 번
y = gey["waiting"]
print("데이터 크기:", X.shape)

model = make_pipeline(PolynomialFeatures(degree=3, include_bias=False),
                      LinearRegression())
model.fit(X, y)

lr = model[-1]
print("\n학습된 식: waiting = "
      f"{lr.intercept_:.2f} {lr.coef_[0]:+.2f}·x {lr.coef_[1]:+.2f}·x² {lr.coef_[2]:+.3f}·x³")

new_eruption = pd.DataFrame({"duration": [1.8, 3.0, 4.5]})
for d, w in zip(new_eruption["duration"], model.predict(new_eruption)):
    print(f"  분출 {d}분 → 다음 분출까지 약 {w:.1f}분 대기 예상")

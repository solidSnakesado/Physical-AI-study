# 핵심 개념
#   원점 기준 회전: x′ = cosθ·x + sinθ·y , y′ = −sinθ·x + cosθ·y
#   행렬은 [[cosθ, sinθ, 0], [−sinθ, cosθ, 0]]
#   영상 좌표계는 y축이 아래를 향하므로 수학좌표계와 부호 배치가 다름
#   기준점이 원점(좌측상단) -> 그대로 스면 영상이 화면 밖으로 크게 벗어남

import sys
import numpy as np
import cv2

# 삼각함수/원주율 제공 표준 모듈
import math     

src = cv2.imread("../data/tekapo.bmp")

# math.pi: 원주율 - 각도를 라디안으로 바꿀 때 사용
rad = 20 * math.pi / 180

# math.cos() / math.sin() - 회전 행렬의 코사인/사인 항 계산 (인자는 라디안)
# np.array(..., np.float32) - 2x3 회전 행렬 생성
aff = np.array([[math.cos(rad), math.sin(rad), 0],
                [-math.sin(rad), math.cos(rad), 0]], dtype=np.float32)

# cv2.warpAffine() - 회전 행렬 적용
dst = cv2.warpAffine(src, aff, (0, 0))

cv2.imshow("src", src)
cv2.imshow("dst", dst)
cv2.waitKey()
cv2.destroyAllWindows()
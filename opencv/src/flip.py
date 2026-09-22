# 대칭 변환
# cv2.flip(src, flipCode, dst=None) -> dst
# src: 입력영상, flipCode: 대칭방향 지정(양수: 좌우, 0: 상하, 음수: 좌우&상하 대칭)
# dst: 출력 영상
# 행렬 연산 ㅇ벗이 인덱스만 뒤집는 방식이라 매우 빠름
# 딥러닝 데이터 증강에서 가장 자주 쓰이는 변환 중 하나

import sys
import numpy as np
import cv2

src = cv2.imread("../data/rose.bmp")

if src is None:
    print("Image load failed!")
    sys.exit

dst = cv2.flip(src, flipCode=-1, dst=None)

cv2.imshow("dst", dst)
cv2.waitKey()
cv2.destroyAllWindows()
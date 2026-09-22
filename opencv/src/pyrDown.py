# 영상 피라미드
# cv2.pyrDown(src, dst=None, dstsize=None, borderType=None)
# src: 입력 영상, dst: 출력 영상, dstsize: 출력 영상 크기(따로 지정하지 않으면 입력 영상의 가로, 세로 크기의 1/2로 설정)
# borderType: 가장자리 픽셀 확장 방식
# 먼저 5x5 크기의 가우시안 필터를 적용 -> 짝수 행/열 제거
# 이후 짝수 행과 열을 제거하여 작은 크기의 영상을 생성
# 가우시안 필터를 먼저 적용하고 짝수행과 열을 제거
# 미리 흐리게 만든 뒤 (가우시안 필터), 솎아 내므로 resize 만 쓸때보다 계단 현상/모아레가 적음


import sys
import numpy as np
import cv2

src = cv2.imread("../data/rose.bmp")

if src is None:
    print("Image load failed!")
    sys.exit

dst = cv2.pyrDown(src, dst=None, dstsize=None, borderType=None)

cv2.imshow("dst", dst)
cv2.waitKey()
cv2.destroyAllWindows()

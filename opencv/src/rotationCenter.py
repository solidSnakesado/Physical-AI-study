import sys
import numpy as np
import cv2
import math     

src = cv2.imread("../data/tekapo.bmp")

if src is None:
    print("Image load failed!")
    sys.exit

# cv2.getRotationMatrix2D(center, angle, scale) -> retval
# center: 회전 중심 좌표, (x, y) 튜플
# angle: (반시계 방향) 회전 각도 (degree), 음수를 시계 방향
# scale: 추가적인 확대 비율
# retval: 2x3 어파인 변환 행렬, 실수형
centerPositon = (src.shape[1] / 2, src.shape[0] / 2)
rot = cv2.getRotationMatrix2D(centerPositon, 20, 0.7)

dst = cv2.warpAffine(src, rot, (0, 0))

cv2.imshow("src", src)
cv2.imshow("dst", dst)
cv2.waitKey()
cv2.destroyAllWindows()
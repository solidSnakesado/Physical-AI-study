import sys
import cv2
import numpy as np

src = cv2.imread("../data/rose.bmp", cv2.IMREAD_GRAYSCALE)

if src is None:
    print("Image load failed!")
    sys.exit()

kernal = np.ones(shape=(5, 5), dtype=np.float32) / 25

dst1 = cv2.filter2D(src, -1, kernal)
dst2 = cv2.blur(src, (3, 3))

cv2.imshow("src", src)
cv2.imshow("dst1", dst1)
cv2.imshow("dst2", dst2)
cv2.waitKey()

cv2.destroyAllWindows()
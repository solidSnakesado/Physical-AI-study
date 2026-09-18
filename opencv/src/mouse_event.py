import sys
import cv2
import numpy as np

oldx = oldy = -1

def on_mouse(event, x, y, flags, param):
    global oldx, oldy

    if event == cv2.EVENT_LBUTTONDOWN:
        oldx, oldy = x, y
        print("EVENT_LBUTTONDOWN: %d, %d" % (x, y))
    elif event == cv2.EVENT_LBUTTONUP:
        print("EVENT_LBUTTONUP: %d, %d" % (x, y))
    elif event == cv2.EVENT_MOUSEMOVE:
        if flags & cv2.EVENT_FLAG_LBUTTON:
            cv2.line(img, (oldx, oldy), (x, y), (0, 0, 255), 4, cv2.LINE_AA)
            cv2.imshow("image", img)
            oldx, oldy = x, y

img = np.ones((480, 640, 3), np.uint8) * 255

cv2.namedWindow(winname="image")
cv2.setMouseCallback("image", on_mouse, img)

# while True:
#     cv2.imshow("my_first_drawing", img)

#     if cv2.waitKey(10) == 27:
#         break

cv2.imshow("image", img)
cv2.waitKey()

cv2.destroyAllWindows()
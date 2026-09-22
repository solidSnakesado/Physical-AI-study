import sys
import numpy as np
import cv2

# 네 모서리 원과 사각형을 그린 표시용 영상 반환
def drawROI(img, corners):
    # img.copy: 원본을 보존하기 위해 복사본에만 그림
    cpy = img.copy()

    c1 = (192, 192, 255)
    c2 = (128, 128, 255)

    for pt in corners: 
        # cv2.circle(): 모서리의 반지금 25의 원 그리기, -1옵션은 내부를 채우기 위함
        cv2.circle(cpy, tuple(pt.astype(int)), 25, c1, -1, cv2.LINE_AA)

    # cv2.line(): 인접한 모서리를 이어 사각형 변 그리기
    # pt.astype(int): 실수 좌표를 정수로 변환(그리기 함수는 점수 좌표 요구)
    # tuple(): 넘파이 배열을 (x, y) 튜플로 변환
    # cv2.LINE_AA: 안티에일리어싱 - 원/선의 경계를 부드럽게
    cv2.line(cpy, tuple(corners[0].astype(int)), tuple(corners[1].astype(int)),
             c2, 2, cv2.LINE_AA)

    cv2.line(cpy, tuple(corners[1].astype(int)), tuple(corners[2].astype(int)), 
             c2, 2, cv2.LINE_AA)

    cv2.line(cpy, tuple(corners[2].astype(int)), tuple(corners[3].astype(int)), 
             c2, 2, cv2.LINE_AA)

    cv2.line(cpy, tuple(corners[3].astype(int)), tuple(corners[0].astype(int)), 
             c2, 2, cv2.LINE_AA)

    # cv2.addWeighted(img, 0.3, cpy, 0.7, 0) : 원본과 그림을 섞어 반투명 오버레이 효과
    disp = cv2.addWeighted(img, 0.3, cpy, 0.7, 0)

    return disp

def onMouse(event, x, y, flags, param):
    global srcQuad, dragSrc, ptOld, src

    if event == cv2.EVENT_LBUTTONDOWN:
        for i in range(4):
            if cv2.norm(srcQuad[i] - (x, y)) < 25:
                dragSrc[i] = True
                ptOld = (x, y)
                break

    if event == cv2.EVENT_LBUTTONUP:
        for i in range(4):
            dragSrc[i] = False

    if event == cv2.EVENT_MOUSEMOVE:
        for i in range(4):
            if dragSrc[i]:
                dx = x - ptOld[0]
                dy = y - ptOld[1]

                srcQuad[i] += (dx, dy)

                cpy = drawROI(src, srcQuad)
                cv2.imshow("img", cpy)
                ptOld = (x, y)
                break

# 입력 이미지 불러오기
src = cv2.imread("../data/scanned.jpeg")

if src is None:
    print("Image open failed!")
    sys.exit()

# 입력 영상 크기 및 출력 영상 크기
h, w = src.shape[:2]
dw = 500
dh = round(dw * 297 / 210)  # A4 용지 크기: 210x297cm

# 모서리 점들의 좌표, 드래그 상태 여부
srcQuad = np.array([[30, 30], [30, h - 30], [w - 30, h - 30], [w - 30, 30]], np.float32)
dstQuad = np.array([[0, 0], [0, dh - 1], [dw - 1, dh - 1], [dw - 1, 0]], np.float32)

dragSrc = [False, False, False, False]

# 모서리점, 사각형 그리기
disp = drawROI(src, srcQuad)

cv2.imshow("img", disp)
cv2.setMouseCallback("img", onMouse)

while True:
    key = cv2.waitKey()
    if key == 13:   # enter 키
        break
    elif key == 27: # esc 키
        cv2.destroyWindow("img")
        sys.exit()

# 투시 변환
pers = cv2.getPerspectiveTransform(srcQuad, dstQuad)
dst = cv2.warpPerspective(src, pers, (dw, dh), flags=cv2.INTER_CUBIC)

# 결과 영상 출력
cv2.imshow("dst", dst)
cv2.waitKey()
cv2.destroyAllWindows()
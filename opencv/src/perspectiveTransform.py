import sys
import numpy as np
import cv2

# 클릭한 좌표를 담을 전역 리스트
srcQuad = []

def drawCircle(event, x, y, flags, param):
    global srcQuad
    if event == cv2.EVENT_LBUTTONDOWN:
        # 4개까지만 좌표를 수집
        if len(srcQuad) < 4:
            srcQuad.append([x, y])
            print(f"클릭 {len(srcQuad)}: ({x}, {y})")
            
            # 클릭한 위치에 시각적으로 점 그리기
            cv2.circle(src, (x, y), 5, (0, 0, 255), -1)
            cv2.imshow("src", src)

src = cv2.imread("../data/pinkwink_namecard.png")

if src is None:
    print("Image load failed!")
    sys.exit()  # 괄호 추가

w, h = 720, 400
dstQuad = np.array([[0, 0], [w - 1, 0], [w - 1, h - 1], [0, h - 1]], np.float32)

# 1. 창을 먼저 띄우기
cv2.imshow("src", src)

# 2. 창이 생성된 후 마우스 콜백 등록
cv2.setMouseCallback("src", drawCircle)

# 3. 메인 루프: 4개 점이 클릭될 때까지 대기
while True:
    key = cv2.waitKey(10)
    
    # 4개 점이 모두 수집되었고 아직 결과 창이 안 떠있다면 변환 수행
    if len(srcQuad) == 4 and 'dst' not in locals():
        # 리스트를 float32 형태의 NumPy 배열로 변환
        pts1 = np.array(srcQuad, dtype=np.float32)
        
        # 투시 변환 행렬 계산 및 적용
        pers = cv2.getPerspectiveTransform(pts1, dstQuad)
        dst = cv2.warpPerspective(src, pers, (w, h))
        
        # 결과 이미지 출력
        cv2.imshow("dst", dst)
    
    # ESC 키(27) 누르면 종료
    if key == 27:
        break

cv2.destroyAllWindows()
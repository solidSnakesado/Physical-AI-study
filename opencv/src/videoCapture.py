import cv2
from datetime import datetime

cap = cv2.VideoCapture(0)

if not cap.isOpened():
    print("카메라를 열 수 없습니다.")
    exit()

while True:
    ret, frame = cap.read()

    if not ret:
        break

    cv2.imshow("Camera", frame)

    key = cv2.waitKey(1) & 0xFF

    if key == ord('c'):
        filename = datetime.now().strftime("capture_%Y%m%d_%H%M%S.jpg")
        cv2.imwrite(filename, frame)
        print(f"촬영 완료: {filename}")

    elif key == ord('q') or key == 27:
        break

cap.release()
cv2.destroyAllWindows()
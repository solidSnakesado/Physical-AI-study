import sys
from PyQt6.QtWidgets import *
from PyQt6.QtGui import *
from PyQt6 import uic
import cv2, imutils
from opencv_ui import Ui_Dialog                                     # 변환된 파일에서 UI 클래서 import
from MyThread import MyTimer
import datetime

class WindowClass(QMainWindow, Ui_Dialog) :
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.setWindowTitle("OpenCV")

        self.pixmap     = QPixmap()
        self.isCameraOn = False                                     # 카메라 on/off 토글
        self.camera_timer = MyTimer()                               # MyTimer 생성
        self.camera_timer.setInterval(0.1)                          # timeout 주기는 1초
        self.count = 0                                              # test 변수

        self.isRecording = False
        self.btnRecord.hide()
        self.record_timer = MyTimer()
        self.record_timer.setInterval(0.1)

        self.btnCapture.hide()

        self.btnOpen.clicked.connect(self.openFile)
        self.btnCamera.clicked.connect(self.clickCamera)
        self.camera_timer.timeout.connect(self.updateCamera)
        self.btnRecord.clicked.connect(self.clickRecord)
        self.record_timer.timeout.connect(self.updateRecord)
        self.btnCapture.clicked.connect(self.capture)
        self.btnOpenVideo.clicked.connect(self.openVideo)

    def openVideo(self):
        filename = QFileDialog.getOpenFileName(filter="Video (*.avi)")
        self.video = cv2.VideoCapture(filename[0])

        if self.video.isOpened():
            self.camera_timer.start()

    def capture(self):
        self.now = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
        filename = self.now + ".png"

        cv2.imwrite(filename, cv2.cvtColor(self.image, cv2.COLOR_RGB2BGR))

    def updateRecord(self):
        # self.label2.setText(str(self.count))
        # self.count += 1
        bgr_frame = cv2.cvtColor(self.image, cv2.COLOR_RGB2BGR)     # 저장 시에 이미지의 픽셀 내 색생 채널의 순서를 변경 처리, PyQt6(화면 출력)와 OpenCV(파일 저장)가 색상 데이터를 읽는 메모리 채널 순서 기준이 반대이기 때문에 추가 처리
        self.writer.write(bgr_frame)

    def startRecording(self):
        self.now = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
        filename = self.now + ".avi"

        self.fourcc = cv2.VideoWriter_fourcc(*"XVID")
        w = int(self.video.get(cv2.CAP_PROP_FRAME_WIDTH))
        h = int(self.video.get(cv2.CAP_PROP_FRAME_HEIGHT))

        self.writer = cv2.VideoWriter(filename, self.fourcc, 20.0, (w, h))

        self.record_timer.start()

    def stopRecording(self):
        self.record_timer.stop()

        if self.isRecording == True:
            self.writer.release()
            self.isRecording = False

    def clickRecord(self):
        if self.isRecording == False:
            self.btnRecord.setText("Rec Stop")
            self.isRecording = True
            self.record_timer.start()
            self.startRecording()
        else:
            self.btnRecord.setText("Rec Start")
            self.isRecording = False
            self.record_timer.stop()
            self.stopRecording()

    def updateCamera(self):
        # self.label.setText("Camera Running : " + str(self.count)) # count 출력
        # self.count += 1
        retval, image = self.video.read()                           # retval (bool): 프레임을 정상적으로 가져왔는 지를 나타내는 성공 여부 플래그
        if retval:
            self.image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)     # OpenCV 가 사용하는 기본 색상 포맷인 BGR을 PyQt의 QImage 가 사용하는 RGB 포맷으로 색상 공간을 변환하여 저장
            
            h, w, c = self.image.shape                              # 이미지 객체의 차원 정보를 언패킹 (h: 세로 픽셀수, w: 가로 픽셀수, c: 색상 채널 수(RGB의 경우 3))
            qimage = QImage(self.image.data,                        # 이미지의 바이너리 데이터
                            w, h,                                   # w, h: 이미지 너비와 높이
                            w * c,                                  # Byte Per Line: 이미지의 한 행(Row)이 차지하는 총 바이트 크기(너비 x 채널), 이 값이 정확하게 전달되어야 이미지가 기울어지거나 깨지는 현상이 방지됨  
                            QImage.Format.Format_RGB888)            # RGB 각 채널당 8비트를 사용하는 24비트 컬러 포맷

            self.pixmap = self.pixmap.fromImage(qimage)             # 생성된 QImage(qimage) 를 PyQt UI 위젯에 출력하기에 최적화된 형태인 QPixmap 객체로 변환하여 self.pixmap 에 저자
            self.pixmap = self.pixmap.scaled(self.label.width(), 
                                             self.label.height())

            self.label.setPixmap(self.pixmap)
        else:
            # 동영상 재생으로 진행되었을때 동영상 재생이 끝났거나 프레임을 읽기 못했을 경우 처리
            self.camera_timer.stop()
            self.video.release()

    def clickCamera(self):
        if self.isCameraOn == False:                                # 카메라가 꺼져 있는 상태라면 On 으로 전환
            self.btnCamera.setText("Camera Off")
            self.isCameraOn = True
            self.camera_timer.start()
            self.video = cv2.VideoCapture(-1)                       # VideoCapture 객체를 생성하여 카메라 장치를 open, -1 또는 0 전달: 시스템에 연결된 기본 웹캠/카메라 장치를 자동으로 선택
            self.btnRecord.show()
            self.btnCapture.show()
        else:                                                       # 카메라가 켜져 있는 상태라면 Off 로 전환
            self.btnCamera.setText("Camera On")
            self.isCameraOn = False
            self.camera_timer.stop()
            self.video.release()                                    # 카메라 해제
            self.btnRecord.hide()
            self.btnCapture.hide()
            self.stopRecording()

    def openFile(self):
        file = QFileDialog.getOpenFileName(filter="Image (*.png *.jpg)")

        image = cv2.imread(file[0])
        image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

        h, w, c = image.shape
        qimage = QImage(image.data, w, h, w * c, QImage.Format.Format_BGR888)

        self.pixmap = self.pixmap.fromImage(qimage)
        self.pixmap = self.pixmap.scaled(self.label.width(), 
                                         self.label.height())

        self.label.setPixmap(self.pixmap)

if __name__ == "__main__":
    app = QApplication(sys.argv)    # 프로그램 실행
    myWindows = WindowClass()       # 화면 클래스 생성
    myWindows.show()                # 프로그램 화면 디스플레이
    sys.exit(app.exec())            # 프로그램 종료까지 동작시킴
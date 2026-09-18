import sys
from PyQt6.QtWidgets import *
from PyQt6.QtGui import *
from PyQt6 import uic
from PyQt6.QtCore import Qt, QByteArray, QBuffer
import urllib.request

from_class = uic.loadUiType("Test8.ui")[0]

class WindowClass(QMainWindow, from_class):
    # region Test8.ui 내부 위젯들의 타입 명시
    btnApply:       QPushButton
    btnImageLoad:   QPushButton
    btnImageSave:   QPushButton
    editMax:        QLineEdit
    editMin:        QLineEdit
    editStep:       QLineEdit
    spinBox:        QSpinBox
    spinBoxValue:   QLabel
    labelPixmap:    QLabel
    sliderValue:    QLabel
    slider:         QSlider
    # endregion

    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.setWindowTitle("Test 8")

        # 숫자는 오른쪽 정렬
        self.spinBox.setAlignment(Qt.AlignmentFlag.AlignRight)
        self.editMax.setAlignment(Qt.AlignmentFlag.AlignRight)
        self.editMin.setAlignment(Qt.AlignmentFlag.AlignRight)
        self.editStep.setAlignment(Qt.AlignmentFlag.AlignRight)
        self.spinBoxValue.setAlignment(Qt.AlignmentFlag.AlignRight)
        self.sliderValue.setAlignment(Qt.AlignmentFlag.AlignRight)

        # 숫자형만 입력되도록 지정
        self.editMax.setValidator(QIntValidator())
        self.editMin.setValidator(QIntValidator())
        self.editStep.setValidator(QIntValidator())

        # 실제 min, max, step 설정값만 가져와서
        min     = self.spinBox.minimum()
        max     = self.spinBox.maximum()
        step    = self.spinBox.singleStep()

        # 출력
        self.editMax.setText(str(max))
        self.editMin.setText(str(min))
        self.editStep.setText(str(step))

        # slider 속성값을 spinBox와 통일
        self.slider.setRange(int(min), int(max))
        self.slider.setSingleStep(int(step))

        url= "https://imageio.forbes.com/specials-images/imageserve/61b1f75e9bdd78e1c08fdd64/A-funny-labrador-dog-with-a-curiously-placed-bubble-in-its-behind-/0x0.jpg?crop=922%2C956%2Cx0%2Cy279%2Csafe&width=960&dpr=1"
        image   = urllib.request.urlopen(url).read()

        self.pixmap = QPixmap()
        # self.pixmap.load("../data/cat.png")
        self.pixmap.loadFromData(image)

        self.pixmap = self.pixmap.scaled(self.labelPixmap.width(), self.labelPixmap.height())
        self.labelPixmap.setPixmap(self.pixmap)
        # self.labelPixmap.resize(self.pixmap.width(), self.pixmap.height())

        self.btnApply.clicked.connect(self.apply)
        self.spinBox.valueChanged.connect(self.changeSpinBoxValue)
        self.slider.valueChanged.connect(self.changeSliderValue)
        self.btnImageSave.clicked.connect(self.saveImage)
        self.btnImageLoad.clicked.connect(self.loadImage)

    def loadImage(self):
        name = QFileDialog.getOpenFileName(self, "Load Image", "../data/")
        if name[0]:
            self.pixmap = QPixmap(name[0])
            self.pixmap = self.pixmap.scaled(
                self.labelPixmap.width(), 
                self.labelPixmap.height(),
                Qt.AspectRatioMode.KeepAspectRatio) # 이미지의 비율 유지를 위한 설정
            self.labelPixmap.setPixmap(self.pixmap)               

    def saveImage(self):
        byte_array = QByteArray()                   # 이미지를 바이너리에 담아둘 QByteArray 변수 생성
        # buffer 는 byte_array 의 메모리 주소를 직접 참조하므로, 두 객체는 하나로 연결된 상태가 됨
        buffer = QBuffer(byte_array)                # QByteArray의 메모리를 참조하는 I/O 버퍼(QBuffer) 생성 및 연동
        # QPixmap 의 원시 픽셀 데이터가 PNG 포맷으로 변환되어 buffer 를 거쳐 byte_array 내부에 실시간으로 기록
        self.pixmap.save(buffer, "PNG")             # QPixmap 픽셀 데이터를 PNG 포맷으로 인코딩하여 버퍼(QByteArray)에 기록
        buffer.close()                              # 쓰기 작업이 완료된 버퍼 스트립 마감 및 자원 정리
        QFileDialog.saveFileContent(byte_array, "") # 인코딩된 바이너리 데이터를 파일 저장 대화상자를 통해 저장

    def apply(self):
        # 수정된 값을 가져와서 지정
        min     = self.editMin.text()
        max     = self.editMax.text()
        step    = self.editStep.text()

        self.spinBox.setRange(int(min), int(max))
        self.spinBox.setSingleStep(int(step))
        self.slider.setRange(int(min), int(max))
        self.slider.setSingleStep(int(step))

    def changeSpinBoxValue(self):
        # curSpinBoxVal = self.spinBox.text()
        curSpinBoxVal = self.spinBox.value()
        self.spinBoxValue.setText(str(curSpinBoxVal))
        self.slider.setValue(curSpinBoxVal)

    def changeSliderValue(self):
        curSliderVal = self.slider.value()
        self.sliderValue.setText(str(curSliderVal))
        self.spinBox.setValue(curSliderVal)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    myWindow = WindowClass()
    myWindow.show()
    sys.exit(app.exec())
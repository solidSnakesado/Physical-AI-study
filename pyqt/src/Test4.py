import sys
import re       # 파이썬 내장 정규표현식 모듈
from PyQt6.QtWidgets import *
from PyQt6.QtGui import *
from PyQt6 import uic
from PyQt6.QtCore import Qt

from_class = uic.loadUiType("Test4.ui")[0]

class WindowClass(QMainWindow, from_class):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.setWindowTitle("Test 4")

        self.addButton.clicked.connect(self.addText)
        self.ubuntuButton.clicked.connect(lambda: self.setFont("Ubuntu"))
        self.nanumButton.clicked.connect(lambda: self.setFont("NanumGothic"))

        self.redButton.clicked.connect(lambda: self.setColor(255, 0, 0))
        self.blueButton.clicked.connect(lambda: self.setColor(0, 0, 255))
        self.greenButton.clicked.connect(lambda: self.setColor(0, 255, 0))

        self.fontSizeButton.clicked.connect(self.setTextSize)
        self.fontSizeLine.returnPressed.connect(self.setTextSize)       # 엔터ㅣ 지원
        self.fontSizeLine.setAlignment(Qt.AlignmentFlag.AlignRight)     # 숫자는 오른쪽 정렬
        self.fontSizeLine.textChanged.connect(self.filter_non_digits)

        self.outputText.setReadOnly(True)
        validator = QIntValidator(1, 30, self.fontSizeLine)
        self.fontSizeLine.setValidator(validator)

    def setTextSize(self):
        size = int(self.fontSizeLine.text())
        self.outputText.selectAll()
        self.outputText.setFontPointSize(size)
        self.outputText.moveCursor(QTextCursor.MoveOperation.End)
        self.fontSizeLine.clear()                                       # 적용 후 입력값 자동삭제

    def setColor(self, r, g, b):
        color = QColor(r, g, b)
        self.outputText.selectAll()
        self.outputText.setTextColor(color)
        self.outputText.moveCursor(QTextCursor.MoveOperation.End)

    def setFont(self, fontName):
        font = QFont(fontName, 11)
        self.outputText.setFont(font)

    def addText(self):
        input = self.inputText.toPlainText()
        self.inputText.clear()
        self.outputText.append(input)

    def filter_non_digits(self, text):
        clean_text = re.sub(r"[^0-9]", "", text)
        if clean_text:
            if int(clean_text) > 30:
                clean_text = "30"
            elif int(clean_text) == 0:
                clean_text = ""

        if text != clean_text:
            self.fontSizeLine.setText(clean_text)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    myWindow = WindowClass()
    myWindow.show()
    sys.exit(app.exec())
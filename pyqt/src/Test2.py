import sys
from PyQt6.QtWidgets import *
from PyQt6.QtGui import *
from PyQt6 import uic
from PyQt6.QtCore import *

from_class = uic.loadUiType("Test2.ui")[0]

class WindoeClass(QMainWindow, from_class):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.setWindowTitle("Test2")
        self.countButton.clicked.connect(self.increment)
        self.resetButton.clicked.connect(self.reset)
        self.submitButton.clicked.connect(self.submit)
        # self.inputLine.textChanged.connect(self.change)
        self.inputLine.returnPressed.connect(self.input)

        self.count = 0
        self.label.setText(str(self.count))     # 프로그램 시작 시 0 출력
        self.outputLine.setReadOnly(True)

    def increment(self):
        self.count += 1
        self.label.setText(str(self.count))     # 1 증가된 count 값 출력

    def reset(self):
        self.count = 0                          # count 값 초기화
        self.label.setText(str(self.count))

    def submit(self):
        self.label.setText(self.lineEdit.text())
        self.lineEdit.clear()

    def change(self):
        self.outputLine.setText(self.inputLine.text())

    def input(self):
        self.outputLine.setText(self.inputLine.text())

if __name__ == "__main__":
    app = QApplication(sys.argv)
    myWindows = WindoeClass()
    myWindows.show()
    sys.exit(app.exec())
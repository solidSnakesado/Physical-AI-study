import sys
from PyQt6.QtWidgets import *
from PyQt6.QtGui import *
from PyQt6 import uic
from PyQt6.QtCore import *
from datetime import datetime

from_class = uic.loadUiType("Test6.ui")[0]

class WindowClass(QMainWindow, from_class):
    # Test6.ui 내부 위젯들의 타입 명시 (VS Code 자동완성용)
    cbYear:     QComboBox
    cbMonth:    QComboBox
    cbDay:      QComboBox
    lineEdit:   QLineEdit

    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.setWindowTitle("Test 6")

        for year in range(1900, 2025 + 1):                          # 1900년 ~ 2025년
            self.cbYear.addItem(str(year))

        for month in range(1, 12 + 1):                              # 1월 ~ 12월
            self.cbMonth.addItem(str(month))

        for day in range(1, 31 + 1):                                # 1월 ~ 31일
            self.cbDay.addItem(str(day))

        self.cbYear.setCurrentText(str(2000))                       # 기본선택은 2000년
        self.lineEdit.setAlignment(Qt.AlignmentFlag.AlignRight)     # 오른쪽 정렬

        # 년월일 중 바뀌는 값이 있으면 함수 호출
        self.cbYear.currentIndexChanged.connect(self.printBirthDate)
        self.cbMonth.currentIndexChanged.connect(self.printBirthDate)
        self.cbDay.currentIndexChanged.connect(self.printBirthDate)

    def printBirthDate(self):
        year    = self.cbYear.currentText()                         # 선택한 년
        month   = self.cbMonth.currentText()                        # 선택한 월
        day     = self.cbDay.currentText()                          # 선택한 일

        self.lineEdit.setText(year + month.zfill(2) + day.zfill(2))

if __name__ == "__main__":
    app = QApplication(sys.argv)
    myWindow = WindowClass()
    myWindow.show()
    sys.exit(app.exec())
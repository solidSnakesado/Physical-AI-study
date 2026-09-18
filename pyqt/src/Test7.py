import sys
from PyQt6.QtWidgets import *
from PyQt6 import uic
from PyQt6.QtCore import QRegularExpression
from PyQt6.QtGui import QRegularExpressionValidator

from_class = uic.loadUiType("Test7.ui")[0]

class WindowClass(QMainWindow, from_class):
    # Test6.ui 내부 위젯들의 타입 명시 (VS Code 자동완성용)
    btnAdd:         QPushButton
    editBirthDate:  QDateEdit
    editGender:     QLineEdit
    editName:       QLineEdit
    tableWidget:    QTableWidget

    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.setWindowTitle("Test 7")

        self.tableWidget.setColumnCount(3)
        self.tableWidget.setHorizontalHeaderLabels(["Name", "Gender", "BirthDate"])                 # add column
        self.tableWidget.horizontalHeader().setSectionResizeMode(QHeaderView.ResizeMode.Stretch)    # resize column

        self.btnAdd.clicked.connect(self.add)

        regx                = QRegularExpression("[F|M]")
        gender_validator    = QRegularExpressionValidator(regx, self.editGender)


    def add(self):
        row_index = self.tableWidget.rowCount()                                                     # 테이블의 현재 row count == 추가할 row index
        self.tableWidget.insertRow(row_index)                                                       # 비어있는 row 를 추가한다.
        self.tableWidget.setItem(row_index, 0, QTableWidgetItem(self.editName.text()))              # 1번째 column
        self.tableWidget.setItem(row_index, 1, QTableWidgetItem(self.editGender.text()))            # 2번째 column
        self.tableWidget.setItem(row_index, 2, QTableWidgetItem(self.editBirthDate.text()))         # 3번째 column

if __name__ == "__main__":
    app = QApplication(sys.argv)
    myWindow = WindowClass()
    myWindow.show()
    sys.exit(app.exec())
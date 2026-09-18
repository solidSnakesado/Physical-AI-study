import sys
from PyQt6.QtWidgets import *
from PyQt6.QtGui import *
from PyQt6 import uic
from PyQt6.QtCore import *

from_class = uic.loadUiType("Test.ui")[0]

class WindowClass(QMainWindow, from_class) :
    def __init__(self):
        super().__init__()
        self.setupUi(self)

        self.setWindowTitle("Test PyQt!")
        # self.textEdit.setText("This is text editor.")

        # 버튼을 클릭하면 함수를 호출
        self.button1.clicked.connect(self.clickButton1)
        self.button2.clicked.connect(self.clickButton2)
        self.button3.clicked.connect(self.clickButton3)

        self.radio1.clicked.connect(self.clickRadio)
        self.radio2.clicked.connect(self.clickRadio)
        self.radio3.clicked.connect(self.clickRadio)

        self.checkBox1.clicked.connect(self.clickCheckBox1)
        self.checkBox2.clicked.connect(self.clickCheckBox2)
        self.checkBox3.clicked.connect(self.clickCheckBox3)
        self.checkBox4.clicked.connect(self.clickCheckBox4)

        self.disableCheck(self.checkBox5)
        self.disableCheck(self.checkBox6)
        self.disableCheck(self.checkBox7)
        self.disableCheck(self.checkBox8)

    def clickButton1(self):
        self.textEdit.setText("Button 1")
        self.radio1.setChecked(True)

    def clickButton2(self):
        self.textEdit.setText("Button 2")
        self.radio2.setChecked(True)

    def clickButton3(self):
        self.textEdit.setText("Button 3")
        self.radio3.setChecked(True)

    def clickRadio1(self):
        self.textEdit.setText("Radio 1")

    def clickRadio2(self):
        self.textEdit.setText("Radio 2")

    def clickRadio3(self):
        self.textEdit.setText("Radio 3")

    def clickRadio(self):
        if self.radio1.isChecked():
            self.textEdit.setText("Radio 1")
        elif self.radio2.isChecked():
            self.textEdit.setText("Radio 2")
        elif self.radio3.isChecked():
            self.textEdit.setText("Radio 3")
        else:
            self.textEdit.setText("Unknown")

    def clickCheckBox1(self):
        self.textEdit.setText("CheckBox 1")
        self.checkBox5.setChecked(self.checkBox1.isChecked())

    def clickCheckBox2(self):
        self.textEdit.setText("CheckBox 2")
        self.checkBox6.setChecked(self.checkBox2.isChecked())

    def clickCheckBox3(self):
        self.textEdit.setText("CheckBox 3")
        self.checkBox7.setChecked(self.checkBox3.isChecked())

    def clickCheckBox4(self):
        self.textEdit.setText("CheckBox 4")
        self.checkBox8.setChecked(self.checkBox4.isChecked())

    def disableCheck(self, checkbox):
        checkbox.setAttribute(Qt.WidgetAttribute.WA_TransparentForMouseEvents, True)
        checkbox.setFocusPolicy(Qt.FocusPolicy.NoFocus)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    myWindows = WindowClass()
    myWindows.show()
    sys.exit(app.exec())
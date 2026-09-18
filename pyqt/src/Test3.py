import sys
from PyQt6.QtWidgets import *
from PyQt6.QtGui import *
from PyQt6 import uic
from PyQt6.QtCore import *

from_class = uic.loadUiType("Test3.ui")[0]

class WindowClass(QMainWindow, from_class):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.setWindowTitle("Test 3")
        self.addButton.clicked.connect(self.addText)
        self.inputLine.returnPressed.connect(self.addText)
        self.clearButton.clicked.connect(self.clearText)

    def clearText(self):
        self.outputText.clear()

    def addText(self):
        self.outputText.append(self.inputLine.text())
        self.inputLine.clear()

if __name__ == "__main__":
    app = QApplication(sys.argv)
    myWindow = WindowClass()
    myWindow.show()
    sys.exit(app.exec())
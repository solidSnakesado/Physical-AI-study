import sys
from PyQt6.QtWidgets import *
from PyQt6.QtGui import *
from PyQt6 import uic
from PyQt6 import QtGui
from PyQt6.QtCore import Qt
import urllib.request

from_class = uic.loadUiType("paint.ui")[0]

class WindowClass(QMainWindow, from_class) :
    # region paint.ui 내부 위젯들의 타입 명시
    label: QLabel
    # endregion

    def __init__(self):
        super().__init__()
        self.setupUi(self)

        self.pixmap = QtGui.QPixmap(self.label.width(), self.label.height())
        self.pixmap.fill(Qt.GlobalColor.red)

        self.label.setPixmap(self.pixmap)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    myWindow = WindowClass()
    myWindow.show()
    sys.exit(app.exec())
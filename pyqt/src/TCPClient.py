import sys
from PyQt6.QtWidgets    import *
from PyQt6.QtGui        import * 
from PyQt6              import uic
from PyQt6.QtCore       import QRegularExpression
from PyQt6.QtGui        import QRegularExpressionValidator
from PyQt6.QtCore       import QTimer
from struct             import Struct
from TCPClient_ui       import Ui_Dialog
import socket

class WindowClass(QMainWindow, Ui_Dialog):
    def __init__(self):
        super().__init__()
        self.setupUi(self)

        self.connected = False
        self.timer = QTimer(self)

        # ip address format
        range = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])"
        ipRegex = QRegularExpression("^" + range + "\\." + range + "\\." + range + "\\." + range + "$")

        self.ipEdit.setValidator(QRegularExpressionValidator(ipRegex, self))
        self.portEdit.setValidator(QIntValidator())
        self.degreeEdit.setValidator(QIntValidator())

        self.setWindowTitle("TCP Client")
        self.connectButton.clicked.connect(self.connect)
        self.led21.clicked.connect(self.clickLED21)
        self.led22.clicked.connect(self.clickLED22)
        self.led23.clicked.connect(self.clickLED23)
        self.moveButton.clicked.connect(self.clickMove)
        self.timer.timeout.connect(self.updateSensor)

    # def test(self):
    #     send_message = "Hello TCP!"
    #     self.sock.send(send_message.encode())

    #     recv_message = ""
    #     while len(recv_message) < len(send_message):
    #         recv_message += self.sock.recv(1).decode()

    #     print(recv_message)

    def __del__(self):
        if self.connected == True:
            self.sock.close()

    def connect(self):
        if self.connected == True:
            self.sock.close()
            self.connectButton.setText("Connect")
            self.timer.stop()
            self.connected = False
        else:
            ip = self.ipEdit.text()
            port = self.portEdit.text()

            self.sock = socket.socket()
            self.sock.connect((ip, int(port)))
            self.connectButton.setText("Disconnect")

            # self.connectButton.setText("Connected")
            # self.connectButton.setDisabled(True)

            self.format = Struct('@ii')
            self.connected = True
            self.timer.start(500)
            # self.test()
            # self.sock.close()

    def send(self, pin, status):
        data = self.format.pack(pin, status)
        req = self.sock.send(data)
        rev = self.format.unpack(self.sock.recv(self.format.size))
        if rev[0] == 34:
            self.sensorEdit.setText(str(rev[1]))
        print(rev)

    def clickLED21(self):
        self.send(21, self.led21.isChecked())

    def clickLED22(self):
        self.send(22, self.led22.isChecked())

    def clickLED23(self):
        self.send(23, self.led23.isChecked())

    def clickMove(self):
        self.send(5, int(self.degreeEdit.text()))

    def updateSensor(self):
        self.send(34, 0)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    myWindows = WindowClass()
    myWindows.show()
    sys.exit(app.exec())

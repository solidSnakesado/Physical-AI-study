from PyQt6.QtCore import *
import time

class MyTimer(QThread):
    timeout = pyqtSignal()                                          # timeout signal 선언

    def __init__(self):
        super().__init__()
        self.interval = 0.1

    def setInterval(self, sec):                                     # timeout 주기
        self.interval = sec

    def start(self, priority = QThread.Priority.InheritPriority):   # start 함수를 호출하면 동작 시작
        super().start(priority)                                     # start 함수를 오버라이드 할때는 조심.!
        self.running = True

    def run(self):
        while self.running == True:                                 # True 인 동안 동작
            self.timeout.emit()                                     # timeout 시그널 발생
            time.sleep(self.interval)                               # timeout 주기만큼 sleep

    def stop(self):
        self.running = False                                        # stop 함수를 호출 하면, 동작 정지
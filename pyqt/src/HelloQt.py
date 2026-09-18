import sys
from PyQt6.QtWidgets import *
from PyQt6.QtGui import *
from PyQt6 import uic

# ui 파일 연결 - 코드 파일과 같은 폴더내에 위치하면 경로 생략 가능
from_class = uic.loadUiType("HelloQt.ui")[0]

# 화면 클래스
class WindoeClass(QMainWindow, from_class) :
    def __init__(self):
        super().__init__()
        self.setupUi(self)                      # ui 파일에서 로딩된 위젯정보로 객체 생성

        self.setWindowTitle("Hello, PyQt!")     # 윈도우 타이틀 출력

if __name__ == "__main__":
    app = QApplication(sys.argv)    # 프로그램 실행
    myWindows = WindoeClass()       # 화면 클래스 생성
    myWindows.show()                # 프로그램 화면 디스플레이
    sys.exit(app.exec())            # 프로그램 종료까지 동작시킴
import sys
from PyQt6.QtWidgets import *
from PyQt6.QtGui import *
from PyQt6 import uic

from_class = uic.loadUiType("Test5.ui")[0]

class WindowClass(QMainWindow, from_class):
    # Test5.ui 내부 위젯들의 타입 명시 (VS Code 자동완성용)
    textEdit: QTextEdit
    nameButton: QPushButton
    seasonButton: QPushButton
    colorButton: QPushButton
    fontButton: QPushButton
    fileButton: QPushButton
    lineEdit: QLineEdit

    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.setWindowTitle("Test 5")

        self.textEdit.setReadOnly(True)                                     # 속성창에서 readOnly 체크와 동일
        self.nameButton.clicked.connect(self.inputName)
        self.seasonButton.clicked.connect(self.inputSeason)
        self.colorButton.clicked.connect(self.inputColor)
        self.fontButton.clicked.connect(self.inputFont)
        self.fileButton.clicked.connect(self.openFile)
        self.lineEdit.returnPressed.connect(self.inputNumber)

    def inputNumber(self):
        text = self.lineEdit.text()

        if text.isdigit():                                                  # 입력값이 숫자이면
            self.textEdit.append(text)                                      # 출력
        else:
            QMessageBox.warning(self, "QMessageBox - setText",              # 타이틀
                                "Please enter only numbers.")               # 경고메세지

        self.lineEdit.clear()

    def openFile(self):
        name = QFileDialog.getOpenFileName(self, "Open File",               # 타이틀
                                           "./")                            # 폴더가 열리는 위치("./" 는 현재 경로)
        if name[0]:                                                         # 파일을 선택 했다면
            with open(name[0], 'r') as file:                                # 선택한 파일을 읽기모그('r') 로 열고
                data = file.read()                                          # 파일의 내용을 읽어서 data에 저장
                self.textEdit.append(data)                                  # 출력
                
    def inputColor(self):
        color = QColorDialog.getColor()

        if color.isValid():
            self.textEdit.append("Color")
            self.textEdit.selectAll()
            self.textEdit.setTextColor(color)
            self.textEdit.moveCursor(QTextCursor.MoveOperation.End)

    def inputFont(self):
        font, ok = QFontDialog.getFont()

        if ok and font:
            info = QFontInfo(font)                                              # 폰트 정보를 가져와서
            self.textEdit.append(info.family() + info.styleName())          # 폰트 이름을 출력
            self.textEdit.selectAll()
            self.textEdit.setFont(font)                                     # 폰트 적용
            self.textEdit.moveCursor(QTextCursor.MoveOperation.End)         # 폰트 적용

    def inputName(self):
        text, ok = QInputDialog.getText(self, "QInputDialog - Name",        # 타이틀
                                        "User name")                        # 입력값 설명
        if ok and text:                                                     # 만약 OK 버튼을 눌렀고, text 가 입력되었다면 
            self.textEdit.append(text)

    def inputSeason(self):
        items = ["Spring", "Summer", "Fall", "Winter"]                      # 선택할 아이템
        item, ok = QInputDialog.getItem(self, "QInputDialog - Season",      # 타이틀
                                        "Season: ",                         # 선택할 아이템 설명
                                        items,                              # 선택할 아이템
                                        0,                                  # 최초 선택괸 아이템 인덱스
                                        False)                              # 편집가능 여부
        if ok and item:
            self.textEdit.append(item)

if __name__ == "__main__":
    app = QApplication(sys.argv)
    myWindow = WindowClass()
    myWindow.show()
    sys.exit(app.exec())
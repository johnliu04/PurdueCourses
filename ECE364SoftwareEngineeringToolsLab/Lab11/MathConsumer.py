# Import PyQt5 classes
import sys
from PyQt5 import QtCore, QtGui
from PyQt5.QtWidgets import QMainWindow, QApplication

from calculator import *

class MathConsumer(QMainWindow, Ui_MainWindow):
    def __init__(self, parent=None):
        super(MathConsumer, self).__init__(parent)
        self.setupUi(self)
        self.btnCalculate.clicked.connect(self.performOperation)

    def performOperation(self):
        num1 = self.edtNumber1.text()
        num2 = self.edtNumber2.text()
        if (num1 == '' or num2 == ''):
            self.edtResult.setText('E')
        try:
            num1 = float(num1)
            if (num1 == int(num1)):
                num1 = int(num1)
        except:
            self.edtResult.setText('E')
        try:
            num2 = float(num2)
            if (num2 == int(num2)):
                num2 = int(num2)
        except:
            self.edtResult.setText('E')

        if (not isinstance(num1, str) and not isinstance(num2, str)):
            if (self.cboOperation.currentText() == '+'):
                result = num1 + num2
                self.edtResult.setText(str(result))
            elif (self.cboOperation.currentText() == '-'):
                result = num1 - num2
                self.edtResult.setText(str(result))
            elif (self.cboOperation.currentText() == '*'):
                result = num1 * num2
                self.edtResult.setText(str(result))
            elif (self.cboOperation.currentText() == '/'):
                result = num1 / num2
                self.edtResult.setText(str(result))



if __name__ == "__main__":
     currentApp = QApplication(sys.argv)
     currentForm = MathConsumer()

     currentForm.show()
     sys.exit(currentApp.exec_())



#######################################################
#   Author:     <Your Full Name>
#   email:      <Your Email>
#   ID:         <Your course ID, e.g. ee364j20>
#   Date:       <Start Date>
#######################################################
import os
import sys
from PyQt5.QtWidgets import QMainWindow, QApplication, QFileDialog
from BasicUI import *
from xml.etree import ElementTree as ET
import xml.dom.minidom as xmd
import collections
from io import StringIO
DataPath = os.path.expanduser('~ee364/DataFolder/Prelab11')

class Consumer(QMainWindow, Ui_MainWindow):

    def __init__(self, parent=None):

        super(Consumer, self).__init__(parent)
        self.setupUi(self)
        self.btnClear.clicked.connect(self.clear)
        self.btnSave.clicked.connect(self.save)
        self.btnLoad.clicked.connect(self.loadData)
        self.alllist = []
        self.alllist.append(self.txtComponentName_1)
        self.alllist.append(self.txtComponentName_2)
        self.alllist.append(self.txtComponentName_3)
        self.alllist.append(self.txtComponentName_4)
        self.alllist.append(self.txtComponentName_5)
        self.alllist.append(self.txtComponentName_6)
        self.alllist.append(self.txtComponentName_7)
        self.alllist.append(self.txtComponentName_8)
        self.alllist.append(self.txtComponentName_9)
        self.alllist.append(self.txtComponentName_10)
        self.alllist.append(self.txtComponentName_11)
        self.alllist.append(self.txtComponentName_12)
        self.alllist.append(self.txtComponentName_13)
        self.alllist.append(self.txtComponentName_14)
        self.alllist.append(self.txtComponentName_15)
        self.alllist.append(self.txtComponentName_16)
        self.alllist.append(self.txtComponentName_17)
        self.alllist.append(self.txtComponentName_18)
        self.alllist.append(self.txtComponentName_19)
        self.alllist.append(self.txtComponentName_20)
        self.alllist.append(self.txtComponentCount_1)
        self.alllist.append(self.txtComponentCount_2)
        self.alllist.append(self.txtComponentCount_3)
        self.alllist.append(self.txtComponentCount_4)
        self.alllist.append(self.txtComponentCount_5)
        self.alllist.append(self.txtComponentCount_6)
        self.alllist.append(self.txtComponentCount_7)
        self.alllist.append(self.txtComponentCount_8)
        self.alllist.append(self.txtComponentCount_9)
        self.alllist.append(self.txtComponentCount_10)
        self.alllist.append(self.txtComponentCount_11)
        self.alllist.append(self.txtComponentCount_12)
        self.alllist.append(self.txtComponentCount_13)
        self.alllist.append(self.txtComponentCount_14)
        self.alllist.append(self.txtComponentCount_15)
        self.alllist.append(self.txtComponentCount_16)
        self.alllist.append(self.txtComponentCount_17)
        self.alllist.append(self.txtComponentCount_18)
        self.alllist.append(self.txtComponentCount_19)
        self.alllist.append(self.txtComponentCount_20)

        for i in self.alllist:
            i.textChanged.connect(self.ch)

    def ch(self):
        self.btnSave.setEnabled(True)
        self.btnLoad.setEnabled(False)

    def clear(self):

        self.txtStudentName.setText('')
        self.txtStudentID.setText('')
        self.chkGraduate.setChecked(0)
        self.cboCollege.setCurrentIndex(0)
        for i in self.alllist:
            i.setText('')
        self.btnSave.setEnabled(False)
        self.btnLoad.setEnabled(True)


    def save(self):

        if self.chkGraduate.isChecked():
            grade='true'
        else:
            grade='false'
        file=xmd.Document()
        file.createElement('StudentName')
        content=file.createElement('Content')
        file.appendChild(content)
        Sname=file.createElement('StudentName')
        Sname.setAttribute('graduate',grade)
        Sname.appendChild(file.createTextNode(self.txtStudentName.text()))
        content.appendChild(Sname)
        Sid = file.createElement('StudentID')
        Sid.appendChild(file.createTextNode(self.txtStudentID.text()))
        content.appendChild(Sid)
        Coll = file.createElement('College')
        Coll.appendChild(file.createTextNode(self.cboCollege.currentText()))
        content.appendChild(Coll)

        com=file.createElement('Components')
        content.appendChild(com)

       # compdic=file.getElementsByTagName('Content')[0].getElementsByTagName('Components')[0].getElementsByTagName('Component')
       # compdic = collections.OrderedDict()

        for i in range(0,20):
            aa = file.createElement('Component')
            aa.setAttribute('count', self.alllist[i + 20].text())
            aa.setAttribute('Aaaaaaaaaaname', self.alllist[i].text())
            #print(self.alllist[i].text())

            #print(i)
            if self.alllist[i].text()!='' or self.alllist[i+20].text()!='':
                com.appendChild(aa)

        #compdic = collections.OrderedDict()

        fp=StringIO("123123.xml")
        file.writexml(fp,newl='\n',addindent='    ',encoding='UTF-8')
        fp.seek(0)
        f1 = open("target.xml",'w')
        for line in fp:
            line_new = line.replace('Aaaaaaaaaaname', 'name')
            f1.write(line_new)
        f1.close()





    def loadData(self):
        """
        *** DO NOT MODIFY THIS METHOD! ***
        Obtain a file name from a file dialog, and pass it on to the loading method. This is to facilitate automated
        testing. Invoke this method when clicking on the 'load' button.

        You must modify the method below.
        """
        filePath, _ = QFileDialog.getOpenFileName(self, caption='Open XML file ...', filter="XML files (*.xml)")

        if not filePath:
            return

        self.loadDataFromFile(filePath)

    def loadDataFromFile(self, filePath):
        """
        Handles the loading of the data from the given file name. This method will be invoked by the 'loadData' method.
        
        *** YOU MUST USE THIS METHOD TO LOAD DATA FILES. ***
        *** This method is required for unit tests! ***
        """
        dom=xmd.parse(filePath)
        root = dom.documentElement
        bb= root.getElementsByTagName('StudentName')

        #name = dom.getElementsByTagName('Content')[0].getElementsByTagName('StudentName')[0].childNodes[0]._data
        name = bb[0].firstChild.data
        #name = bb.childNodes[0]._data
        grad=bb[0].getAttribute("graduate")
        if grad=='true':
            gra=True
        else:
            gra=False
        b1 = root.getElementsByTagName('StudentID')
        sid = b1[0].firstChild.data
        b5 = root.getElementsByTagName('College')
        coll = b5[0].firstChild.data

        #print(coll)
        b2 = root.getElementsByTagName('Component')
        cname=[]
        ccount=[]
        for i in b2:
            cname.append(i.getAttribute("name"))

        for i in b2:
            ccount.append(i.getAttribute("count"))

        for i in range(0,len(cname)):
            #print(i)
            self.alllist[i].setText(cname[i])
            self.alllist[i+20].setText(ccount[i])

        self.txtStudentName.setText(name)
        self.txtStudentID.setText(sid)
        self.chkGraduate.setChecked(gra)
        self.cboCollege.setCurrentText(coll)










        pass



if __name__ == "__main__":
    currentApp = QApplication(sys.argv)
    currentForm = Consumer()

    currentForm.show()
    currentApp.exec_()

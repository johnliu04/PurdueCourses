
#######################################################
#   Author:     <Your Full Name>
#   email:      <Your Email>
#   ID:         <Your course ID, e.g. ee364j20>
#   Date:       <Start Date>
#######################################################

import sys
from PyQt5.QtWidgets import QMainWindow, QApplication, QFileDialog
from BasicUI import *
import xml.etree.ElementTree as ET
from xml.dom import minidom

class Consumer(QMainWindow, Ui_MainWindow):

    def __init__(self, parent=None):
        super(Consumer, self).__init__(parent)
        self.setupUi(self)

        self.btnSave.setDisabled(True)
        self.componentlistname = []
        self.componentlistname.append(self.txtComponentName_1)
        self.componentlistname.append(self.txtComponentName_2)
        self.componentlistname.append(self.txtComponentName_3)
        self.componentlistname.append(self.txtComponentName_4)
        self.componentlistname.append(self.txtComponentName_5)
        self.componentlistname.append(self.txtComponentName_6)
        self.componentlistname.append(self.txtComponentName_7)
        self.componentlistname.append(self.txtComponentName_8)
        self.componentlistname.append(self.txtComponentName_9)
        self.componentlistname.append(self.txtComponentName_10)
        self.componentlistname.append(self.txtComponentName_11)
        self.componentlistname.append(self.txtComponentName_12)
        self.componentlistname.append(self.txtComponentName_13)
        self.componentlistname.append(self.txtComponentName_14)
        self.componentlistname.append(self.txtComponentName_15)
        self.componentlistname.append(self.txtComponentName_16)
        self.componentlistname.append(self.txtComponentName_17)
        self.componentlistname.append(self.txtComponentName_18)
        self.componentlistname.append(self.txtComponentName_19)
        self.componentlistname.append(self.txtComponentName_20)
        self.componentlistcount = []
        self.componentlistcount.append(self.txtComponentCount_1)
        self.componentlistcount.append(self.txtComponentCount_2)
        self.componentlistcount.append(self.txtComponentCount_3)
        self.componentlistcount.append(self.txtComponentCount_4)
        self.componentlistcount.append(self.txtComponentCount_5)
        self.componentlistcount.append(self.txtComponentCount_6)
        self.componentlistcount.append(self.txtComponentCount_7)
        self.componentlistcount.append(self.txtComponentCount_8)
        self.componentlistcount.append(self.txtComponentCount_9)
        self.componentlistcount.append(self.txtComponentCount_10)
        self.componentlistcount.append(self.txtComponentCount_11)
        self.componentlistcount.append(self.txtComponentCount_12)
        self.componentlistcount.append(self.txtComponentCount_13)
        self.componentlistcount.append(self.txtComponentCount_14)
        self.componentlistcount.append(self.txtComponentCount_15)
        self.componentlistcount.append(self.txtComponentCount_16)
        self.componentlistcount.append(self.txtComponentCount_17)
        self.componentlistcount.append(self.txtComponentCount_18)
        self.componentlistcount.append(self.txtComponentCount_19)
        self.componentlistcount.append(self.txtComponentCount_20)
        self.namelist = []
        self.namelist.append(self.txtStudentName)
        self.namelist.append(self.txtStudentID)
        self.namelist.append(self.chkGraduate)
        self.namelist.append(self.cboCollege)

        for i in self.componentlistname:
            i.textChanged.connect(self.modifysaveandload)

        for i in self.componentlistcount:
            i.textChanged.connect(self.modifysaveandload)

        for i in self.namelist:
            try:
                i.textChanged.connect(self.modifysaveandload)
            except:
                try:
                    i.stateChanged.connect(self.modifysaveandload)
                except:
                    i.currentTextChanged.connect(self.modifysaveandload)

        self.btnClear.clicked.connect(self.clear)
        self.btnSave.clicked.connect(self.save)
        self.btnLoad.clicked.connect(self.loadData)

    def modifysaveandload(self):
        self.btnSave.setDisabled(False)
        self.btnLoad.setDisabled(True)

    def clear(self):
        self.txtStudentName.setText('')
        self.txtStudentID.setText('')
        self.chkGraduate.setChecked(0)
        self.cboCollege.setCurrentIndex(0)
        for i in self.componentlistname:
            i.setText('')
        for i in self.componentlistcount:
            i.setText('')
        self.btnSave.setDisabled(True)
        self.btnLoad.setDisabled(False)

    def save(self):
        content = ET.Element('Content')
        studentname = ET.SubElement(content, 'StudentName')
        studentid = ET.SubElement(content, 'StudentID')
        college = ET.SubElement(content, 'College')
        components = ET.SubElement(content, 'Components')
        if self.chkGraduate.isChecked(): graduate = 'true'
        else: graduate = 'false'
        studentname.set('graduate', graduate)
        studentname.text = self.txtStudentName.text()
        studentid.text = self.txtStudentID.text()
        college.text = self.cboCollege.currentText()

        for index, comp in enumerate(self.componentlistname):
            if comp.text() == '' and self.componentlistcount[index].text() == '':
                continue
            component = ET.SubElement(components, 'Component')
            component.set('count', self.componentlistcount[index].text()) #count actually
            component.set('arandamjustincasename', comp.text()) #name actually

        newstring = ET.tostring(content, 'utf8')  # print the element in string
        parsestring = minidom.parseString(newstring)  # parse it using minidom
        infor = parsestring.toprettyxml(indent="\t")  # convert it again in XML using the toprettyxml function.

        infor = infor.split('?>')
        infor = infor[0] + 'encoding="UTF-8"?>' + infor[1]
        infor = infor.replace('arandamjustincasename', 'name')
        infor = infor.replace('/>', ' />')
        infor = infor.replace('</Content>\n','</Content>')
        file = open('target.xml','w')
        file.write(infor)

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
        infor = ET.parse(filePath).getroot()
        studentname = infor.find('StudentName').text
        graduate = infor.find('StudentName').get('graduate')
        if graduate == 'true':
            graduate = True
        elif graduate == 'false':
            graduate = False
        studentID = infor.find('StudentID').text
        college = infor.find('College').text

        i = 0
        for component in infor.find('Components').findall('Component'):
            name = component.get('name')
            count = component.get('count')
            if i >= 20:
                break
            self.componentlistname[i].setText(name)
            self.componentlistcount[i].setText(count)
            i += 1
        
        self.txtStudentName.setText(studentname)
        self.txtStudentID.setText(studentID)
        self.chkGraduate.setChecked(graduate)
        self.cboCollege.setCurrentText(college)
        
        self.btnSave.setDisabled(False)
        self.btnLoad.setDisabled(True)
        pass



if __name__ == "__main__":
    currentApp = QApplication(sys.argv)
    currentForm = Consumer()

    currentForm.show()
    currentApp.exec_()

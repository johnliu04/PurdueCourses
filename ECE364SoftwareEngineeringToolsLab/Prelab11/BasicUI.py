# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'BasicUI.ui'
#
# Created by: PyQt5 UI code generator 5.9.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1092, 836)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.lblStudentName = QtWidgets.QLabel(self.centralwidget)
        self.lblStudentName.setGeometry(QtCore.QRect(290, 40, 113, 31))
        self.lblStudentName.setScaledContents(False)
        self.lblStudentName.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblStudentName.setObjectName("lblStudentName")
        self.lblGraduate = QtWidgets.QLabel(self.centralwidget)
        self.lblGraduate.setGeometry(QtCore.QRect(280, 120, 121, 33))
        self.lblGraduate.setScaledContents(False)
        self.lblGraduate.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblGraduate.setObjectName("lblGraduate")
        self.lblStudentID = QtWidgets.QLabel(self.centralwidget)
        self.lblStudentID.setGeometry(QtCore.QRect(290, 80, 113, 33))
        self.lblStudentID.setScaledContents(False)
        self.lblStudentID.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblStudentID.setObjectName("lblStudentID")
        self.lblCollege = QtWidgets.QLabel(self.centralwidget)
        self.lblCollege.setGeometry(QtCore.QRect(280, 160, 121, 33))
        self.lblCollege.setScaledContents(False)
        self.lblCollege.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblCollege.setObjectName("lblCollege")
        self.frmDemographics = QtWidgets.QFrame(self.centralwidget)
        self.frmDemographics.setGeometry(QtCore.QRect(280, 20, 461, 181))
        self.frmDemographics.setFrameShape(QtWidgets.QFrame.WinPanel)
        self.frmDemographics.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.frmDemographics.setObjectName("frmDemographics")
        self.txtStudentName = QtWidgets.QLineEdit(self.centralwidget)
        self.txtStudentName.setGeometry(QtCore.QRect(420, 40, 301, 27))
        self.txtStudentName.setObjectName("txtStudentName")
        self.txtStudentID = QtWidgets.QLineEdit(self.centralwidget)
        self.txtStudentID.setGeometry(QtCore.QRect(420, 80, 301, 27))
        self.txtStudentID.setObjectName("txtStudentID")
        self.chkGraduate = QtWidgets.QCheckBox(self.centralwidget)
        self.chkGraduate.setGeometry(QtCore.QRect(420, 121, 93, 31))
        self.chkGraduate.setText("")
        self.chkGraduate.setObjectName("chkGraduate")
        self.cboCollege = QtWidgets.QComboBox(self.centralwidget)
        self.cboCollege.setGeometry(QtCore.QRect(420, 160, 301, 27))
        self.cboCollege.setObjectName("cboCollege")
        self.cboCollege.addItem("")
        self.cboCollege.addItem("")
        self.cboCollege.addItem("")
        self.cboCollege.addItem("")
        self.cboCollege.addItem("")
        self.cboCollege.addItem("")
        self.cboCollege.addItem("")
        self.lblComponentName = QtWidgets.QLabel(self.centralwidget)
        self.lblComponentName.setGeometry(QtCore.QRect(150, 250, 131, 31))
        self.lblComponentName.setScaledContents(False)
        self.lblComponentName.setAlignment(QtCore.Qt.AlignLeading|QtCore.Qt.AlignLeft|QtCore.Qt.AlignVCenter)
        self.lblComponentName.setObjectName("lblComponentName")
        self.lblCount = QtWidgets.QLabel(self.centralwidget)
        self.lblCount.setGeometry(QtCore.QRect(390, 250, 131, 31))
        self.lblCount.setScaledContents(False)
        self.lblCount.setAlignment(QtCore.Qt.AlignCenter)
        self.lblCount.setObjectName("lblCount")
        self.lblCount_2 = QtWidgets.QLabel(self.centralwidget)
        self.lblCount_2.setGeometry(QtCore.QRect(910, 250, 131, 31))
        self.lblCount_2.setScaledContents(False)
        self.lblCount_2.setAlignment(QtCore.Qt.AlignCenter)
        self.lblCount_2.setObjectName("lblCount_2")
        self.lblComponentName_2 = QtWidgets.QLabel(self.centralwidget)
        self.lblComponentName_2.setGeometry(QtCore.QRect(670, 250, 131, 31))
        self.lblComponentName_2.setScaledContents(False)
        self.lblComponentName_2.setAlignment(QtCore.Qt.AlignLeading|QtCore.Qt.AlignLeft|QtCore.Qt.AlignVCenter)
        self.lblComponentName_2.setObjectName("lblComponentName_2")
        self.layoutWidget = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget.setGeometry(QtCore.QRect(530, 280, 41, 411))
        self.layoutWidget.setObjectName("layoutWidget")
        self.verticalLayout_6 = QtWidgets.QVBoxLayout(self.layoutWidget)
        self.verticalLayout_6.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_6.setObjectName("verticalLayout_6")
        self.lblIndex_11 = QtWidgets.QLabel(self.layoutWidget)
        self.lblIndex_11.setScaledContents(False)
        self.lblIndex_11.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblIndex_11.setObjectName("lblIndex_11")
        self.verticalLayout_6.addWidget(self.lblIndex_11)
        self.lblIndex_12 = QtWidgets.QLabel(self.layoutWidget)
        self.lblIndex_12.setScaledContents(False)
        self.lblIndex_12.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblIndex_12.setObjectName("lblIndex_12")
        self.verticalLayout_6.addWidget(self.lblIndex_12)
        self.lblIndex_13 = QtWidgets.QLabel(self.layoutWidget)
        self.lblIndex_13.setScaledContents(False)
        self.lblIndex_13.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblIndex_13.setObjectName("lblIndex_13")
        self.verticalLayout_6.addWidget(self.lblIndex_13)
        self.lblIndex_14 = QtWidgets.QLabel(self.layoutWidget)
        self.lblIndex_14.setScaledContents(False)
        self.lblIndex_14.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblIndex_14.setObjectName("lblIndex_14")
        self.verticalLayout_6.addWidget(self.lblIndex_14)
        self.lblIndex_15 = QtWidgets.QLabel(self.layoutWidget)
        self.lblIndex_15.setScaledContents(False)
        self.lblIndex_15.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblIndex_15.setObjectName("lblIndex_15")
        self.verticalLayout_6.addWidget(self.lblIndex_15)
        self.lblIndex_16 = QtWidgets.QLabel(self.layoutWidget)
        self.lblIndex_16.setScaledContents(False)
        self.lblIndex_16.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblIndex_16.setObjectName("lblIndex_16")
        self.verticalLayout_6.addWidget(self.lblIndex_16)
        self.lblIndex_17 = QtWidgets.QLabel(self.layoutWidget)
        self.lblIndex_17.setScaledContents(False)
        self.lblIndex_17.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblIndex_17.setObjectName("lblIndex_17")
        self.verticalLayout_6.addWidget(self.lblIndex_17)
        self.lblIndex_18 = QtWidgets.QLabel(self.layoutWidget)
        self.lblIndex_18.setScaledContents(False)
        self.lblIndex_18.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblIndex_18.setObjectName("lblIndex_18")
        self.verticalLayout_6.addWidget(self.lblIndex_18)
        self.lblIndex_19 = QtWidgets.QLabel(self.layoutWidget)
        self.lblIndex_19.setScaledContents(False)
        self.lblIndex_19.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblIndex_19.setObjectName("lblIndex_19")
        self.verticalLayout_6.addWidget(self.lblIndex_19)
        self.lblIndex_20 = QtWidgets.QLabel(self.layoutWidget)
        self.lblIndex_20.setScaledContents(False)
        self.lblIndex_20.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblIndex_20.setObjectName("lblIndex_20")
        self.verticalLayout_6.addWidget(self.lblIndex_20)
        self.layoutWidget1 = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget1.setGeometry(QtCore.QRect(3, 280, 41, 411))
        self.layoutWidget1.setObjectName("layoutWidget1")
        self.verticalLayout_5 = QtWidgets.QVBoxLayout(self.layoutWidget1)
        self.verticalLayout_5.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_5.setObjectName("verticalLayout_5")
        self.lblIndex = QtWidgets.QLabel(self.layoutWidget1)
        self.lblIndex.setScaledContents(False)
        self.lblIndex.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblIndex.setObjectName("lblIndex")
        self.verticalLayout_5.addWidget(self.lblIndex)
        self.lblIndex_2 = QtWidgets.QLabel(self.layoutWidget1)
        self.lblIndex_2.setScaledContents(False)
        self.lblIndex_2.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblIndex_2.setObjectName("lblIndex_2")
        self.verticalLayout_5.addWidget(self.lblIndex_2)
        self.lblIndex_3 = QtWidgets.QLabel(self.layoutWidget1)
        self.lblIndex_3.setScaledContents(False)
        self.lblIndex_3.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblIndex_3.setObjectName("lblIndex_3")
        self.verticalLayout_5.addWidget(self.lblIndex_3)
        self.lblIndex_4 = QtWidgets.QLabel(self.layoutWidget1)
        self.lblIndex_4.setScaledContents(False)
        self.lblIndex_4.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblIndex_4.setObjectName("lblIndex_4")
        self.verticalLayout_5.addWidget(self.lblIndex_4)
        self.lblIndex_5 = QtWidgets.QLabel(self.layoutWidget1)
        self.lblIndex_5.setScaledContents(False)
        self.lblIndex_5.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblIndex_5.setObjectName("lblIndex_5")
        self.verticalLayout_5.addWidget(self.lblIndex_5)
        self.lblIndex_6 = QtWidgets.QLabel(self.layoutWidget1)
        self.lblIndex_6.setScaledContents(False)
        self.lblIndex_6.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblIndex_6.setObjectName("lblIndex_6")
        self.verticalLayout_5.addWidget(self.lblIndex_6)
        self.lblIndex_7 = QtWidgets.QLabel(self.layoutWidget1)
        self.lblIndex_7.setScaledContents(False)
        self.lblIndex_7.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblIndex_7.setObjectName("lblIndex_7")
        self.verticalLayout_5.addWidget(self.lblIndex_7)
        self.lblIndex_8 = QtWidgets.QLabel(self.layoutWidget1)
        self.lblIndex_8.setScaledContents(False)
        self.lblIndex_8.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblIndex_8.setObjectName("lblIndex_8")
        self.verticalLayout_5.addWidget(self.lblIndex_8)
        self.lblIndex_9 = QtWidgets.QLabel(self.layoutWidget1)
        self.lblIndex_9.setScaledContents(False)
        self.lblIndex_9.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblIndex_9.setObjectName("lblIndex_9")
        self.verticalLayout_5.addWidget(self.lblIndex_9)
        self.lblIndex_10 = QtWidgets.QLabel(self.layoutWidget1)
        self.lblIndex_10.setScaledContents(False)
        self.lblIndex_10.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.lblIndex_10.setObjectName("lblIndex_10")
        self.verticalLayout_5.addWidget(self.lblIndex_10)
        self.layoutWidget2 = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget2.setGeometry(QtCore.QRect(910, 280, 148, 421))
        self.layoutWidget2.setObjectName("layoutWidget2")
        self.verticalLayout_4 = QtWidgets.QVBoxLayout(self.layoutWidget2)
        self.verticalLayout_4.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_4.setObjectName("verticalLayout_4")
        self.txtComponentCount_11 = QtWidgets.QLineEdit(self.layoutWidget2)
        self.txtComponentCount_11.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.txtComponentCount_11.setObjectName("txtComponentCount_11")
        self.verticalLayout_4.addWidget(self.txtComponentCount_11)
        self.txtComponentCount_12 = QtWidgets.QLineEdit(self.layoutWidget2)
        self.txtComponentCount_12.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.txtComponentCount_12.setObjectName("txtComponentCount_12")
        self.verticalLayout_4.addWidget(self.txtComponentCount_12)
        self.txtComponentCount_13 = QtWidgets.QLineEdit(self.layoutWidget2)
        self.txtComponentCount_13.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.txtComponentCount_13.setObjectName("txtComponentCount_13")
        self.verticalLayout_4.addWidget(self.txtComponentCount_13)
        self.txtComponentCount_14 = QtWidgets.QLineEdit(self.layoutWidget2)
        self.txtComponentCount_14.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.txtComponentCount_14.setObjectName("txtComponentCount_14")
        self.verticalLayout_4.addWidget(self.txtComponentCount_14)
        self.txtComponentCount_15 = QtWidgets.QLineEdit(self.layoutWidget2)
        self.txtComponentCount_15.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.txtComponentCount_15.setObjectName("txtComponentCount_15")
        self.verticalLayout_4.addWidget(self.txtComponentCount_15)
        self.txtComponentCount_16 = QtWidgets.QLineEdit(self.layoutWidget2)
        self.txtComponentCount_16.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.txtComponentCount_16.setObjectName("txtComponentCount_16")
        self.verticalLayout_4.addWidget(self.txtComponentCount_16)
        self.txtComponentCount_17 = QtWidgets.QLineEdit(self.layoutWidget2)
        self.txtComponentCount_17.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.txtComponentCount_17.setObjectName("txtComponentCount_17")
        self.verticalLayout_4.addWidget(self.txtComponentCount_17)
        self.txtComponentCount_18 = QtWidgets.QLineEdit(self.layoutWidget2)
        self.txtComponentCount_18.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.txtComponentCount_18.setObjectName("txtComponentCount_18")
        self.verticalLayout_4.addWidget(self.txtComponentCount_18)
        self.txtComponentCount_19 = QtWidgets.QLineEdit(self.layoutWidget2)
        self.txtComponentCount_19.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.txtComponentCount_19.setObjectName("txtComponentCount_19")
        self.verticalLayout_4.addWidget(self.txtComponentCount_19)
        self.txtComponentCount_20 = QtWidgets.QLineEdit(self.layoutWidget2)
        self.txtComponentCount_20.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.txtComponentCount_20.setObjectName("txtComponentCount_20")
        self.verticalLayout_4.addWidget(self.txtComponentCount_20)
        self.layoutWidget3 = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget3.setGeometry(QtCore.QRect(580, 280, 321, 421))
        self.layoutWidget3.setObjectName("layoutWidget3")
        self.verticalLayout_3 = QtWidgets.QVBoxLayout(self.layoutWidget3)
        self.verticalLayout_3.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.txtComponentName_11 = QtWidgets.QLineEdit(self.layoutWidget3)
        self.txtComponentName_11.setAlignment(QtCore.Qt.AlignCenter)
        self.txtComponentName_11.setObjectName("txtComponentName_11")
        self.verticalLayout_3.addWidget(self.txtComponentName_11)
        self.txtComponentName_12 = QtWidgets.QLineEdit(self.layoutWidget3)
        self.txtComponentName_12.setAlignment(QtCore.Qt.AlignCenter)
        self.txtComponentName_12.setObjectName("txtComponentName_12")
        self.verticalLayout_3.addWidget(self.txtComponentName_12)
        self.txtComponentName_13 = QtWidgets.QLineEdit(self.layoutWidget3)
        self.txtComponentName_13.setAlignment(QtCore.Qt.AlignCenter)
        self.txtComponentName_13.setObjectName("txtComponentName_13")
        self.verticalLayout_3.addWidget(self.txtComponentName_13)
        self.txtComponentName_14 = QtWidgets.QLineEdit(self.layoutWidget3)
        self.txtComponentName_14.setAlignment(QtCore.Qt.AlignCenter)
        self.txtComponentName_14.setObjectName("txtComponentName_14")
        self.verticalLayout_3.addWidget(self.txtComponentName_14)
        self.txtComponentName_15 = QtWidgets.QLineEdit(self.layoutWidget3)
        self.txtComponentName_15.setAlignment(QtCore.Qt.AlignCenter)
        self.txtComponentName_15.setObjectName("txtComponentName_15")
        self.verticalLayout_3.addWidget(self.txtComponentName_15)
        self.txtComponentName_16 = QtWidgets.QLineEdit(self.layoutWidget3)
        self.txtComponentName_16.setAlignment(QtCore.Qt.AlignCenter)
        self.txtComponentName_16.setObjectName("txtComponentName_16")
        self.verticalLayout_3.addWidget(self.txtComponentName_16)
        self.txtComponentName_17 = QtWidgets.QLineEdit(self.layoutWidget3)
        self.txtComponentName_17.setAlignment(QtCore.Qt.AlignCenter)
        self.txtComponentName_17.setObjectName("txtComponentName_17")
        self.verticalLayout_3.addWidget(self.txtComponentName_17)
        self.txtComponentName_18 = QtWidgets.QLineEdit(self.layoutWidget3)
        self.txtComponentName_18.setAlignment(QtCore.Qt.AlignCenter)
        self.txtComponentName_18.setObjectName("txtComponentName_18")
        self.verticalLayout_3.addWidget(self.txtComponentName_18)
        self.txtComponentName_19 = QtWidgets.QLineEdit(self.layoutWidget3)
        self.txtComponentName_19.setAlignment(QtCore.Qt.AlignCenter)
        self.txtComponentName_19.setObjectName("txtComponentName_19")
        self.verticalLayout_3.addWidget(self.txtComponentName_19)
        self.txtComponentName_20 = QtWidgets.QLineEdit(self.layoutWidget3)
        self.txtComponentName_20.setAlignment(QtCore.Qt.AlignCenter)
        self.txtComponentName_20.setObjectName("txtComponentName_20")
        self.verticalLayout_3.addWidget(self.txtComponentName_20)
        self.layoutWidget4 = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget4.setGeometry(QtCore.QRect(380, 280, 148, 421))
        self.layoutWidget4.setObjectName("layoutWidget4")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout(self.layoutWidget4)
        self.verticalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.txtComponentCount_1 = QtWidgets.QLineEdit(self.layoutWidget4)
        self.txtComponentCount_1.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.txtComponentCount_1.setObjectName("txtComponentCount_1")
        self.verticalLayout_2.addWidget(self.txtComponentCount_1)
        self.txtComponentCount_2 = QtWidgets.QLineEdit(self.layoutWidget4)
        self.txtComponentCount_2.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.txtComponentCount_2.setObjectName("txtComponentCount_2")
        self.verticalLayout_2.addWidget(self.txtComponentCount_2)
        self.txtComponentCount_3 = QtWidgets.QLineEdit(self.layoutWidget4)
        self.txtComponentCount_3.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.txtComponentCount_3.setObjectName("txtComponentCount_3")
        self.verticalLayout_2.addWidget(self.txtComponentCount_3)
        self.txtComponentCount_4 = QtWidgets.QLineEdit(self.layoutWidget4)
        self.txtComponentCount_4.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.txtComponentCount_4.setObjectName("txtComponentCount_4")
        self.verticalLayout_2.addWidget(self.txtComponentCount_4)
        self.txtComponentCount_5 = QtWidgets.QLineEdit(self.layoutWidget4)
        self.txtComponentCount_5.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.txtComponentCount_5.setObjectName("txtComponentCount_5")
        self.verticalLayout_2.addWidget(self.txtComponentCount_5)
        self.txtComponentCount_6 = QtWidgets.QLineEdit(self.layoutWidget4)
        self.txtComponentCount_6.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.txtComponentCount_6.setObjectName("txtComponentCount_6")
        self.verticalLayout_2.addWidget(self.txtComponentCount_6)
        self.txtComponentCount_7 = QtWidgets.QLineEdit(self.layoutWidget4)
        self.txtComponentCount_7.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.txtComponentCount_7.setObjectName("txtComponentCount_7")
        self.verticalLayout_2.addWidget(self.txtComponentCount_7)
        self.txtComponentCount_8 = QtWidgets.QLineEdit(self.layoutWidget4)
        self.txtComponentCount_8.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.txtComponentCount_8.setObjectName("txtComponentCount_8")
        self.verticalLayout_2.addWidget(self.txtComponentCount_8)
        self.txtComponentCount_9 = QtWidgets.QLineEdit(self.layoutWidget4)
        self.txtComponentCount_9.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.txtComponentCount_9.setObjectName("txtComponentCount_9")
        self.verticalLayout_2.addWidget(self.txtComponentCount_9)
        self.txtComponentCount_10 = QtWidgets.QLineEdit(self.layoutWidget4)
        self.txtComponentCount_10.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.txtComponentCount_10.setObjectName("txtComponentCount_10")
        self.verticalLayout_2.addWidget(self.txtComponentCount_10)
        self.layoutWidget5 = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget5.setGeometry(QtCore.QRect(50, 280, 321, 421))
        self.layoutWidget5.setObjectName("layoutWidget5")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.layoutWidget5)
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout.setObjectName("verticalLayout")
        self.txtComponentName_1 = QtWidgets.QLineEdit(self.layoutWidget5)
        self.txtComponentName_1.setAlignment(QtCore.Qt.AlignCenter)
        self.txtComponentName_1.setObjectName("txtComponentName_1")
        self.verticalLayout.addWidget(self.txtComponentName_1)
        self.txtComponentName_2 = QtWidgets.QLineEdit(self.layoutWidget5)
        self.txtComponentName_2.setAlignment(QtCore.Qt.AlignCenter)
        self.txtComponentName_2.setObjectName("txtComponentName_2")
        self.verticalLayout.addWidget(self.txtComponentName_2)
        self.txtComponentName_3 = QtWidgets.QLineEdit(self.layoutWidget5)
        self.txtComponentName_3.setAlignment(QtCore.Qt.AlignCenter)
        self.txtComponentName_3.setObjectName("txtComponentName_3")
        self.verticalLayout.addWidget(self.txtComponentName_3)
        self.txtComponentName_4 = QtWidgets.QLineEdit(self.layoutWidget5)
        self.txtComponentName_4.setAlignment(QtCore.Qt.AlignCenter)
        self.txtComponentName_4.setObjectName("txtComponentName_4")
        self.verticalLayout.addWidget(self.txtComponentName_4)
        self.txtComponentName_5 = QtWidgets.QLineEdit(self.layoutWidget5)
        self.txtComponentName_5.setAlignment(QtCore.Qt.AlignCenter)
        self.txtComponentName_5.setObjectName("txtComponentName_5")
        self.verticalLayout.addWidget(self.txtComponentName_5)
        self.txtComponentName_6 = QtWidgets.QLineEdit(self.layoutWidget5)
        self.txtComponentName_6.setAlignment(QtCore.Qt.AlignCenter)
        self.txtComponentName_6.setObjectName("txtComponentName_6")
        self.verticalLayout.addWidget(self.txtComponentName_6)
        self.txtComponentName_7 = QtWidgets.QLineEdit(self.layoutWidget5)
        self.txtComponentName_7.setAlignment(QtCore.Qt.AlignCenter)
        self.txtComponentName_7.setObjectName("txtComponentName_7")
        self.verticalLayout.addWidget(self.txtComponentName_7)
        self.txtComponentName_8 = QtWidgets.QLineEdit(self.layoutWidget5)
        self.txtComponentName_8.setAlignment(QtCore.Qt.AlignCenter)
        self.txtComponentName_8.setObjectName("txtComponentName_8")
        self.verticalLayout.addWidget(self.txtComponentName_8)
        self.txtComponentName_9 = QtWidgets.QLineEdit(self.layoutWidget5)
        self.txtComponentName_9.setAlignment(QtCore.Qt.AlignCenter)
        self.txtComponentName_9.setObjectName("txtComponentName_9")
        self.verticalLayout.addWidget(self.txtComponentName_9)
        self.txtComponentName_10 = QtWidgets.QLineEdit(self.layoutWidget5)
        self.txtComponentName_10.setAlignment(QtCore.Qt.AlignCenter)
        self.txtComponentName_10.setObjectName("txtComponentName_10")
        self.verticalLayout.addWidget(self.txtComponentName_10)
        self.layoutWidget6 = QtWidgets.QWidget(self.centralwidget)
        self.layoutWidget6.setGeometry(QtCore.QRect(140, 750, 801, 29))
        self.layoutWidget6.setObjectName("layoutWidget6")
        self.gridLayout = QtWidgets.QGridLayout(self.layoutWidget6)
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.gridLayout.setObjectName("gridLayout")
        self.btnClear = QtWidgets.QPushButton(self.layoutWidget6)
        self.btnClear.setObjectName("btnClear")
        self.gridLayout.addWidget(self.btnClear, 0, 0, 1, 1)
        self.btnLoad = QtWidgets.QPushButton(self.layoutWidget6)
        self.btnLoad.setObjectName("btnLoad")
        self.gridLayout.addWidget(self.btnLoad, 0, 1, 1, 1)
        self.btnSave = QtWidgets.QPushButton(self.layoutWidget6)
        self.btnSave.setObjectName("btnSave")
        self.gridLayout.addWidget(self.btnSave, 0, 2, 1, 1)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 1092, 25))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        self.cboCollege.setCurrentIndex(0)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)
        MainWindow.setTabOrder(self.txtStudentName, self.txtStudentID)
        MainWindow.setTabOrder(self.txtStudentID, self.chkGraduate)
        MainWindow.setTabOrder(self.chkGraduate, self.cboCollege)
        MainWindow.setTabOrder(self.cboCollege, self.txtComponentName_1)
        MainWindow.setTabOrder(self.txtComponentName_1, self.txtComponentCount_1)
        MainWindow.setTabOrder(self.txtComponentCount_1, self.txtComponentName_2)
        MainWindow.setTabOrder(self.txtComponentName_2, self.txtComponentCount_2)
        MainWindow.setTabOrder(self.txtComponentCount_2, self.txtComponentName_3)
        MainWindow.setTabOrder(self.txtComponentName_3, self.txtComponentCount_3)
        MainWindow.setTabOrder(self.txtComponentCount_3, self.txtComponentName_4)
        MainWindow.setTabOrder(self.txtComponentName_4, self.txtComponentCount_4)
        MainWindow.setTabOrder(self.txtComponentCount_4, self.txtComponentName_5)
        MainWindow.setTabOrder(self.txtComponentName_5, self.txtComponentCount_5)
        MainWindow.setTabOrder(self.txtComponentCount_5, self.txtComponentName_6)
        MainWindow.setTabOrder(self.txtComponentName_6, self.txtComponentCount_6)
        MainWindow.setTabOrder(self.txtComponentCount_6, self.txtComponentName_7)
        MainWindow.setTabOrder(self.txtComponentName_7, self.txtComponentCount_7)
        MainWindow.setTabOrder(self.txtComponentCount_7, self.txtComponentName_8)
        MainWindow.setTabOrder(self.txtComponentName_8, self.txtComponentCount_8)
        MainWindow.setTabOrder(self.txtComponentCount_8, self.txtComponentName_9)
        MainWindow.setTabOrder(self.txtComponentName_9, self.txtComponentCount_9)
        MainWindow.setTabOrder(self.txtComponentCount_9, self.txtComponentName_10)
        MainWindow.setTabOrder(self.txtComponentName_10, self.txtComponentCount_10)
        MainWindow.setTabOrder(self.txtComponentCount_10, self.txtComponentName_11)
        MainWindow.setTabOrder(self.txtComponentName_11, self.txtComponentCount_11)
        MainWindow.setTabOrder(self.txtComponentCount_11, self.txtComponentName_12)
        MainWindow.setTabOrder(self.txtComponentName_12, self.txtComponentCount_12)
        MainWindow.setTabOrder(self.txtComponentCount_12, self.txtComponentName_13)
        MainWindow.setTabOrder(self.txtComponentName_13, self.txtComponentCount_13)
        MainWindow.setTabOrder(self.txtComponentCount_13, self.txtComponentName_14)
        MainWindow.setTabOrder(self.txtComponentName_14, self.txtComponentCount_14)
        MainWindow.setTabOrder(self.txtComponentCount_14, self.txtComponentName_15)
        MainWindow.setTabOrder(self.txtComponentName_15, self.txtComponentCount_15)
        MainWindow.setTabOrder(self.txtComponentCount_15, self.txtComponentName_16)
        MainWindow.setTabOrder(self.txtComponentName_16, self.txtComponentCount_16)
        MainWindow.setTabOrder(self.txtComponentCount_16, self.txtComponentName_17)
        MainWindow.setTabOrder(self.txtComponentName_17, self.txtComponentCount_17)
        MainWindow.setTabOrder(self.txtComponentCount_17, self.txtComponentName_18)
        MainWindow.setTabOrder(self.txtComponentName_18, self.txtComponentCount_18)
        MainWindow.setTabOrder(self.txtComponentCount_18, self.txtComponentName_19)
        MainWindow.setTabOrder(self.txtComponentName_19, self.txtComponentCount_19)
        MainWindow.setTabOrder(self.txtComponentCount_19, self.txtComponentName_20)
        MainWindow.setTabOrder(self.txtComponentName_20, self.txtComponentCount_20)
        MainWindow.setTabOrder(self.txtComponentCount_20, self.btnSave)
        MainWindow.setTabOrder(self.btnSave, self.btnLoad)
        MainWindow.setTabOrder(self.btnLoad, self.btnClear)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.lblStudentName.setText(_translate("MainWindow", "Student Name"))
        self.lblGraduate.setText(_translate("MainWindow", "Graduate Student"))
        self.lblStudentID.setText(_translate("MainWindow", "Student ID"))
        self.lblCollege.setText(_translate("MainWindow", "College"))
        self.cboCollege.setItemText(0, _translate("MainWindow", "-----"))
        self.cboCollege.setItemText(1, _translate("MainWindow", "Aerospace Engineering"))
        self.cboCollege.setItemText(2, _translate("MainWindow", "Civil Engineering"))
        self.cboCollege.setItemText(3, _translate("MainWindow", "Computer Engineering"))
        self.cboCollege.setItemText(4, _translate("MainWindow", "Electrical Engineering"))
        self.cboCollege.setItemText(5, _translate("MainWindow", "Industrial Engineering"))
        self.cboCollege.setItemText(6, _translate("MainWindow", "Mechanical Engineering"))
        self.lblComponentName.setText(_translate("MainWindow", "Component Name"))
        self.lblCount.setText(_translate("MainWindow", "Count"))
        self.lblCount_2.setText(_translate("MainWindow", "Count"))
        self.lblComponentName_2.setText(_translate("MainWindow", "Component Name"))
        self.lblIndex_11.setText(_translate("MainWindow", "11."))
        self.lblIndex_12.setText(_translate("MainWindow", "12."))
        self.lblIndex_13.setText(_translate("MainWindow", "13."))
        self.lblIndex_14.setText(_translate("MainWindow", "14."))
        self.lblIndex_15.setText(_translate("MainWindow", "15."))
        self.lblIndex_16.setText(_translate("MainWindow", "16."))
        self.lblIndex_17.setText(_translate("MainWindow", "17."))
        self.lblIndex_18.setText(_translate("MainWindow", "18."))
        self.lblIndex_19.setText(_translate("MainWindow", "19."))
        self.lblIndex_20.setText(_translate("MainWindow", "20."))
        self.lblIndex.setText(_translate("MainWindow", "1."))
        self.lblIndex_2.setText(_translate("MainWindow", "2."))
        self.lblIndex_3.setText(_translate("MainWindow", "3."))
        self.lblIndex_4.setText(_translate("MainWindow", "4."))
        self.lblIndex_5.setText(_translate("MainWindow", "5."))
        self.lblIndex_6.setText(_translate("MainWindow", "6."))
        self.lblIndex_7.setText(_translate("MainWindow", "7."))
        self.lblIndex_8.setText(_translate("MainWindow", "8."))
        self.lblIndex_9.setText(_translate("MainWindow", "9."))
        self.lblIndex_10.setText(_translate("MainWindow", "10."))
        self.btnClear.setText(_translate("MainWindow", "Clear"))
        self.btnLoad.setText(_translate("MainWindow", "Load"))
        self.btnSave.setText(_translate("MainWindow", "Save"))


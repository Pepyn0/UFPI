from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QMainWindow, QStackedLayout

from mainWindow import MainWindow
from registerWindow import RegisterWindow
from searchWindow import SearchWindow

from pessoa import Pessoa
from cadastro import Cadastro

class Ui_MultWindow(QtWidgets.QWidget):
	def setupUi(self, Main):
		Main.setObjectName("Main")
		Main.resize(640, 480)

		self.QtStack = QStackedLayout()
		self.stack0 = QMainWindow()
		self.stack1 = QMainWindow()
		self.stack2 = QMainWindow()

		self.mainScreen = MainWindow()
		self.mainScreen.setupUi(self.stack0)
		
		self.registerScreen = RegisterWindow()
		self.registerScreen.setupUi(self.stack1)

		self.searchScreen = SearchWindow()
		self.searchScreen.setupUi(self.stack2)

		self.QtStack.addWidget(self.stack0)
		self.QtStack.addWidget(self.stack1)
		self.QtStack.addWidget(self.stack2)

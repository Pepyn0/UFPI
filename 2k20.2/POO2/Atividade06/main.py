import sys
from PyQt5 import QtGui, QtWidgets
from PyQt5.QtWidgets import QMessageBox, QApplication, QMainWindow

from multWindow import Ui_MultWindow

from pessoa import Pessoa
from cadastro import Cadastro


class Main(Ui_MultWindow):
	
	def setupUi(self, Main):
		super().setupUi(Main)
		self.cadastro = Cadastro()
		self.mainScreen.pushButtonScreenRegister.clicked.connect(self.buttonScreenRegister)
		self.mainScreen.pushButtonScreenSearch.clicked.connect(self.buttonScreenSearch)

		self.registerScreen.pushButtonRegister.clicked.connect(self.buttonRegister)
		self.searchScreen.pushButtonSearch.clicked.connect(self.buttonSearch)

	def returnMainScreen(self):
		self.QtStack.setCurrentIndex(0)

	def buttonScreenRegister(self):
		self.QtStack.setCurrentIndex(1)

	def buttonScreenSearch(self):
		self.QtStack.setCurrentIndex(2)

	def buttonRegister(self):
		nome = self.registerScreen.lineEditNameIn.text()
		endereco = self.registerScreen.lineEditCityIn.text()
		cpf = self.registerScreen.lineEditCpfIn.text()
		nascimento = self.registerScreen.lineEditDateIn.text()

		if not(nome == '' or endereco == '' or cpf == '' or nascimento == ''):
			p = Pessoa(nome, endereco, cpf, nascimento)
			if(self.cadastro.cadastrar(p)):
				QMessageBox.information(None, "POOII", "Cadastro realizado com sucesso!")
				self.registerScreen.lineEditNameIn.setText('')
				self.registerScreen.lineEditCityIn.setText('')
				self.registerScreen.lineEditDateIn.setText('')
				self.registerScreen.lineEditCpfIn.setText('')
			else:
				QMessageBox.information(None, "POOII", "CPF invalido!")
		else:
			QMessageBox.information(None, "POOII", "Todos os valores devem ser preenchidos!")

		self.returnMainScreen()

	def buttonSearch(self):
		cpf = self.searchScreen.lineEditCpfSearch.text()
		pessoa = self.cadastro.busca(cpf)
		if(pessoa):
			self.searchScreen.lineEditNameOut.setText(pessoa.nome)
			self.searchScreen.lineEditCityOut.setText(pessoa.endereco)
			self.searchScreen.lineEditDateOut.setText(pessoa.nascimento)
		else:
			QMessageBox.information(None, "POOII", "CPF não encontrado!")


if __name__ == "__main__":
	app = QApplication(sys.argv)
	MainWindow = QMainWindow()
	ui = Main()
	ui.setupUi(MainWindow)
	sys.exit(app.exec_())

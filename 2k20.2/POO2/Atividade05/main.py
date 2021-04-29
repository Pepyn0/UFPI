import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QMessageBox

#
from ui_tela import Ui_MainWindow
from cadastro import Cadastro
from pessoa import Pessoa


class MainWindowBeckEnd(Ui_MainWindow):

	def setupUi(self, MainWindow):
		super().setupUi(MainWindow)
		self.cadastro = Cadastro()
		self.pushButtonCadastrar.clicked.connect(self.botaoCadastrar)
		self.pushButtonBuscar.clicked.connect(self.botaoBuscar)
	
	def botaoCadastrar(self):
		nome = self.lineEditNomeIn.text()
		endereco = self.lineEditCidadeIn.text()
		cpf = self.lineEditCpfIn.text()
		nascimento = self.lineEditNascimentoIn.text()
		if not(nome == '' or endereco == '' or cpf == '' or nascimento == ''):
			p = Pessoa(nome, endereco, cpf, nascimento)
			if(self.cadastro.cadastrar(p)):
				QMessageBox.information(None, "POOII", "Cadastro realizado com sucesso!")
				self.lineEditNomeIn.setText('')
				self.lineEditCidadeIn.setText('')
				self.lineEditNascimentoIn.setText('')
				self.lineEditCpfIn.setText('')
			else:
				QMessageBox.information(None, "POOII", "CPF invalido!")
		else:
			QMessageBox.information(None, "POOII", "Todos os valores devem ser preenchidos!")

	def botaoBuscar(self):
		cpf = self.lineEditCpfBusca.text()
		pessoa = self.cadastro.busca(cpf)
		if(pessoa):
			self.lineEditNomeOut.setText(pessoa.nome)
			self.lineEditCidadeOut.setText(pessoa.endereco)
			self.lineEditNascimentoOut.setText(pessoa.nascimento)
		else:
			QMessageBox.information(None, "POOII", "CPF não encontrado!")


if __name__ == "__main__":
	app = QtWidgets.QApplication(sys.argv)
	MainWindow = QtWidgets.QMainWindow()
	ui = MainWindowBeckEnd()
	ui.setupUi(MainWindow)
	MainWindow.show()
	sys.exit(app.exec_())

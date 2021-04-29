class Cadastro(object):

	__slots__ = ["_listaPessoas"]

	def __init__(self):
		self._listaPessoas = []

	def busca(self, cpf):
		for p in self._listaPessoas:
			if(p.cpf == cpf):
				return p
		return None

	def cadastrar(self, pessoa):
		existe = self.busca(pessoa.cpf)
		if(existe):
			return False
		else:
			self._listaPessoas.append(pessoa)
			return True

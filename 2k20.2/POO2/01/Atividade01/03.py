# -*- coding: utf-8 -*-

__author__		= "Pepyn0"
__copyright__	= "Copyright 2021, eXu Corp.dev"

valorHora = float(input())
nHora = int(input())

salario = valorHora * nHora
ir = salario * 1.11 - salario
inss = salario * 1.08 - salario
sindicato = salario * 1.05 - salario
sliquido = salario - ir - inss - sindicato

print("+ Salário Bruto : R$ {:.2f}".format(salario))
print("- IR (11%) : R$ {:.2f}".format(ir))
print("- INSS (8%) : R$ {:.2f}".format(inss))
print("- Sindicato (5%) : R$ {:.2f}".format(sindicato))
print("= Salário Liquido : R$ {:.2f}".format(sliquido))

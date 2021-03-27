# -*- coding: utf-8 -*-

__author__		= "Pepyn0"
__copyright__	= "Copyright 2021, eXu Corp.dev"

peso = float(input())

excesso = 0 if peso <= 50 else peso - 50

multa = excesso * 4.00

print("peso excedente: {}".format(excesso))
print("valor da multa: {}".format(multa))

# -*- coding: utf-8 -*-

__author__		= "Pepyn0"
__copyright__	= "Copyright 2021, eXu Corp.dev"

nLitros = int(input())
cTipo = input()

if(cTipo == 'A'):
	if(nLitros <= 20):
		print("R$ {:.2f}".format(nLitros * 3.45 - (nLitros * 3.45 * 0.03)))
	else:
		print("R$ {:.2f}".format(nLitros * 3.45 - (nLitros * 3.45 * 0.05)))
elif(cTipo == 'G'):
	if(nLitros <= 20):
		print("R$ {:.2f}".format(nLitros * 4.53 - (nLitros * 3.45 * 0.04)))
	else:
		print("R$ {:.2f}".format(nLitros * 4.53 - (nLitros * 3.45 * 0.06)))

# -*- coding: utf-8 -*-

__author__		= "Pepyn0"
__copyright__	= "Copyright 2021, eXu Corp.dev"

valor = 1
while(valor > 0 and valor < 16):
	valor = int(input())
	i = valor - 1
	result = valor
	while(i > 0):
		result *= i
		i -= 1

	print("{}".format(result))

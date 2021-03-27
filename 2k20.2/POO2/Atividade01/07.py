# -*- coding: utf-8 -*-

__author__		= "Pepyn0"
__copyright__	= "Copyright 2021, eXu Corp.dev"

valor = int(input())
i = valor - 1
while(i > 0):
	valor *= i
	i -= 1

print("{}".format(valor))

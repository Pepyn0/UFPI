# -*- coding: utf-8 -*-

__author__		= "Pepyn0"
__copyright__	= "Copyright 2021, eXu Corp.dev"

base = int(input())
expoente = int(input())

i = 0
resultado = base
while(i < expoente):
	resultado += base
	i+= 1

print("{}".format(resultado))

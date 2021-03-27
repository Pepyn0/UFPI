# -*- coding: utf-8 -*-

__author__		= "Pepyn0"
__copyright__	= "Copyright 2021, eXu Corp.dev"

tabuada = int(input())
comeco = int(input())
termina = int(input())

while(comeco <= termina):
	print("{} x {}".format(tabuada, tabuada * comeco))
	comeco += 1

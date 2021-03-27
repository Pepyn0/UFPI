# -*- coding: utf-8 -*-

__author__		= "Pepyn0"
__copyright__	= "Copyright 2021, eXu Corp.dev"

l1 = int(input())
l2 = int(input())
l3 = int(input())

if((l1 + l2) > l3 and (l1 + l3) > l2):
	if(l1 == l2 and l2 == l3):
		print("Triângulo Equilátero")
	elif(l1 == l2 or l1 == l3 or l2 == l3):
		print("Triângulo Isósceles")
	else:
		print("Triângulo Escaleno")
else:
	print("não pode ser triangulo")

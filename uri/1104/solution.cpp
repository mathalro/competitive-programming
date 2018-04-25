# -*- coding: utf-8 -*-

maxn = 100001

while 1:
	a,b = [ int(i) for i in raw_input().split() ]

	if a + b == 0: break

	cartasA = [0]*maxn
	cartasB = [0]*maxn
	contA = 0
	contB = 0
	maior = 0

	for i in [ int(i) for i in raw_input().split() ]:
		cartasA[i] = 1;
		maior = max(maior, i)
	for i in [ int(i) for i in raw_input().split() ]:
		cartasB[i] = 1;
		maior = max(maior, i)
	
	for i in range(1, maior+1):
		if cartasA[i] and not cartasB[i]:	
			contA += 1;
		if cartasB[i] and not cartasA[i]:	
			contB += 1;

	print min(contA, contB)
# -*- coding: utf-8 -*-


gp = [[]*100]*100
pt = [[]*100]*100

while 1:
	g,p = [ int(i) for i in raw_input().split() ]
	if g == p == 0:
		break

	for i in range(0, g):
		gp[i] = [ int(j) for j in raw_input().split() ]

	s = int(input())

	for i in range(0, s):
		pt[i] = [ int(j) for k, j in enumerate(raw_input().split()) if k > 0 ]


	res = []
	for i, pontuacoes in enumerate(pt[:s]):
		pontuados = [0]*p
		for j, gpes in enumerate(gp[:g]):
			for piloto, posicao in enumerate(gpes):
				if posicao <= len(pontuacoes):
					pontuados[piloto] += pontuacoes[posicao-1]

		res.append(pontuados)

	for i in res[:s]:
		campeao = max(i)
		campeoes = []
		for piloto, j in enumerate(i):
			if j == campeao:
				campeoes.append(piloto+1)
		print str(campeoes).replace("[", "").replace("]", "").replace(",", "")


				
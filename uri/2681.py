def exp(base, e, mod):
	if (e == 0): 
		return 1
	if (e == 1): 
		return base
	tmp = exp(base, e//2, mod)
	tmp = (tmp*tmp)%mod
	if (e&1): 
		tmp = (tmp*base)%mod
	return tmp

mod = 60*60*24

x = input();
x = int(x)

ans = 1
base = 2

"""
while (x > 0):
	if (x&1):
		ans = (ans*base)%mod
	base = (base*base)%mod
	x = x//2
"""

ans = exp(base, x, mod)
ans = (ans-1)%mod;
if (ans < 0):
	ans += mod

hora = ans//3600
ans = ans%3600
minuto = ans//60
ans = ans%60
segundo = ans
print('%02d:%02d:%02d' % (hora, minuto, segundo))
	

t = int(raw_input())

hora = t // 3600
t -= hora * 3600
m = t // 60
seg = t - (m * 60)

print str(hora)+":"+str(m)+":"+str(seg)

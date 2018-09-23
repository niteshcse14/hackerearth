t = input()
while (t > 0):
	t = t - 1
	d, a, m, b, x = [int(x) for x in raw_input().split()]
	x = x - d
	tot = a * m + b
	div = x / tot
	res = (m + 1) * div
	diff = x - div * (a * m + b)
	if (diff > (a * m)) :
		res += m + 1
		print(res)
		continue
	div = diff / a
	res += div
	if ((div * a) < diff) :
		res += 1
	print (res)
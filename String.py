n = input()
s = raw_input()
ar = []
for i in range(26) :
	ar.append(0)
s = list(s)
for i in range(0, n) :
	ar[ord(s[i]) - ord('a')] += 1;
mx = 0
for i in range(26) :
	mx = max(mx, ar[i])
print(n - mx)
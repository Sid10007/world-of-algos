def gcd(a, b):
	if a == 0:
		return b
	return gcd(b % a, a)


a = int(input("a = "))
b = int(input("b = "))
res = gcd(max(a, b), min(a, b))
#print(res)
print("gcd(a, b) = ", res)

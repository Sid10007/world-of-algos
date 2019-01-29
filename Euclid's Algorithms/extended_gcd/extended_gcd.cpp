#include<bits/stdc++.h>
using namespace std;

template <class T>
T extended_gcd(T a, T b, T*  x, T* y) {
	if(a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}

	T x1, y1, gcd;
	gcd = extended_gcd(b % a, a, &x1, &y1);

	*x = y1 - ((int)(b / a) * x1);
	*y = x1;
	return gcd;
}

int main() {
	long long a, b, x, y;
	cin >> a >> b;
	cout << extended_gcd<long long>(a, b, &x, &y) << "\n";
	cout << "x = " << x << "y = " << y << "\n";
	return 0;
}
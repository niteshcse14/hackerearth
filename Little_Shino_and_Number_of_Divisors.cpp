#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
const LL Modules = 1e9 + 7;
const LL MAX = 1e6 + 5;
LL n;
LL arr[MAX + 5];
LL ans[MAX];
LL Multiply(LL a, LL b) {
	LL result = a * b;
	result = result % Modules;
	if (result < 0) {
		result += Modules;
	}
	return result % Modules;
}
LL Addition(LL a, LL b) {
	LL result = a + b;
	result %= Modules;
	if (result < 0) {
		result += Modules;
	}
	return result % Modules;
}
LL POWER(LL a, LL b) {
	LL result = 1;
	while (b > 0) {
		if (b & 1) {
			result = Multiply(result, a);
		}
		b >>= 1;
		a = Multiply(a, a);
	}
	if (result < 0) {
		result += Modules;
	}
	return result;
}
int main() {
	LL result = 1;
	LL inv = POWER(2, Modules - 2);
	scanf("%lld", &n);
	for (int i = 0; i < n; ++i) {
		scanf ("%lld", &arr[i]);
		result = Multiply(result, Addition(arr[i], 1) % Modules) % Modules;
	}
	LL out = 1;
	for (int i = 0; i < n; ++i) {
		if (arr[i] > 0) {
			LL sum = Multiply(Multiply(arr[i], arr[i] + 1) % Modules, inv) % Modules;
			LL b = Multiply(result, POWER(Addition(arr[i], 1), Modules - 2));
			LL a = Multiply(sum, b) % Modules;
			out = Multiply(out, Addition(a, 1) % Modules) % Modules;
		}
	}
	printf("%lld\n", out);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = 1e9 + 7;
ll power(ll a, ll b) {
	a %= MOD;
	b %= MOD;
	ll res = 1;
	while (b > 0) {
		if (b & 1) {
			res = (res * a) % MOD;
		}
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res;
}
ll t, n, p;
int main() {
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld%lld", &n, &p);
		printf("%lld\n", power(n, p));
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e5 + 5;
const ll MOD = 1e9 + 7;
ll arr[maxn];
ll fact[maxn];
ll sum, n;
ll temp[200];
ll power(ll a, ll b) {
	ll res = 1;
	a %= MOD;
	b %= MOD;
	while (b > 0) {
		if (b & 1) {
			 res = (res * a) % MOD;
		}
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res;
}
ll panda_xor() {
	for (ll i = 0; i < n; ++i) {
		memset(temp, 0, sizeof(temp));
		for (ll j = 0; j < 128; ++j) {
			if (fact[j] != 0) {
				ll cc = j ^ arr[i];
				temp[cc] = (temp[cc] + fact[j]) % MOD;
			}
		}
		for (ll j = 0; j < 128; ++j) {
			fact[j] = (fact[j] + temp[j]) % MOD;
		}
		fact[arr[i]] = (fact[arr[i]] + 1) % MOD;
	}
	ll res = 0;
	ll inv = power(2, MOD - 2);
	for (ll i = 0; i < 128; ++i) {
		ll tt = ((fact[i] % MOD) * ((fact[i] - 1) % MOD) % MOD * inv) % MOD;
		res = (res + tt) % MOD;
	}
	return res;
}
int main() {
	memset(temp, 0, sizeof(temp));
	memset(fact, 0, sizeof(fact));
	sum = 0;
	scanf("%lld", &n);
	for (ll i = 0; i < n; ++i) {
		scanf("%lld", &arr[i]);
	}
	printf("%lld\n", panda_xor());
}
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = 1e9 + 7;
const ll maxn = 1e6 + 5;
ll a[maxn], b[maxn];
ll n;
ll solve(ll arr[]) {
	ll res = 0;
	ll sum = 0;
	for (int i = 0; i < n; ++i) {
		res += arr[i] * 1LL * i % MOD - sum;
		sum += arr[i];
		sum %= MOD;
	}
	if (res < 0) {
		res += MOD;
	}
	return res % MOD;
}
int main() {
	scanf ("%lld", &n);
	for (int i = 0; i < n; ++i) {
		scanf ("%lld%lld", &a[i], &b[i]);
	}
	sort (a, a + n);
	sort (b, b + n);
	printf("%lld\n", (solve(a) + solve(b)) % MOD);
	return 0;
}
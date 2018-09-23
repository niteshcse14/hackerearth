#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e6 + 5;
const ll MOD = 1e9 + 7;
ll dp[maxn];
ll t, n;
ll salesman (ll n) {
	if (n == 0) {
		return 0;
	}
	if (n >= 1 && n <= 3) {
		return n;
	}
	if (dp[n] != 0 && n < maxn) {
		return dp[n] % MOD;
	}
	return (salesman(n - 1) % MOD + salesman(n - 2) % MOD + salesman(n - 3) % MOD) % MOD;
}
void init () {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (ll i = 4; i < maxn; ++i) {
		dp[i] = dp[i - 1] % MOD + dp[i - 2] % MOD + dp[i - 3] % MOD;
		dp[i] %= MOD;
	}
}
int main() {
	memset(dp, 0, sizeof(dp));
	init ();
	scanf ("%lld", &t);
	while (t--) {
		scanf ("%lld", &n);
		printf("%lld\n", salesman(n));
	}
	return 0;
}
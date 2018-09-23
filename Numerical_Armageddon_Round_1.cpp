#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e6 + 5;
const ll MOD = 1e9 + 7;
ll t, n;
ll arr[maxn];
char str[maxn];
ll dp[maxn][10];
ll solve () {
	memset (dp, 0, sizeof (dp));
	for (ll i = 0; i < n; ++i) {
		dp[i][(str[i] - '0') % 6]++;
	}
	for (ll i = 1; i < n; ++i) {
		for (ll j = 0; j < 6; ++j) {
			dp[i][j] += dp[i - 1][j];
			dp[i][j] %= MOD;
			dp[i][(j * 10 + (str[i] - '0')) % 6] += dp[i - 1][j];
			dp[i][j] %= MOD;
		}
	}
	return dp[n - 1][0] % MOD;
}
int main () {
	scanf ("%lld", &t);
	while (t--) {
		scanf ("%s", str);
		n = strlen (str);
		printf("%lld\n", solve ());
	}
	return 0;
}
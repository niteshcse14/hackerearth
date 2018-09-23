#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 105;
ll t, n, m, K, mx;
ll arr[maxn][maxn], dp[maxn][maxn][505];
void solve (ll i, ll j, ll sum) {
	if (dp[i][j][sum] != -1) return;
	dp[i][j][sum] = 1;
	sum += arr[i][j];
	if (sum > K) return;
	if ((i == n) && (j == m)) {
		mx = max (mx, sum);
		return;
	}
	if ((i + 1) <= n) solve (i + 1, j, sum);
	if ((j + 1) <= m) solve (i, j + 1, sum);
	if ((i + 1) <= n && (j + 1) <= m) solve (i + 1, j + 1, sum);
	return;
}
int main () {
	scanf ("%lld", &t);
	while (t--) {
		scanf ("%lld%lld%lld", &n, &m, &K);
		for (ll i = 1; i <= n; ++i) {
			for (ll j = 1; j <= m; ++j) {
				scanf ("%lld", &arr[i][j]);
				for (ll k = 0; k <= K; ++k) {
					dp[i][j][k] = -1;
				}
			}
		}
		mx = -1;
		solve (1, 1, 0);
		printf("%lld\n", mx);
	}
	return 0;
}
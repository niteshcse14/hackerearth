#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e5 + 5;
ll t, n, sum, cnt;
ll arr[maxn], dp[105][maxn];
int main () {
	scanf ("%lld", &t);
	while (t--) {
		memset (dp, 0, sizeof (dp));
		scanf ("%lld", &n);
		sum = 0;
		for (ll i = 0; i < n; ++i) {
			scanf ("%lld", &arr[i]);
			sum += arr[i];
			dp[i][i] = 1;
		}
		for (ll i = 0; i <= n; ++i) {
			dp[i][0] = 1;
		}
		dp[0][arr[0]] = 1;
		for (ll i = 1; i < n; ++i) {
			for (ll j = 1; j <= sum; ++j) {
				if (j < arr[i]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i]];
				}
			}
		}
		cnt = 0;
		for (ll i = 0; i <= sum; ++i) {
			if (dp[n - 1][i] > 0) {
				cnt++;
			}
		}
		printf("%lld\n", cnt);
	}
	return 0;
}
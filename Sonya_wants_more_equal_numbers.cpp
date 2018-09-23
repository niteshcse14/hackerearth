#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int maxn_ = 4e4 + 1;
int n, ans;
int dp[101][maxn_], cnt[maxn], arr[maxn], pre[maxn];
int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &arr[i]);
		pre[i] = pre[i - 1] + arr[i];
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < maxn_; ++j) {
			dp[i][j] = dp[i - 1][j];
			for (int k = i - 1; k >= 0; --k) {
				if ((arr[i] + pre[i - 1] - pre[k]) > j) break;
				else if ((arr[i] + pre[i - 1] - pre[k]) == j) {
					dp[i][j] = max (dp[i][j], dp[k][j] + 1);
				}
			}
			cnt[j] = max (dp[i][j], cnt[j]);
			ans = max (ans, cnt[j]);
		}
	}
	printf("%d\n", ans);
	for (int i = 0; i < maxn_; ++i) {
		if (cnt[i] == ans) printf("%d ", i);
	}
	printf("\n");
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
int t, n, sum;
int arr[maxn], dp[101][10001];
int main () {
	scanf ("%d", &t);
	while (t--) {
		sum = 0;
		memset (dp, 0, sizeof (dp));
		scanf ("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf ("%d", arr + i);
			dp[arr[i]][arr[i]] = 1;
			sum += arr[i];
		}
		dp[0][arr[0]] = 1;
		for (int i = 0; i < n; ++i) {
			dp[i][0] = 1;
		}
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j <= sum; ++j) {
				if (j < arr[i]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i]];
				}
			}
		}
		int cnt = 0;
		for (int i = 0; i <= sum; ++i) {
			if (dp[n - 1][i]) {
				cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
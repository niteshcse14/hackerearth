#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int n, cnt, ans, a, b;
int arr[maxn], dp[maxn];
int main () {
	ans = 0;
	scanf ("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf ("%d", &arr[i]);
		dp[i] = 1;
	}
	sort (arr, arr + n);
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (arr[i] % arr[j] == 0) {
				dp[i] = max (dp[i], dp[j] + 1);
			}
		}
		printf("%d ", dp[i]);
		ans = max (ans, dp[i]);
	}
	printf("\n");
	if (ans == 1) {
		ans = -1;
	}
	printf("%d\n", ans);
	return 0;
}
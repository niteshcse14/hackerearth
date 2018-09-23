#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
const int maxn_k = 105;
const int MOD = 1e9 + 7;
int sum = 0, x, k, t;
int dp[maxn_k][maxn];
void solve () {
	for (int i = 1; i < maxn; ++i) {
		dp[1][i] = 1;
	}
	for (int i = 0; i < maxn; ++i) {
		dp[0][i] = 0;
	}
	for (int i = 0; i < maxn_k; ++i) {
		dp[i][0] = 0;
	}
	for (int i = 2; i < maxn_k; ++i) {
		for (int j = 1; j < maxn; ++j) {
			if (j < i) {
				dp[i][j] = (dp[i - 1][j]) % MOD;
			}
			else if (i == j) {
				dp[i][j] = (dp[i - 1][j] + 1) % MOD;
			}
			else {
				sum = 0;
				for (int k = j - 1; k >= (j - i); --k) {
					sum = (sum + dp[i][k]) % MOD;;
				}
				dp[i][j] = sum % MOD;
			}
		}
	}
	/*
	for (int i = 1; i <= 10; ++i) {
		for (int j = 1; j <= 10; ++j) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	*/
}
int main () {
	solve();
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d%d", &x, &k);
		printf("%d\n", dp[k][x]);
	}
	return 0;
}
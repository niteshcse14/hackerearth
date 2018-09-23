#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int n;
int dp[maxn][maxn], arr[maxn];
int solve (int i, int j) {
	if(i==j)
        return 1;
	if (i > j) 
		return 0;
	if (arr[i] == arr[j]) 
		return solve (i + 1, j - 1);
	if (dp[i][j] != -1) 
		return dp[i][j];
	int res = INT_MAX;
	for (int k = i; k < j; ++k) {
		res = min (res, solve (i, k) + solve (k + 1, j));
	}
	dp[i][j] = res;
	return res;
}
int main () {
	freopen ("input.txt", "r", stdin);
	scanf ("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf ("%d", &arr[i]);
		for (int j = i + 1; j < n; ++j) {
			dp[i][j] = dp[j][i] = -1;
		}
	}
	printf("%d\n", solve (0, n - 1));
	return 0;
}
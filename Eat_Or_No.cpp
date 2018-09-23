#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int vitamin[maxn];
int carbs[maxn];
int fats[maxn];
int protien[maxn];
int v, c, f, p, n;
int x, y, z, u;
bool subset_sum_check(int arr[], int sum) {
	bool dp[n + 1][sum + 1];
	for (int i = 0; i <= n; ++i) {
		dp[i][0] = true;
	}
	for (int i = 1; i <= sum; ++i) {
		dp[0][i] = false;
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= sum; ++j) {
			if (j < arr[i - 1]) {
				dp[i][j] = dp[i - 1][j];
			}
			if(j >= arr[i - 1]) {
				dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
			}
		}
	}
	return dp[n][sum];
}
int main() {
	scanf ("%d%d%d%d%d", &v, &c, &f, &p, &n);
	for (int i = 0; i < n; ++i) {
		scanf ("%d%d%d%d", &vitamin[i], &carbs[i], &fats[i], &protien[i]);
	}
	subset_sum_check(vitamin, v);
	if (subset_sum_check(vitamin, v) == false) {
		printf("NO\n");
		return 0;
	}
	if (subset_sum_check(carbs, c) == false) {
		printf("NO\n");
		return 0;
	}
	if (subset_sum_check(fats, f) == false) {
		printf("NO\n");
		return 0;
	}
	if (subset_sum_check(protien, p) == false) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	return 0;
}
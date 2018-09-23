#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[1024][1024];
ll arr[1024];
ll n, a, b;
ll rec(ll i, ll j) {
	if (i > j) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	ll a = arr[j] + rec(i, j - 1);
	ll b = arr[i] + rec(i + 1, j);
	ll c = INT_MIN;
	ll d = INT_MIN;
	if (i < j) {
		c = (arr[i] * arr[i + 1]) + rec(i + 2, j);
		d = (arr[j] * arr[j - 1]) + rec(i, j - 2);
	}
	dp[i][j] = max(max(a, b), max(c, d));
	return dp[i][j];
}
int main() {
	for (ll i = 0; i < 1024; ++i) {
		for (ll j = 0; j < 1024; ++j) {
			dp[i][j] = -1;
		}
	}
	scanf("%lld", &n);
	for (ll i = 0; i < n; ++i) {
		scanf("%lld", &arr[i]);
	}
	printf("%lld\n", rec(0, n - 1));
	return 0;
}
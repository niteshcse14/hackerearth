#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 5e3 + 5;
ll n, ans;
ll arr[maxn], dp[maxn];
int main () {
	scanf ("%lld", &n);
	for (ll i = 0; i < n; ++i) {
		scanf ("%lld", &arr[i]);
		dp[i] = 1;
	}
	ans = 1;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (arr[i] > 0 && arr[j] < 0 && abs (arr[j]) < arr[i]) {
				dp[i] = max (dp[i], dp[j] + 1);
			}
			else if (arr[i] < 0 && arr[j] > 0 && arr[j] < abs (arr[i])) {
				dp[i] = max (dp[i], dp[j] + 1);
			}
		}
		ans = max (dp[i], ans);
	}
	printf("%lld\n", ans);
	return 0;
}
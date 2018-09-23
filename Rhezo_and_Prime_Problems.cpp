#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 5;
typedef long long int ll;
vector < int > prime;
ll arr[maxn];
bool visited[maxn];
ll prefix[maxn], dp[maxn];
ll n, mx, ans, sum, SIZE;
void init() {
	prime.push_back(2);
	for (ll i = 3; i < maxn; i += 2) {
		if (!visited[i]) {
			prime.push_back(i);
			for (ll j = i * i; j < maxn; j += 2 * i) {
				visited[j] = true;
			}
		}
	}
}
int main () {
	init();
	scanf ("%lld", &n);
	for (ll i = 1; i <= n; ++i) {
		scanf ("%lld", &arr[i]);
		prefix[i] = prefix[i - 1] + arr[i];
	}
	dp[0] = dp[1] = 0;
	for (ll i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1];
		for (ll j = 0; j < (int)prime.size() && prime[j] <= i; ++j) {
			ll idx = i - prime[j] - 1;
			if (idx == -1) {
				dp[i] = max (dp[i], prefix[i]);
			}
			else {
				dp[i] = max (dp[i], dp[idx] + prefix[i] - prefix[idx + 1]);
			}
		}
	}
	printf("%lld\n", dp[n]);
	return 0;
}
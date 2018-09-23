#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, m, ans, k;
void solve (ll a, ll b) {
	if (a == 1 && b == 1) {
		return;
	}
	if (a == 1) {
		ans = max (ans, b);
		return;
	}
	if (b == 1) {
		ans = max (ans, a);
		return;
	}
	if (a * b <= k) {
		ans = max (ans, a * b);
		return;
	}
	solve(a - 1, b);
	solve(a, b - 1);
	solve(a - 1, b - 1);
}
int main () {
	scanf ("%lld", &t);
	while (t--) {
		scanf ("%lld%lld%lld", &n, &m, &k);
		if (n == 1 || m == 1 || n >= k || m >= k) {
			printf("%lld\n", k);
			continue;
		}
		if (k >= n * m) {
			printf("%lld\n", n * m);
			continue;
		}
		ll sq = sqrt (k);
		if (sq * sq == k) {
			if (sq <= n && sq <= m) {
				printf("%lld\n", k);
				continue;
			}
		}
		ans = -1;
		solve (n, m);
		printf("%lld\n", ans);
	}
	return 0;
}
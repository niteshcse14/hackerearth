#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld double long
ll t, n, a, b, x, y, ans, ans1, ans2;
ll solve() {
	ll res = ((a + b) * x * x - 2 * b * n * x + b * n * n);
	return res;
}
int main() {
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld%lld%lld", &n, &a, &b);
		x = (b * n) / (a + b);
		ans = solve();
		x++;
		ans = min(ans, solve());
		x -= 2;
		ans = min(ans, solve());
		printf("%lld\n", ans);
	}
	return 0;
}
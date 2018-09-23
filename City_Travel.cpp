#include <bits/stdc++.h>
using namespace std;
#define maxn 10010
#define ll long long int
ll n, a, b, s, x, temp, ans;
struct node {
	ll x, y;
};
node point[maxn];
bool cmp(node a, node b) {
	return a.x < b.x;
}
ll solve(ll num) {
	double tt = double(num) / double(x);
	return ceil(tt);
}
int main() {
	scanf("%lld%lld%lld", &s, &x, &n);
	point[0].x = point[0].y = 0;
	for (ll i = 1; i <= n; ++i)
		scanf("%lld%lld", &point[i].x, &point[i].y);
	sort(point + 1, point + n + 1, cmp);
	for (ll i = 1; i <= n; ++i) {
		if (s <= 0) break;
		temp = (point[i].x - point[i - 1].x - 1);
		if (temp * x <= s) {
			ans += temp;
			s -= temp * x;
		}
		else {
			ans += solve(s);
			s -= solve(s) * x;
		}
		if (s <= 0) break;
		ans++;
		s -= point[i].y;
	}
	if (s > 0) ans += solve(s);
	printf("%lld\n", ans);
	return 0;
}
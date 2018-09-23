#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, x_min, x_max, y_min, y_max, x, y;
ll min(ll a, ll b) {
	if (a < b) {
		return a;
	}
	return b;
}
ll max(ll a, ll b) {
	if (a > b) {
		return a;
	}
	return b;
}
int main() {
	scanf ("%lld", &t);
	while (t--) {
		scanf ("%lld", &n);
		x_min = y_min = 99999999999999999;
		x_max = y_max = -99999999999999999;
		for (int i = 0; i < n; ++i) {
			scanf ("%lld%lld", &x, &y);
			x_min = min(x_min, x);
			x_max = max(x_max, x);
			y_min = min(y_min, y);
			y_max = max(y_max, y);
		}
		//printf("%lld   %lld  %lld  %lld\n", x_min, x_max, y_min, y_max);
		x = max(x_max - x_min, y_max - y_min);
		ll res = x * x;
		printf("%lld\n", res);
	}
	return 0;
}
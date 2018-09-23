#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e5 + 5;
ll t, n, sum, k;
ll data, ans, last_int;
int main () {
	scanf ("%lld", &t);
	while (t--) {
		scanf ("%lld%lld", &n, &k);
		sum = 0;
		ans = 0;
		scanf ("%lld", &data);
		last_int = data;
		if (data <= k) {
			sum = data;
		}
		for (ll i = 1; i < n; ++i) {
			scanf ("%lld", &data);
			if (data <= k) {
				sum += data;
			}
			else {
				sum = 0;
			}
			ans = max (sum, ans);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
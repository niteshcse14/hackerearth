#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e5 +5;
ll prefix[maxn];
ll t, data, n, l, r, q;
int main () {
	scanf ("%lld", &t);
	while (t--) {
		scanf ("%lld", &n);
		prefix[0] = 0;
		for (int i = 1; i <= n; ++i) {
			scanf ("%lld", &data);
			prefix[i] = prefix[i - 1] + data;
		}
		scanf ("%lld", &q);
		while (q--) {
			scanf ("%lld%lld", &l, &r);
			printf("%lld\n", prefix[r] - prefix[l - 1]);
		}
	}
	return 0;
}
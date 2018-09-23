#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e5 + 5;
ll t, n, data, sum, l, r, ansl, ansr;
ll prefix[maxn];
ll dp[maxn][2];
int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		sum = 0;
		for (int i = 0; i <= n; ++i) {
			dp[i][0] = dp[i][1] = -1;
		}
		prefix[0] = 0;
		dp[0][0] = 0;
		for (int i = 1; i <= n; ++i) {
			scanf ("%d", &data);
			sum += data;
			sum %= n;
			prefix[i] = (sum % n + n) % n;
		}
		ansl = l = 0;
		ansr = r = 1e9 + 1;
		for (int i = 1; i <= n; ++i) {
			if (dp[prefix[i]][0] != -1) {
				l = dp[prefix[i]][0];
				r = i;
			}
			dp[prefix[i]][0] = i;
			if ((r - l) < (ansr - ansl)) {
				ansl = l;
				ansr = r;
			}
		}
		printf("%lld %lld\n", ansl + 1, ansr);
	}
	return 0;
}
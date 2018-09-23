#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e5 + 15;
ll q, n, data;
ll cnt[maxn];
ll isPrime[maxn];
void init() {
	for (ll i = 2; i * i <= maxn; ++i) {
		if (isPrime[i] == 0) {
			for (ll j = 2 * i; j < maxn; j += i) {
				isPrime[j] = 1;
			}
		}
	}
}
void factors(ll val) {
	for (ll i = 1; i <= sqrt(val); ++i) {
		if (val % i == 0) {
			if (val / i == i) {
				cnt[i]++;
			}
			else {
				cnt[i]++;
				cnt[val / i]++;
			}
		}
	}
}
int main() {
	memset(cnt, 0, sizeof(cnt));
	memset(isPrime, 0, sizeof(isPrime));
	init();
	scanf("%lld", &n);
	for (ll i = 0; i < n; ++i) {
		scanf("%lld", &data);
		if (isPrime[data] == 0 && data > 2) {
			cnt[data]++;
			cnt[1]++;
		}
		else {
			factors(data);
		}
	}
	scanf("%lld", &q);
	while (q--) {
		scanf("%lld", &data);
		printf("%lld\n", cnt[data]);
	}
	return 0;
}
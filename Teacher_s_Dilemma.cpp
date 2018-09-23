#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const maxn = 1e6 + 5;
const ll MOD = 1e9 + 7;
struct subset {
	ll parent;
	ll rank;
};
ll n, m, a, b, res;
ll cnt[maxn];
subset subsets[maxn];
ll mul(ll a, ll b) {
	ll res = 1;
	res = a * b;
	res %= MOD;
	if (res < 0) {
		res += MOD;
	}
	return res;
}
ll find(ll i) {
	if (subsets[i].parent != i) {
		subsets[i].parent = find(subsets[i].parent);
	}
	return subsets[i].parent;
}
void Union(ll x, ll y) {
	if (x == y) {
		return;
	}
	ll xroot = find(x);
	ll yroot = find(y);
	if (subsets[xroot].rank < subsets[yroot].rank) {
		subsets[xroot].parent = yroot;
	}
	else if (subsets[xroot].rank > subsets[yroot].rank){
		subsets[yroot].parent = xroot;
	}
	else {
		subsets[xroot].parent = yroot;
		subsets[yroot].rank++;
	}
}
int main() {
	res = 1;
	scanf ("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; ++i) {
		subsets[i].parent = i;
		subsets[i].rank = 0;
	}
	for (ll i = 1; i <= m; ++i) {
		scanf ("%lld%lld", &a, &b);
		Union(find(a), find(b));
	}
	for (ll i = 1; i <= n; ++i) {
		cnt[find(i)]++;
	}
	for (ll i = 1; i <= n; ++i) {
		if (cnt[i] > 0) {
			res = mul(res, cnt[i]) % MOD;
		}
	}
	printf("%lld\n", res);
	return 0;
}
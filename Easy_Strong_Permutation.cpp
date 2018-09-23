#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e5 + 5;
ll arr_max[maxn];
ll arr_min[maxn];
ll n, sum;
int main() {
	scanf ("%lld", &n);
	for (ll i = 0; i < n; ++i) {
		scanf ("%lld", &arr_min[i]);
		arr_max[i] = arr_min[i];
	}
	sort (arr_max, arr_max + n);
	sort (arr_min, arr_min + n, greater < ll > ());
	for (ll i = 0; i < n; ++i) {
		sum += abs(arr_max[i] - arr_min[i]);
	}
	printf("%lld\n", sum);
	return 0;
}
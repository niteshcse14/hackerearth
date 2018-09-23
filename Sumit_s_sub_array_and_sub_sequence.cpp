#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e5 + 5;
ll t, n, mx, ans, max_so_far, sum, max_ending_here;
ll arr[maxn];
bool flag;
int main () {
	scanf ("%lld", &t);
	while (t--) {
		flag = false;
		scanf ("%lld", &n);
		mx = -9999999999999;
		sum = 0;
		for (ll i = 0; i < n; ++i) {
			scanf ("%lld", &arr[i]);
			if (arr[i] > 0) {
				sum += arr[i];
				flag = true;
			}
			mx = max (mx, arr[i]);
		}
		max_ending_here = 0;
		max_so_far = -9999999999999;
		for (ll i = 0; i < n; ++i) {
			max_ending_here = max_ending_here + arr[i];
			if (max_so_far < max_ending_here) {
				max_so_far = max_ending_here;
			}
			if (max_ending_here < 0) {
				max_ending_here = 0; 
			}
		}
		printf("%lld %lld\n", max_so_far, flag ? sum : mx);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e6 + 5;
ll arr[maxn];
ll t, n, curr_max, sum;
int main () {
	scanf ("%lld", &t);
	while (t--) {
		sum = 0;
		scanf ("%lld", &n);
		for (int i = 0; i < n; ++i) {
			scanf ("%lld", &arr[i]);
			if (arr[i] > 0) {
				sum += arr[i];
			}
		}
		if (sum & 1) {
			printf("%lld\n", sum);
			continue;
		}
		curr_max = -9999999999;
		for (int i = 0; i < n; ++i) {
			if (arr[i] > 0) {
				if ((sum - arr[i]) & 1) {
					curr_max = max (curr_max, sum - arr[i]);
				}
			}
			else {
				if ((sum + arr[i]) & 1) {
					curr_max = max (curr_max, sum + arr[i]);
				}
			}
		}
		printf("%lld\n", curr_max);
	}
}
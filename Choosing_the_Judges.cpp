#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, data, sum, sum1, max_ending_here , max_so_far;
int main () {
	scanf ("%lld", &t);
	for (ll j = 1; j <= t; ++j) {
		scanf ("%lld", &n);
		scanf ("%d", &data);
		max_so_far = data;
		max_ending_here = 0;
		//printf("%lld  %lld\n", max_ending_here, max_so_far);
		for (int i = 1; i < n; ++i) {
			scanf ("%lld", &data);
			ll tt = max (max_so_far, max_ending_here);
			max_so_far = max (max_so_far, max_ending_here + data);
			max_ending_here = tt;
			//printf("%lld  %lld\n", max_ending_here, max_so_far);
		}
		printf("Case %lld: %lld\n", j, max_so_far);
	}
	return 0;
}
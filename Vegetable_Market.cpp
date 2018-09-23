#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long int
ll n, num, q, sum, left_sum, ans;
ll inp[maxn], pre[maxn];
ll solve(ll val) {
	ll lb = lower_bound(inp, inp + n, val) - inp;
	left_sum = 0;
	if (lb > 0) 
		left_sum = pre[lb - 1];
	ll tm = n - lb;
	//printf("%lld  %lld  %lld  %lld\n", lb, tm, left_sum, inp[lb]);
	return (left_sum + tm * val);
	//printf("upper bound of %lld   %lld\n", val, lb);
}
int main() {
	memset(inp, 0, sizeof inp);
	memset(pre, 0, sizeof pre);
	scanf("%lld", &n);
	for (ll i = 0; i < n; ++i) {
		scanf("%lld", &inp[i]);
		sum += inp[i];
	}
	sort(inp, inp + n);
	for (ll i = 0; i < n; ++i) {
		if (i > 0) pre[i] = pre[i - 1] + inp[i];
		else pre[i] = inp[i];
		//printf("%lld %lld\n", i, pre[i]);
	}
	scanf("%lld", &q);
	while (q--) {
		scanf("%lld", &num);
		if (num > sum) 
			printf("-1\n");
		else if(num <= n)
			printf("1\n");
		else {
			ll left = 1;
			ll right = 1e6;
			ans = LLONG_MAX;
			while (left <= right) {
				//if (left == right - 1) break;
				//printf("%lld %lld\n", left, right);
				ll mid = (left + right + 1) >> 1;
				ll val = solve(mid);
				//printf("solve  %lld  %lld\n", solve(mid), mid);
				if (val >= num) {
					right = mid - 1;
					ans = min(mid, ans);
				}
				else left = mid + 1;
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
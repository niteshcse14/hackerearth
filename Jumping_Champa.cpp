#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e3 + 5;
ll t, n, q;
ll h[maxn];
int main(){
	scanf("%lld", &t);
	while(t--){
		memset(h, 0, sizeof(h));
		scanf("%lld%lld", &n, &q);
		for(ll i = 0; i < n; ++i){
			scanf("%lld", &h[i]);
		}
		if(n == 1){
			printf("0\n");
			continue;
		}
		ll sum = 0;
		sort(h, h + n);
		for(ll i = 1; i < n; ++i){
			sum += q * abs(h[i] - h[i - 1]);
		}
		printf("%lld\n", sum);
	}
	return 0;
}
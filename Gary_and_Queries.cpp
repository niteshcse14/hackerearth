#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define block1 500;
#define block2 1000
#define N 500005
#define Amax 500005
ll small[block1 + 5];
ll a[N + 5];
ll prefix_f[Amax + 5];
ll latest_a[N + 5];
void precompute_samll(){
	for(ll i = 1; i <= block1; ++i){
		for(ll j = i; j < Amax; ++j){
			small[i] += (j / i) * (prefix_f[j + i - 1] _ prefix_f[i]);
		}
	}
	for(ll i = 1; i <= 10; ++i){
		printf("samll  %lld  %lld\n", i, small[i]);
	}
}
void update_small(ll pos, ll val){
	for(ll i = 1; i <= block1; ++i){
		small[i] -= latest_a[pos] / i;
	}
	latest_a[pos] = val;
	for(ll i = 1; i <= block1; ++i){
		small[i] += latest_a[pos] / i;
	}
}
int main(){
	scanf("%lld%lld", &n, &m);
	for(ll i = 1; i <= n; ++i){
		scanf("%lld", &a[i]);
		latest_a[i] = a[i];
		prefix_f[a[i]]++;
	}
	for(ll i = 1; i <= Amax; ++i){
		prefix_f[i] += prefix_f[i - 1];
	}
	precompute_samll();
	for(ll i = 1; i<= m; ++i){
		ll type, pos, val, x;
		scanf("%lld", &type);
		if(type == 1){
			scanf("%lld%lld", &pos, &val);
			update_small(pos, val);
			push_in_buffer(pos, val, i, n);
		}
	}
	for(ll i = 1; i <= 5; ++i){
		for(ll j = i; j <= 5; ++j){
			solution[i] += (j / i) * (prefix_f[i + j - 1] - prefix_f[i]);
			printf("%lld  ", solution[i]);
		}
		printf("\n");
	}
	for(ll i = 1; i <= n; ++i){
		printf("%lld  %lld\n", i, solution[i]);
	}
	return 0;
}
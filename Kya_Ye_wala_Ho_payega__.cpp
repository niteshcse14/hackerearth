#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll prefix[100000];
ll arr[100000];
ll n, q, r, l, data;
ll cnt2_divisors(ll num){
	ll cnt = 0;
	while(num % 2 == 0){
		cnt++;
		num /= 2;
	}
	return cnt;
}
int main(){
	scanf("%lld", &n);
	for(ll i = 0; i < n; ++i){
		scanf("%lld", &data);
		arr[i] = cnt2_divisors(data);
	}
	prefix[0] = arr[0];
	for(ll i = 1; i < n; ++i){
		prefix[i] = arr[i] + prefix[i - 1];
	}
	scanf("%lld", &q);
	while(q--){
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", prefix[r - 1] - prefix[l - 2]);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e5 + 5;
ll isPrime[maxn];
ll ans[maxn];
ll arr[maxn];
ll cnt[maxn];
ll N, ANS = 0;
ll _gcd(ll a, ll b){
	if(a == 0){
		return b;
	}
	else{
		return _gcd(b % a, a);
	}
}
int main(){
	scanf("%lld", &N);
	for(ll i = 0; i < N; ++i){
		scanf("%lld", &arr[i]);
		cnt[arr[i]]++;
	}
	for(ll i = 2; i < 3001; ++i){
		if(cnt[i] > 1){
			ll temp = 0;
			for(ll j = 2; j < i; ++j){
				if(cnt[j] && _gcd(i, j) > 1){
					temp += cnt[j];
				}
			}
			temp *= cnt[i];
			ANS += temp += (cnt[i] * (cnt[i] - 1)) / 2;
		}
	}
	printf("%lld\n", ANS);
}
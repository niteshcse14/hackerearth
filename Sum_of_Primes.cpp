#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN = 1e6 + 5;
ll isPrime[MAXN];
ll ans[MAXN];
ll N, l, r;
void init()
{
	for(ll i = 4; i < MAXN; i += 2){
		isPrime[i] = 1;
	}
	for(ll i = 3; i * i < MAXN; i += 2){
		if(!isPrime[i]){
			for(ll j = i * i; j < MAXN; j += i){
				isPrime[j] = 1;
			}
		}
	}
	isPrime[1] = 1;
	ans[0] = 0;
	ans[1] = 0;
	ans[2] = 2;
	for(ll i = 3; i < MAXN; ++i){
		ans[i] = ans[i - 1];
		if(!isPrime[i]){
			ans[i] += i;
		}
	}
	//printf("\n");
}
int main(){
	init();
	scanf("%lld", &N);
	while(N--)
	{
		scanf("%lld %lld", &l, &r);
		printf("%lld\n", (ans[r] - ans[l - 1]));
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll N = 1000005;
ll is[N];
ll arr[N];
ll choose[1005][1005];
ll mul(ll a, ll b, ll mod) {return (a * b) % mod;}
ll add(ll a, ll b, ll MOD)
{
	a += b;
	if(a >= MOD)
	{
		a -= MOD;
	}
	if(a < 0)
	{
		a += MOD;
	}
	return a;
}
void seive()
{
	is[1] = 1;
	for(ll i = 2; i < N; i++)
	{
		if(!is[i])
		{
			for(ll j = i * i; j < N; j += i)
			{
				is[j] = 1;
			}
		}
	}
}
void pre(ll MOD)
{
	choose[0][0] = 1;
	for(int i = 1; i <= 1004; i++)
	{
		choose[i][0] = 1;
		choose[i][1] = i;
	}
	for(int i = 2; i <= 1004; i++)
	{
		for(int j = 2; j <= 1004; j++)
		{
			if(j > i)
			{
				break;
			}
			choose[i][j] = add(choose[i - 1][j], choose[i - 1][j - 1], MOD);
		}
	}
}
ll power(ll a, ll b, ll mod)
{
    if(b == 0) return 1;
    if(b == 1) return a % mod;
    ll x = power(a, b / 2, mod);
    x = mul(x, x, mod);
    if(b % 2)
    {
        return mul(x, a, mod);
    }
    return x;
}
int main()
{
	ll MOD1 = 1000000007;
	ll mod2 = 1000000006;
	seive();
	pre(mod2);
	ll T, N, primes, noprimes;
	scanf("%lld", &T);
	while(T--)
	{
		primes = noprimes = 0;
		scanf("%lld", &N);
		for(int i = 0; i < N; i++)
		{
			scanf("%lld", &arr[i]);
			primes += !is[arr[i]];
		}
		noprimes = N - primes;
		ll ans = 1;
		ll c = 0;
		for(ll i = 0; i <= noprimes; ++i){
			c = add(c, choose[noprimes][i], mod2);
		}
		for(int i = 0; i <= primes; i++)
		{
			ll possible = mul(c, choose[primes][i], mod2);
			ll curr = power(i + 2, possible, MOD1);
			ans = mul(ans, curr, MOD1);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
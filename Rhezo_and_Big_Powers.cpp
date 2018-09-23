#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = (ll) (1e9 + 7);
ll A, B;
inline ll scanLongMod(ll MOD) 
{
	ll N = 0;
 	char ch = getchar_unlocked();
 	ll sign = 1;
 	while(ch < '0' || ch > '9') 
 	{
  		if(ch == '-') sign = -1;
  		ch = getchar_unlocked();
 	}
 	while(ch >= '0' && ch <= '9') 
 	{
  		N = (N << 1) + (N << 3) + (ll)(ch - '0');
  		N = (N % MOD);
  		ch = getchar_unlocked();
 	}
 	return N * sign;
}
ll power()
{
	ll ans = 1;
	A %= MOD;
	B %= MOD;
	while(B > 0)
	{
		if(B % 2 != 0)
		{
			ans = (ans * A) % MOD;
		}
		B >>= 1;
		A = (A * A) % MOD;
	}
	return ans;
}
int main()
{
	//scanf("%lld %lld", &A, &B);
	A = scanLongMod(MOD);
	B = scanLongMod(MOD - 1);
	printf("%lld\n", power() % MOD);
	return 0;
}
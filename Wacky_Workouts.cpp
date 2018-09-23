#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int MOD = 1000000007;
void multiply(ll F[2][2], ll M[2][2])
{
  ll x =  F[0][0] * M[0][0] + F[0][1] * M[1][0];
  ll y =  F[0][0] * M[0][1] + F[0][1] * M[1][1];
  ll z =  F[1][0] * M[0][0] + F[1][1] * M[1][0];
  ll w =  F[1][0] * M[0][1] + F[1][1] * M[1][1];
 
  F[0][0] = x % MOD;
  F[0][1] = y % MOD;
  F[1][0] = z % MOD;
  F[1][1] = w % MOD;
}
void power(ll F[2][2], ll N)
{
	if(N == 0 || N == 1)
	{
		return;
	}
	power(F, N / 2);
	multiply(F, F);
	ll M[2][2] = {{1, 1}, {1, 0}};
	if(N % 2 != 0)
	{
		multiply(F, M);
	}
}
ll fib(ll N)
{
	ll F[2][2] = {{1, 1}, {1, 0}};
	power(F, N + 1);
	return F[0][0] % MOD;
}
int main()
{
	ll T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		cout << fib(N) << "\n";
	}
	return 0;
}
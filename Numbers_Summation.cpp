#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = 1e9 + 7;
ll n, N, sum, temp, temp1, s;
ll power(ll a, ll b) {
	a %= MOD;
	b %= MOD;
	ll res = 1;
	while (b > 0) {
		if (b & 1) {
			res = (res * a) % MOD;
		}
		b >>= 1;
		a = (a * a) % MOD;
	}
	return res;
}
inline ll mult(ll a , ll b) { 
	ll x = a; x *= ll(b); 
	if(x >= MOD) {
		x %= MOD; 
	}
	return x; 
}
inline ll add(ll a , ll b) { 
	return a + b >= MOD ? a + b - MOD : a + b; 
}
inline ll sub(ll a , ll b) { 
	return a - b < 0 ? MOD - b + a : a - b; 
}
ll inv;
inline ll get(ll x) {
  x = x % MOD;
  return mult(mult(x , x + 1), inv);
}
inline ll get(ll l , ll r) {
  return sub(get(r) , get(l-1));
}
int main() {
	scanf("%lld", &N);
	ll i = 1, start,  x, end;
	inv = power(2, MOD - 2);
	sum = 0;
	while (i <= N) {
		start = i;
		x = N / i;
		end = N / x;
		x = get(x);
		i = end + 1;
		sum = add(sum, mult(get(start, end), x));
		//printf("i   ==   %lld\n", i);
	}
	printf("%lld\n", sum % MOD);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e5 + 5;
ll n, sum;
ll arr[maxn], dp[505][101][101];
const ll MOD = 1e9 + 7;
ll gcd (ll a, ll b) {
	if (a == 0) return b;
	return gcd (b % a, a);
}
ll solve (ll i, ll val, ll g) {
	if (i == n) {
		return (g == 1);
	}
	if (dp[i][val][g] != -1) return dp[i][val][g];
	ll res = 0;
	res = solve (i + 1, val, g);
	if (arr[i] > val) {
		res = res + solve (i + 1, arr[i], gcd (g, arr[i]));
	}
	dp[i][val][g] = res;
	return res;
}
int main(){
	freopen ("in.txt", "r", stdin);
	scanf("%lld", &n);
	for(ll i = 0; i < n; ++i){
		scanf("%lld", &arr[i]);
	}
	memset (dp, -1, sizeof (dp));
	sum = 0;
	for (int i = 0; i < n; ++i) {
		sum = sum % MOD + solve (i + 1, arr[i], arr[i]) % MOD;
	}
	printf("%lld\n", sum % MOD);
	return 0;
}
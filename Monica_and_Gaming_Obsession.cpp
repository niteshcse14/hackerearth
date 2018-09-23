#include <bits/stdc++.h>
using namespace std;
typedef long long int ll; 
ll dp[100005];
int main(){
	ll n;
	scanf("%lld", &n);
	dp[0] = 1;
	dp[1] = 2;
	ll i = 1;
	while(dp[i] <= n){
		dp[++i] = dp[i - 1] + dp[i - 2];
	}
	printf("%lld\n", i - 1);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = 1e9 + 7;
ll n, data, res;
int main(){
	res = 1;
	scanf("%lld", &n);
	for(int i = 0; i < n; ++i){
		scanf("%lld", &data);
		res = (res * (data + 1) % MOD) % MOD;
	}
	printf("%lld\n", res - 1);
	return 0;
}
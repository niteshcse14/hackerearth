#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	string str;
	ll n, result = 0;
	cin >> str;
	vector < ll > cnt1(10, 0);
	scanf("%lld", &n);
	for(ll i = 0; i < n; ++i){
		ll x;
		scanf("%lld", &x);
		cnt1[x] = 1;
	}
	for(ll i = 0; i < str.size(); ++i){
		ll cnt = 0;
		vector < ll > cnt2;
		cnt2 = cnt1;
		for(ll j = i; j < str.size(); ++j){
			if(cnt2[str[j] - '0'] == 1){
				cnt++;
				cnt2[str[j] - '0'] = 0;
			}
			if(cnt == n){
				result += str.size() - j;
				break;
			}
		}
	}
	printf("%lld\n", result);
	return 0;
}
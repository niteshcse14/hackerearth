#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
const ll maxn = 1e6 + 5;
ll n;
ll arr[maxn];
ll add, mul, sum;
int main(){
	sum = 0;
	scanf("%llu", &n);
	for(ll i = 0; i < n; ++i){
		scanf("%llu", &arr[i]);
	}
	for(ll i = 0; i < n; ++i){
		for(ll j = i + 1; j < n; ++j){
			//mul = arr[i] * arr[j];
			//add = arr[i] + arr[j];
			for(ll k = j + 1; k < n; ++k){
				//printf("%llu  %llu   %llu\n", arr[i], arr[j], arr[k]);
				mul = arr[i] * arr[j] * arr[k];
				add = arr[i] + arr[j] + arr[k];
				sum += add / mul;
			}
		}
	}
	printf("%llu\n", sum);
	return 0;
}
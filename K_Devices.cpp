#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN = 1e5 + 5;
ll arr[MAXN];
ll x_arr[MAXN];
ll y_arr[MAXN];
ll N, K;
int main()
{
    scanf("%lld%lld", &N, &K);
    for(ll i = 0; i < N; ++i){
        scanf("%lld", &x_arr[i]);
    }
    for(ll i = 0; i < N; ++i){
        scanf("%lld", &y_arr[i]);
    }
    for(ll i = 0; i < N; ++i){
        ll temp =  pow(x_arr[i], 2) + pow(y_arr[i] * 1LL, 2);
        arr[i] = ceil(sqrt(temp));
    }
    sort(arr, arr + N);
    cout << arr[K - 1] << "\n";
   return 0;
}
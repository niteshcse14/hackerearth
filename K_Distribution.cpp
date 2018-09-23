#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = 1000000007;
int main()
{
	ll N, K, ans = 0, sum = 0, Total = 0;
	scanf("%lld %lld", &N, &K);
	ll arr[N];
	for(int i = 0; i < N; i++)
	{
		scanf("%lld", &arr[i]);
		Total += arr[i];
	}
	for(int i = 0; i < (1 << N); i++)
	{
		sum = 0;
		for(int j = 0; j < N; j++)
		{
			if(j & i)
			{
				sum += arr[j];
			}
		}
		if((sum >= K) && ((Total - sum) >= K))
		{
			ans++;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
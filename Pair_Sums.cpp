#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll hash_table[2000005];
ll arr[1000005];
int main()
{
	ll N, K;
	scanf("%lld %lld", &N, &K);
	memset(hash_table, 0, sizeof(hash_table));
	for(int i = 0; i < N; i++)
	{
		scanf("%lld", &arr[i]);
	}
	bool flag = 0;
	sort(arr, arr + N);
	for(int i = 0; i < N; i++)
	{
		ll diff = K - arr[i];
		if(diff >= 0 && hash_table[diff])
		{
			printf("YES\n");;
			return 0;
		}
		hash_table[arr[i]] = 1;
	}
	printf("NO\n");
	return 0;
}
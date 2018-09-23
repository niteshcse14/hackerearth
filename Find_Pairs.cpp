#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll hash_table[1000005];
int main()
{
	ll T, N, data, ans;
	scanf("%lld", &T);
	while(T--)
	{
		memset(hash_table, 0, sizeof(hash_table));
		ans = 0;
		scanf("%lld", &N);
		for(int i = 0; i < N; i++)
		{
			scanf("%lld", &data);
			hash_table[data]++;
			ans += hash_table[data];
		}
		printf("%lld\n", ans);
	}
	return 0;
}
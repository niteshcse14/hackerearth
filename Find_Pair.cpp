#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll hash_table[100005];
int main()
{
	ll N, count = 0, data;
	scanf("%lld", &N);
	for(ll i = 0; i < N; i++)
	{
		scanf("%lld", &data);
		hash_table[data]++;
	}
	for(ll i = 0; i < 100005; i++)
	{
		count += ((hash_table[i]) * (hash_table[i] - 1)) / 2;
	}
	printf("%lld\n", count);
	return 0;
}
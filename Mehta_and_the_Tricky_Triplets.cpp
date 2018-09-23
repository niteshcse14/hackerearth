#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define MAX 100005
vector<int> prime;
int SPF[MAXN];
int P[MAXN];
int isprime[MAXN];
void init()
{
	memset(isprime, 1, sizeof(isprime));
	memset(P, 0, sizeof(P));
	isprime[0] = isprime[1] = 0;
	for(int i = 2; i < MAXN; i++)
	{
		if(isprime[i])
		{
			prime.push_back(i);
			SPF[i] = i;
		}
		for(int j = 0; j < prime.size() && i * prime[j] < MAXN && prime[j] <= SPF[i]; j++)
		{
			isprime[i * prime[j]] = 0;
			SPF[i * prime[j]] = SPF[j];
		}
	}
	for(int i = 0; i < prime.size(); i++)
	{
		P[prime[i]] = 1;
	}
}
int main()
{
	init();
	ll N, data;
	scanf("%lld", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%lld", &data);
		if(arr[data])
		{
			count++;
		}
	}
	printf("%d\n", nCr[N - count]);
	return 0;
}
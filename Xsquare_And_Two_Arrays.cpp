#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAX = 100005;
ll A[MAX];
ll B[MAX];
ll N, Q, sum_a, sum_b, data, type, l, r;
int main()
{
	A[0] = B[0] = 0;
	scanf("%lld %lld", &N, &Q);
	for(int i = 1; i <= N; i++)
	{
		scanf("%lld", &A[i]);
	}
	for(int i = 1; i <= N; i++)
	{
		scanf("%lld", &B[i]);
	};
	for(int i = 2; i <= N; i += 2)
	{
		swap(B[i], A[i]);
	}
	for(int i = 1; i <= N; i++)
	{
		A[i] += A[i - 1];
		B[i] += B[i - 1];
	}
	while(Q--)
	{
		scanf("%lld %lld %lld", &type, &l, &r);
		if(type == 1)
		{
			if(l % 2)
			{
				printf("%lld\n", A[r] - A[l - 1]);
			}
			else
			{
				printf("%lld\n", B[r] - B[l - 1]);
			}
		}
		else
		{
			if(l % 2 == 0)
			{
				printf("%lld\n", A[r] - A[l - 1]);
			}
			else
			{
				printf("%lld\n", B[r] - B[l - 1]);
			}
		}
	}
	return 0;
}
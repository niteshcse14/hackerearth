#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll Total, ans, N, T;
int main()
{
	bool flag = false;
	for(int i = 0; i < 32; i++)
	{
		Total += 1 << i;
	}
	scanf("%lld", &T);
	while(T--)
	{
		flag = false;
		scanf("%lld", &N);
		ll arr[N];
		for(int i = 0; i < N; i++)
		{
			scanf("%lld", &arr[i]);
		}
		if(N == 1)
		{
			if(arr[0] && (!(arr[0] & arr[0] - 1)))
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
			continue;
		}
		for(int i = 0; i < 32; i++)
		{
			ans = Total;
			for(int j = 0; j < N; j++)
			{
				if(arr[j] & (1 << i))
				{
					ans &= arr[j];
				}
			}
			if(ans && !(ans & (ans - 1)))
			{
				flag = true;
				break;
			}
		}
		if(flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
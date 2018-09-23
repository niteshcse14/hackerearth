#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, count_odd, count_even;
	scanf("%d", &T);
	while(T--)
	{
		count_even = count_odd = 0;
		scanf("%d", &N);
		int arr[N], dp[2][N];
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &arr[i]);
			if((arr[i] & 1))
			{
				dp[1][i] = ++count_odd;
			}
			else
			{
				dp[1][i] = count_odd;
			}
			if(!(arr[i] & 1))
			{
				dp[0][i] = ++count_even;
			}
			else
			{
				dp[0][i] = count_even;
			}
		}
		/*
		for(int i = 0; i < N; i++)
		{
			printf("%d   ", dp[0][i]);
		}
		printf("\n");
		for(int i = 0; i < N; i++)
		{
			printf("%d   ", dp[1][i]);
		}
		printf("\n");
		long long sum = 0;
		for(int i = 0; i < N  - 1; i++)
		{
			sum += (dp[0][N - 1] - dp[0][i]) * (dp[1][N - 1] - dp[1][i]);
			printf("%d\n", sum);
		}
		*/
		printf("%lld\n", dp[0][N - 1] * dp[1][N - 1]);
	}
	return 0;
}
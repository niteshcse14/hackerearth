#include <bits/stdc++.h>
using namespace std;
int dp[10000];
int main()
{
	int arr[10005];
	for(int i = 1; i <= 10000; i++)
	{
		arr[i] = 1;
	}
	for(int i = 2; i <= 10000; i++)
	{
		if(arr[i])
		{
			for(int j = i * i; j <= 10000; j += i)
			{
				arr[j] = 0;
			}
		}
	}
	vector<int> prime;
	arr[4] = 1;
	arr[27] = 1;
	arr[3125] = 1;
	prime.push_back(2);
	prime.push_back(3);
	prime.push_back(4);
	for(int i = 5; i < 10000; i += 2)
	{
		if(arr[i] || i == 27 || i == 3125)
		{
			prime.push_back(i);
		}
	}
	dp[2] = 1;
	dp[3] = 1;
	for(int i = 4; i <= 10000; i++)
	{
		dp[i] = INT_MAX;
		if(arr[i])
		{
			dp[i] = 1;
			continue;
		}
		else
		{
			for(int j = 0; j < prime.size(); j++)
			{
				if((i - prime[j]) < 2)
				{
					break;
				}
				dp[i] = min(dp[i], dp[i - prime[j]] + 1);
			}
		}
	}
	int T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		cout << dp[N] << "\n";
	}
	return 0;
}
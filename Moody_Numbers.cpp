#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool check[11] = {false, true, true, false, true, false, false, false, true, false, true};
int digits_sum(ll N)
{
	int sum = 0;
	while(N > 0)
	{
		sum += N % 10;
		N /= 10;
	}
	return sum;
}
/*
bool moody(int N, bool dp[])
{
	if(N == 1 || N == 4)
	{
		return true;
	}
	int digit = digits_sum(N);
	dp[N] = moody(digit  * digit, dp);
	return dp[N];
}
*/
int main()
{
	int T, N;
	/*
	bool arr[73];
	for(int i = 1; i <= 72; i++)
	{
		arr[i] = false;
	}
	arr[1] = arr[4] = true;
	arr[3] = false;
	*/
	/*
	for(int i = 1; i <= 72; i++)
	{
		while(!arr[i])
		if()
		{
			arr[i] = true;
			cout << i << "  true\n";
		}
		else
		{
			arr[i] = false;
			cout << i << "  false\n";
		}
	}
	*/
	cin >> T;
	while(T--)
	{
		scanf("%d", &N);
		int itr = 5;
		bool flag = false;
		while(itr--)
		{
			flag = (N == 4 || N == 1);
			if(flag)
			{
				break;
			}
			N = digits_sum(1ll * N * N);
		}
		puts(ok ? "YES" : "NO");
		/*
		if(arr[digits_sum(N)])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		*/
	}
	return 0;
}
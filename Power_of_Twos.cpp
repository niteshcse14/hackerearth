#include <bits/stdc++.h>
using namespace std;
int N = 1e6 + 1, T;
int arr[1000001];
int main()
{
	for(int i = 2; i <= N; i++)
	{
		for(int j = 2 * i; j <= N; j += i)
		{
			arr[j]++;
		}
	}
	for(int i = 2; i <= N; i++)
	{
		arr[i] += arr[i - 1] + 1;
	}
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		printf("%d\n", arr[N]);
	}
	return 0;
}
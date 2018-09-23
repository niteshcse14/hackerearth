#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	scanf("%d", &N);
	int arr[N];
	for(int i = 1; i <= N; i++)
	{
		arr[i - 1] = i;
	}
	for(int i = 0; i < N; i++)
	{
		int sum = 0;
		for(int j = 0; j < N; j++)
		{
			if(arr[i] & arr[j] == arr[i])
			{
				sum++;
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
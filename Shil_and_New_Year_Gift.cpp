#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	scanf("%d", &N);
	int arr[N];
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	for(int i = 0; i < (int)pow(2, N); i++)
	{
		for(int j = 0; j < N; j++)
		{
			if((i & (1 << j)) > 0)
			{
				printf("%d ", arr[j]);
			}
		}
		printf("\n");
	}
	return 0;
}
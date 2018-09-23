#include <bits/stdc++.h>
using namespace std;
int main()
{
	int arr[32];
	int T, N, data;
	scanf("%d", &T);
	while(T--)
	{
		memset(arr, 0, sizeof(arr));
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &data);
			//printf("AT %d \n", i);
			for(int j = 0; j < 32; j++)
			{
			    if((data  & (1 << j)))
			    {
			        arr[j]++;
			    }
				//printf("%d   ", arr[j]);
			}
			//printf("\n");
		}
		int M = -1, ans;
		for(int i = 0; i < 32; i++)
		{
			//printf("%d  ", arr[i]);
			if(arr[i] > M)
			{
				M = arr[i];
				ans = i;
			}
		}
		//printf("\n");
		printf("%d\n", ans);
	}
	return 0;
}
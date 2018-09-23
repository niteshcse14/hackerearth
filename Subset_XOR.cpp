#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, data, ans;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &data);
			if(i == 0)
			{
				ans = data;
			}
		}
		if(N == 1)
		{
			printf("%d\n", ans);
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
int main()
{
	int T, N, ans;
	char str[MAX];
	scanf("%d", &T);
	while(T--)
	{
		ans = 0;
		scanf("%d %s", &N, str);
		for(int i = 0; i < N; i++)
		{
			if(str[i] == '0')
			{
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, a, b, sum, N;
	scanf("%d", &T);
	while(T--)
	{
		sum = 0;
		bool flag = true;
		string str;
		cin >> str;
		N = str.length();
		cin >> a >> b;
		if(N % 2 != 0)
		{
			printf("-1\n");
		}
		else
		{
			for(int i = 0; i < N / 2; i++)
			{
				//printf("%c   %c   ", str[i], str[N - 1 - i]);
				if(str[i] == str[N - 1 - i] && str[i] != '/')
				{
					//printf("%d\n", sum);
					continue;
				}
				else if(str[i] == '/' || str[N - 1 - i] == '/')
				{
					if(str[i] == str[N - i - 1])
					{
						sum += 2 * min(a, b);
					}
					else if(str[i] == '/')
					{
						if(str[N - 1 - i] == 'a')
						{
							sum += a;
						}
						else
						{
							sum += b;
						}
					}
					else if(str[N - 1 - i] == '/')
					{
						if(str[i] == 'a')
						{
							sum += a;
						}
						else
						{
							sum += b;
						}
					}
				}
				else
				{
					flag = false;
					break;
				}
				//printf("%d\n", sum);
			}
		}
		if(!flag)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", sum);
		}
	}
	return 0;
}
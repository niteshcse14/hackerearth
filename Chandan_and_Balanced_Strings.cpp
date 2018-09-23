#include <bits/stdc++.h>
using namespace std;
int const MAX = 1e5 + 5;
char str[MAX];
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", str);
		int N = strlen(str);
		int arr[N];
		memset(arr, -1, N);
		int sum = 0;
		for(int i = 0; i < N; i++)
		{
			sum ^= (int)(str[i] - 97 + 1);
			arr[i] = sum;
		}
		int count = 0;
		sort(arr, arr + N);
		for(int i = 0; i < N; i++)
		{
			//printf("%d   %d\n", arr[i], (int)(str[i] - 97 + 1));
			if(arr[i] == 0)
			{
				count++;
			}
			else
			{
				break;
			}
		}
		count++;
		printf("%d\n", count * (count - 1) / 2);
	}
	return 0;
}
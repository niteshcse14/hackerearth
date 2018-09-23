#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	string str;
	scanf("%d", &T);
	while(T--)
	{
		cin >> str;
		int ans = 0;
		for(int i = 0; i < str.size() - 1; i++)
		{
			ans ^= ((int)(str[i] - 97) + 1);
		}
		if((ans ^ ((int)(str[str.size() - 1] - 97) + 1)) == 0)
		{
			printf("1\n");
		}
		else
		{
			printf("-1\n");//, sum);
		}
	}
	return 0;
}
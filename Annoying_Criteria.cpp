#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	int fac[1000];
	fac[0] = 0;
	fac[1] = 1;
	for(int i = 2; i < 1000; i++)
	{
		fac[i] = 1;
	}
	for(int i = 2; i < 1000; i++)
	{
		for(int j = i; j < 1000; j += i)
		{
			fac[j] += 1;
		}
	}
	string str;
	scanf("%d", &T);
	while(T--)
	{
		int count = 0;
		cin >> str;
		for(int i = 0; i < str.size(); i++)
		{
			int pos = (int)str[i];
			if((int)str[i] > 96)
			{
				//printf("%d\n", (str[i] - 'a' + 1));
				count += str[i] - 'a' + 1;
			}
			else
			{
				//printf("%d\n", (str[i] - 'A' + 1));
				count += str[i] - 'A' + 1;
			}
		}
		//printf("%d %d\n", count, fac[count]);
		if(fac[count] >= str.size())
		{
			printf("IN\n");
		}
		else
		{
			printf("OUT\n");
		}

	}
}
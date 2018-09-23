#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int N = str.size();
	for(int i = 0; i < N; i++)
	{
		if(str[i] == '?')
		{
			if((i > 0 && str[i - 1] == 'a') || (i + 1 < N && str[i + 1] == 'a'))
			{
				str[i] = 'b';
			}
			else
			{
				str[i] = 'a';
			}
		}
	}
	cout << str << "\n";
	return 0;
}
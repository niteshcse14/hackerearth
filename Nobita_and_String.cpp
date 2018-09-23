#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, j;
	string str, temp;
	scanf("%d", &T);
	T++;
	while(T--)
	{
		j = 0;
		getline(cin, str);
		string arr[str.length()];
		for(int i = 0; i < str.length(); i++)
		{
			temp = "";
			while(str[i] != ' ' && i < str.length())
			{
				temp += str[i];
				i++;
			}
			arr[j++] = temp;
		}
		for(int i = j - 1; i >= 0; i--)
		{
			cout << arr[i] << " ";
		}
		printf("\n");
	}
	return 0;
}
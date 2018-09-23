#include <bits/stdc++.h>
using namespace std;
bool palindrome(string str, int start, int end)
{
	for(int i = 0; i < (end - start); i++)
	{
		if(str[start + i] != str[end - i])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int count = 0;
	string str;
	cin >> str;
	for(int i = 0; i < str.size(); i++)
	{
		for(int j = i; j < str.size(); j++)
		{
			//cout << i << "  " << j << "\n";
			if(palindrome(str, i, j))
			{
				count++;
			}
		}
	}
	cout << count << "\n";
	return 0;
}
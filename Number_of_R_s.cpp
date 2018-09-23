#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, count;
	string str;
	cin >> T;
	while(T--)
	{
		count = 0;
		cin >> str;
		int arr[str.size()];
		for(int i = 0; i < str.size(); i++)
		{
			if(str[i] == 'R')
			{
				arr[i] = -1;
				count++;
			}
			else
			{
				arr[i] = 1;
			}
		}
		int max_ending_hete = 0, max_so_far = INT_MIN;
		for(int i = 0; i < str.size(); i++)
		{
			max_ending_hete  += arr[i];
			if(max_so_far < max_ending_hete)
			{
				max_so_far = max_ending_hete;
			}
			if(max_ending_hete < 0)
			{
				max_ending_hete = 0;
			}
		}
		if(count == str.size())
		{
			count -= 1;
		}
		cout << (max_so_far + count) << "\n";
	}
	return 0;
}
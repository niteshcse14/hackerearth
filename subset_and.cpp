#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, N, Z;
	cin >> T;
	while(T--)
	{
		cin >> Z >> N;
		int arr, sum;
		sum = Z;
		for(int i = 0; i < N; i++)
		{
			cin >> arr;
			sum = arr & arr;
		}
		if(sum == 0)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int bit_size(int N)
{
	int count = 0;
	while(N)
	{
		count++;
		N >>= 1;
	}
	return count;
}
int main()
{
	int N, T;
	scanf("%d", &N);
	int arr[N], lengths[N];
	vector<int> buckets[65];
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		buckets[bit_size(arr[i])].push_back(arr[i]);
	}
	int modified_arr[100];
	int index = 0;
	for(int i = 64; i > 0; i--)
	{
		if(buckets[i].size())
		{
			modified_arr[index++] = buckets[i][0];
			for(int j = 1; j < buckets[i].size(); j++)
			{
				int temp = buckets[i][0] ^ buckets[i][j];
				int len = bit_size(temp);
				buckets[len].push_back(temp);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < index; i++)
	{
		if(ans < (ans ^ modified_arr[i]))
		{
			ans = ans ^ modified_arr[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}
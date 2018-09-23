#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long T;
	scanf("%lld", &T);
	while(T--)
	{
		unsigned long long N;
		scanf("%lld", &N);
		unsigned long long arr[26];
		for(int i = 0; i < 26; i++)
		{
			scanf("%lld", &arr[i]);
		}
		const unsigned long long total_points = N * 12;
		const unsigned long long div = total_points / 26;
		const unsigned long long rem = total_points - 26 * div;
		unsigned long long rem_sum = 0;
		unsigned long long *f = new unsigned long long[26];
		for(int i = 0; i < 26; i++)
		{
			f[i] = div;
			if(i < rem)
			{
				f[i]++;
			}
		}
		unsigned long long sum = 0;
		for(int i = 0; i < 26; i++)
		{
			sum += f[i] * arr[i] + f[i] * (f[i] - 1) / 2;
		}
		printf("%llu\n", sum);
	}
	return 0;
}
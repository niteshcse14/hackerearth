#include <bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	scanf("%d", &N);
	int arr[N];
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	int odd_sum = 0;
	int even_sum = 0;
	int odd = 0, even = 0;
	for(int i = 0; i < N; i++)
	{
		if(arr[i] % 2 == 0)
		{
			odd_sum += odd;
			even_sum += even;
			even++;
		}
		else
		{
			odd_sum += even;
			even_sum += odd;
			odd++;
		}
	}
	printf("%d\n", abs(odd_sum - even_sum));
	return 0;
}
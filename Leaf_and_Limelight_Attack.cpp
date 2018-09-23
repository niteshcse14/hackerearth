#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const long long MAX = 1e7 + 5;
ll MOD = 1e9 + 9;
long long arr[MAX];
int main()
{
	long long T, N;
	long long x;
	arr[0] = 0;
	arr[1] = 1;
	for(long long i = 2; i < MAX; i++)
	{
		x = (i * i) % MOD;
		arr[i] = arr[i - 2] + 4 * x - 6 * (i - 1);
		arr[i] %= MOD;
		if(arr[i] < 0)
		{
			arr[i] += MOD;
		}
	}
	cin >> T;
	//scanf("%lld", &T);
	while(T--)
	{
		cin >> N;
		cout << arr[N] << "\n";
		//scanf("%lld", &N);
		//printf("%lld\n", &arr[N]);
	}
	return 0;
}
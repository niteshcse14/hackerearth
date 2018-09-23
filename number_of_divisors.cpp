#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll number_of_divisor(ll N)
{
	ll ans = 1;
	ll count = 0;
	for(ll i = 2; i * i <= N; i++)
	{
		count = 0;
		if(N % i == 0)
		{
			while(N % i == 0)
			{
				N = N / i;
				count++;
			}
		}
		ans = ans * (count + 1);
	}
	if(N != 1)
	{
		ans = ans * 2;
	}
	return ans;
}
int main()
{
	ll T, N;
	cin >> T;
	while(T--)
	{
		cin >> N;
		cout << number_of_divisor(N) << "\n";;
	}
	return 0;
}
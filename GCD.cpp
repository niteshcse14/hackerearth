#include <bits/stdc++.h>
using namespace std;
class GCD
{
	int *arr;
	int N;
public:
	GCD(int N);
	int getGCD(int a, int b);
	int findRangeGcd(int arr[], int l, int r);
};
GCD::GCD(int N)
{
	this->N = N;
	arr = new int[N];
}
GCD::getGCD(int a, int b)
{
	if(a == 0)
	{
		return b;
	}
	return getGCD(b % a, a);
}
GCD::findRangeGcd(int arr[], int l, int r)
{
	for(l += N, r += N; l < r; l >>= 1, r >>= 1)
	{
		if(l & 1)
		{
			if()
		}
	}
}
int main()
{
	int T, N, count, K;
	T = 1;
	//cin >> T;
	while(T--)
	{
		bool check = false;
		int flag = 0;
		count = 0;
		cin >> N >> K;
		int arr[2 * N] = { 0 };
		for(int i = 0; i < N; i++)
		{
			cin >> arr[N + i];
			if(arr[N + i] % K == 0)
			{
				check = true;
			}
			if(arr[N + i] == K)
			{
				flag = 1;
			}
		}
		if(!check)
		{
			count << "-1\n";
		}
		else if(flag == 1)
		{
			cout << "1\n";
		}
		else
		{
			for(int i = N - 1; i > 0; i--)
			{
				arr[i] = getGCD(arr[i << 1], arr[i << 1 | 1]);
			}
			
			int res = N + 1;
    		for (int i = 0; i < N - 1; i++)
    		{
        		if (arr[i] % K != 0)
                {
                   	continue;
                }
        		int low = i + 1;
        		int high = n - 1;
        		int closest = 0;
        		while (true)
        		{
            		int mid = low + (high - low) / 2;
            		int gcd = findRangeGcd(i, mid, arr, n);
			        if (gcd > k)
			        {
			            low = mid;
			        }
			        else if (gcd == k)
			        {
			            high = mid;
			            closest = mid;
			            break;
			        }
			        else
			        {
			           high = mid;
			        }
			        if (abs(high - low) <= 1)
			        {
			            if (findRangeGcd(i, low, arr, n) == k)
			            {
			                  closest = low;
			            }
			            else if (findRangeGcd(i, high, arr, n) == k)
			            {
			                closest = high;
			            }
			            break;
			        }
			    }
				if (closest != 0)
				{
			            res = min(res, closest - i + 1);
				}
			}
		    return (res == n+1) ? -1 : res;
		}
	}
	return 0;
}
//GCD.cpp
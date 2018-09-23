#include <bits/stdc++.h>
using namespace std;
const int MAX1 = 100005, MAX = 500005;
const long long int MOD = 1e7 + 7;
long long int arr[MAX], ans[MAX];
void pre()
{
	for(int i = 0; i < MAX; i++)
	{
		arr[i] = i;
	}
	for(int i = 2; i < MAX; i++)
	{
		if(arr[i] == i)
		{
			arr[i] = i - 1;
			for(int j = 2 * i; j < MAX; j += i)
			{
				arr[j] -= (arr[j] / i);
			}
		}
	}
	int k;
	for(int i = 1; i < MAX; i++)
	{
		for(int j = i, k = 1; j < MAX; j += i, k++)
		{
			ans[j] += i * arr[k];
		}
	}
}
void update(int *st, int val, int index)
{
	if(index < 1)
	{
		return;
	}
	st[index] += val;
	update(st, val, (index - 1) / 2);
}
int build(int *st, int arr[], int ss, int se, int si, int N)
{
	if(ss == se)
	{
		st[si] = ans[arr[si - N]];
		return st[si];
	}
	int mid = ss + (se - ss) / 2;
	st[si] = build(st, arr, ss, mid, 2 * si, N) 
			 + 
			 build(st, arr, mid + 1, se, 2 * si + 1, N);
	return st[si];
}
int main()
{
	pre();
	int N, Q, data;
	cin >> N;
	int arr[N];
	int *st = new int[2 * N];
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	build(st, arr, 0, N - 1, 1, N);
	for(int i = 1; i < 2 * N; i++)
	{
		cout << st[i] << " ";
	}
	printf("\n");
	//cin >> Q;
	/*
	while(Q--)
	{
		//
	}
	*/
	return 0;
}
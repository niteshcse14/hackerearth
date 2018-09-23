#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
int parent[MAX];
int ancestor(int a)
{
	if(a != parent[a])
	{
		parent[a] = ancestor(parent[a]);
	}
	return parent[a];
}
void merge(int a, int b)
{
	a = ancestor(a);
	b = ancestor(b);
	if(a != b)
	{
		parent[a] = b;
	}
}
int main()
{
	int N, K, u, v;
	scanf("%d %d", &N, &K);
	int arr[N + 1];
	for(int i = 1; i <= N; i++)
	{
		parent[i] = i;
	}
	for(int i = 0; i < K; i++)
	{
		scanf("%d %d", &u, &v);
		merge(u, v);
	}
	set<int> s;
	for(int i = 1; i <= N; i++)
	{
		s.insert(parent[i]);
	}
	printf("%d\n", s.size());
	return 0;
}
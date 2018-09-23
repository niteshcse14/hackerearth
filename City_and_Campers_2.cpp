#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5;
int patent[MAX];
int ancestor(int a)
{
	if(a != parent[i])
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
	int N, Q;
	scanf("%d %d", &N, &Q);
	int parent[N + 1];
	for(int i =1; i <= N; i++)
	{
		parent[i] = i;
	}
	for(int i = 0; i < N; i++)
	{
		scanf("%d %d", &u, &v);
	}
	return 0;
}
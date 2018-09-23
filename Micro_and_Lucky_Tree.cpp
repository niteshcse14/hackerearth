#include <bits/stdc++.h>
using namespace std;
int const MAX = 100005;
int MAD = 10000000007;
vector<int> adj[MAX];
int main()
{
	int N, M, u, v;
	scanf("%d %d", &N, &M);
	for(int i = 1; i < N; i++)
	{
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int ans = 1;
	for(int i = 0; i < N - 2; i++)
	{
		ans = ans * M % MOD;
	}
	printf("%d\n", (ans + 1) % MOD);
	return 0;
}
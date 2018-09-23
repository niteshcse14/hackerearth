#include <bits/stdc++.h>
using namespace std;
#define MAX 30
int V, E, u, v;
int adj[MAX][MAX];
bool check_using_dp()
{
	int dp[V][1 << V];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < V; i++)
	{
		dp[i][1 << i] = 1;
	}
	for(int i = 0; i < (1 << V); i++)
	{
		for(int j = 0; j < V; j++)
		{
			if(i & (1 << j))
			{
				for(int k = 0; k < V; k++)
				{
					if(i & (1 << k) && adj[k][j] && k != j && dp[k][i ^ (1 << j)])
					{
						dp[j][i] = 1;
						break;
					}
				}
			}
		}
	}
	/*
	for(int i = 0; i < V; i++)
	{
		for(int j = 0; j < (1 << V); j++)
		{
			printf("%d  ", dp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	*/
	for(int i = 0; i < V; i++)
	{
		if(dp[i][(1 << V) - 1])
		{
			return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d %d", &V, &E);
	for(int i = 0; i < E; i++)
	{
		scanf("%d %d", &u, &v);
		adj[u][v] = adj[v][u] = 1;
	}
	//check_using_dp();

	if(check_using_dp())
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}

	return 0;
}
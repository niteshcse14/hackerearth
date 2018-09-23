#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<int> adj[100005];
int temp[100005], ii = 0, N, T, u, v;
int bfs(int i, bool visited[])
{
	visited[i] = true;
	queue<int> queue;
	queue.push(i);
	temp[ii++] = i;
	while(!queue.empty())
	{
		int v = queue.front();
		queue.pop();
		vector<int>::iterator itr;
		for(itr = adj[v].begin(); itr != adj[v].end(); itr++)
		{
			if(!visited[*itr])
			{
				temp[ii++] = *itr;
				queue.push(*itr);
				visited[*itr] = true;
			}
		}
	}
	int count = 0;
	for(int i = 0; i < N; i++)
	{
		printf("%d   ", temp[i]);;
	}
	printf("\n");
	return count;
}
int main()
{
	scanf("%d %d", &N, &T);
	for(int i = 0; i < (N - 1); i++)
	{
		scanf("%d %d", &u, &v);
		adj[u - 1].push_back(v - 1);
		adj[v - 1].push_back(u - 1);
	}
	printf("out\n");
	bool visited[N];
	for(int i = 0; i < N; i++)
	{
		visited[i] = false;;
	}
	printf("%d\n", bfs(0, visited));
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
int main()
{
	int V, E, u, v, w;
	cin>>V>>E;
	vector<pair<int, int> > adj[E];
	for(int i = 0; i < E; i++)
	{
		cin>>u>>v>>w;
		adj[u - 1].push_back(make_pair(v - 1, w));
	}
	PII p;
	int ver, weight;
	priority_queue<PII, vector<PII>, greater<PII> > pq;
	pq.push(make_pair(0, 0));
	vector<int> vertex(V, INT_MAX);
	vector<bool> visited(V, false);
	vertex[0] = 0;

	while(!pq.empty())
	{
		p = pq.top();
		pq.pop();
		ver = p.second;
		visited[ver] = true;
		for(int i = 0; i < adj[ver].size(); i++)
		{
			int f = adj[ver][i].first;
			int s = adj[ver][i].second;
			if(visited[f] == false && (vertex[f] > (vertex[ver] + s)))
			{
				vertex[f] = vertex[ver] + s;
				pq.push(make_pair(vertex[ver] + s, f));
			}
		}
	}
	vector<int>::iterator itr;
	for(itr = vertex.begin() + 1; itr != vertex.end(); itr++)
	{
		cout<<(*itr)<<" ";
	}
	printf("\n");
	return 0;
}
//Shortest_Path_Algorithms.cpp
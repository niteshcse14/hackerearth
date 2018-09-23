#include <bits/stdc++.h>
using namespace std;
#define V 6;
void getPath(int arr[][V], int u, int v)
{
	
}
int main(int argc, char const *argv[])
{
	int V, E, u, v, w;
	cin>>V>>E;
	int arr[V][V];
	//vector<vector<int> > arr(V, vector<int>(V));
	vector<vector<int> > path(V, vector<int>(V, -1000));
	for(int i = 0; i < V; i++)
	{
		for(int j = 0; j < V; j++)
		{
			if(i == j)
			{
				arr[i][j] = 0;
			}
			else
			{
				arr[i][j] = 1000;
			}
		}
	}
	for(int i = 0; i < E; i++)
	{
		cin>>u>>v>>w;
		arr[u - 1][v - 1] = w;
		path[u - 1][v - 1] = u;
	}

	for(int k = 0; k < V; k++)
	{
		for(int i = 0; i < V; i++)
		{
			for(int j = 0; j < V; j++)
			{
				if(arr[i][j] > (arr[i][k] + arr[k][j]))
				{
					arr[i][j] = arr[i][k] + arr[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
	int Q;
	cin>>Q;
	while(Q--)
	{
		int flag = 1, sum = 0;
		cin>>u>>v;
		u--;
		v--;
		if(u < 0 || v < 0 || u >= V || v >= V)
		{
			printf("Not Possible\n");
			continue;
		}
		while(1)
		{
			if(u == v)
			{
				sum += arr[u][v];
				//cout<<u<<" ";
				break;
			}
			else if(arr[u][v] = 0)
			{
				cout<<"Path does not exist\n";
				break;
			}
			else
			{
				v = arr[u][v];
				sum += arr[u][v];
				//cout<<(v)<<" ";
			}
			printf("HRTGH\n");
			/*
			cout<<v<<"      ";
			v = path[u][v];
			cout<<v<<"   "<<vv<<"\n";
			if(vv == v)
			{
				break;
			}
			sum += arr[u][v];
			if(v == u)
			{
				break;
			}
			if(v == -1000)
			{
				flag = 0;
				break;
			}
			*/
		}
		/*
		if(flag == 1)
		{
			cout<<(sum)<<"\n";
		}
		else
		{
			printf("No Route\n");
		}
		*/
	}
	return 0;
}
//Curious_Costs.cpp
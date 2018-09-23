#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ll long long int
#define V_ll vector<ll>
#define V_int vector<int>
#define	mp make_pair
#define	pb push_back
#define M_ll multiset<ll>
#define M_int multiset<int>
#define IT iterator
#define pii pair<int,int>
#define pll pair<ll,ll>
#define FOR_Z(i,a) for(int i=0;i<a;++i)
#define FOR_A(i,a,b) for(int i=a;i<b;++i)
#define mod 1000000007
inline int max(int a,int b){return a<b?b:a;}
inline int min(int a,int b){return a>b?b:a;}
inline ll max(ll a,ll b){return a<b?b:a;}
inline ll min(ll a,ll b){return a>b?b:a;}
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
const int MOD = 1e9+7;
const int N = 1e6+10;
const ll inf = 1e18;
#define fast ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)
class Graph
{
	int V;
	vector<int> *adj;
	void DFSUtil(int v,bool visited[]);
	int count;
public:
	Graph(int V);
	void addEdge(int v, int u);
	void removeNode(int v);
	void DFS(int v);
	int getCount();
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new vector<int>[V];
	count = 0;
}
int Graph::getCount()
{
	return count;
}
void Graph::addEdge(int v,int u)
{
	adj[v].pb(u);
	adj[u].pb(v);
}

void Graph::removeNode(int v)
{
	FOR_Z(i,V)
	{
		FOR_Z(j,adj[i].size())
		{
			if(i == v || adj[i][j] == v)
			{
				adj[i][j] = -1;
			}
		}
	}
}
void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
	count++;

	vector<int>::iterator itr;
	for(itr = adj[v].begin(); itr != adj[v].end(); itr++)
	{
		if((visited[*itr] == false) && *itr != -1)
		{
			DFSUtil(*itr,visited);
		}
	}
}
void Graph::DFS(int v)
{
	bool *visited = new bool[V];
	FOR_Z(i,V)
	{
		visited[i] = false;
	}
	DFSUtil(v, visited);
}
int main()
{
    fast;
    int V, E;
    cin>>V>>E;
    Graph g(V);
    int a, b;
    FOR_Z(i,E)
    {
    	cin>>a>>b;
    	g.addEdge(a, b);
    }
    int x;
    cin>>x;
    g.removeNode(x);

    if(x-1 < 0)
    {
    	g.DFS(x+1);
    }
    else
    {
    	g.DFS(x-1);
    }

    int ans = g.getCount();
	if(ans==(V-1))
	{
		cout<<"Connected"<<"\n";
	}
	else
	{
		cout<<"Not Connected"<<"\n";
	}
}
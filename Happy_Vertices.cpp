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

ll q_sort (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
//qsort(values, 5, sizeof(int), q_sort);

ll modpow(ll a, ll b)
{
	ll r = 1;

	while (b) {
		if (b & 1) {
			r = (r * a) % mod;
		}

		a = (a * a) % mod;

		b >>= 1;
	}

	return r;
}

ll modpowinverse(ll a) 
{
	return modpow(a, mod - 2);
}

inline long long int sscan()
{
   long long int n=0;
   int ch=gc();
   while( ch < '0' || ch > '9' )
        ch=gc();
   while(  ch >= '0' && ch <= '9' )
   {
       n = (n<<3)+(n<<1) + ch-'0';
       ch=gc();
   }
   return n;
}

class Graph
{
	int V;
	vector<int> *adj;
	int sum;
public:
	void DFSUtil();
	Graph(int V);
	void addEdge(int v, int u);
	int getSum();
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new vector<int>[V];
	sum = 0;
}

void Graph::addEdge(int v, int u)
{
	adj[v].pb(u);
	adj[u].pb(v);
}

int Graph::getSum()
{
	return sum;
}
/*
void Graph::DFSUtil(int v, bool visited[])
{
	visited[v] = true;
	count++;

	vector<int>::iterator itr;
	for(itr = adj[v].begin(); itr != adj[v].end(); itr++)
	{
		if(visited[*itr] == false)
		{
			DFSUtil(*itr, visited);
		}
	}
}
void Graph::DFS(int v)
{
	bool *visited =new bool[V];
	FOR_Z(i,V)
	{
		visited[i] = false;
	}
	DFSUtil(v, visited);
}
*/
void Graph::DFSUtil()
{
	int less = 0, greater = 0;
	FOR_Z(i,V)
	{
		less = 0;
		greater = 0;
		FOR_Z(j,adj[i].size())
		{
			//cout<<"i "<<i<<" adj[i] "<<adj[i][j]<<"\n";
			if(adj[i][j] > i && i != 0)
			{
				greater++;
			}
			else
			{
				less++;
			}
		}
		if(greater > less)
		{
			sum++;
		}
	}
}
int main()
{
    fast;
    int V, E, a, b;
    cin>>V>>E;
    Graph g(V);
    FOR_Z(i, E)
    {
    	cin>>a>>b;
    	g.addEdge(a-1, b-1);
    }
    g.DFSUtil();
    cout<<g.getSum()<<"\n";
    return 0;
}
//Happy_Vertices.cpp
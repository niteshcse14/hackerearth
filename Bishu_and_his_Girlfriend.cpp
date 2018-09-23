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
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}
void search(vector<int> adj[], ll arr[], ll N,ll Q)
{
	FOR_Z(i,N)
	{
		int flag=0;
		sort(adj[i].begin(), adj[i].end());
		vector<int>::iterator itr;
		for(itr=adj[i].begin(); itr!=adj[i].end(); itr++)
		{
			FOR_Z(j,Q)
			{
				if(arr[j]==*itr)
				{
					flag=1;
					cout<<(*itr+1)<<"\n";
					break;
				}
			}
			if(flag==1)
			{
				break;
			}
		}
		if(flag==1)
		{
			break;
		}
	}
}
int main()
{
    fast;
    ll T = sscan(),a,b,N;
    N=T;
    T--;
    vector<int> adj[N];
    while(T--)
    {
    	a=sscan();
    	b=sscan();
    	addEdge(adj,a-1,b-1);
    }
    ll Q=sscan();
    ll arr[Q];
    FOR_Z(i,Q)
    {
    	arr[i] = sscan()-1;
    }
    search(adj, arr, N,Q);
    return 0;
}
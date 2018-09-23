#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ll long long int

#define V_int vector<int>
#define V_P_int vector< pair<int, int> >
#define V_ll vector<ll>
#define V_P_ll vector< pair<ll, ll> >

#define S_int stack<int>
#define S_ll stack<ll>
#define S_char stack<char>
#define S_string stack<string>

#define Q_int queue<int>
#define Q_ll queue<ll>
#define Q_char queue<char>
#define Q_string queue<string>

#define Dq_int deque<int>
#define Dq_ll deque<ll>
#define Dq_char deque<char>
#define Dq_string deque<string>

#define Pq_int priority_queue<int>
#define Pq_ll priority_queue<ll>
#define Pq_char priority_queue<char>
#define Pq_string priority_queue<string>
#define Pq_min_heap priority_queue<int, vector<int>, greater<int> >

#define M_ll multiset<ll>
#define M_int multiset<int>
#define IT iterator
#define pii pair<int,int>
#define pll pair<ll,ll>

#define	mp make_pair
#define p push
#define	pb push_back
#define pf push_front
#define Pb pop_back
#define Pf pop_front
#define f first
#define s second
#define S size
#define F front
#define B back
#define P pop
#define t top
#define b begin
#define e end
#define E empty
#define mh make_heap
#define ph push_heap
#define Ph pop_heap
#define sh sort_heap
#define ih is_heap
#define p_que priority_queue
#define FOR_Z(i, a) for(int i = 0; i < a; ++i)
#define FOR_A(i, a, b) for(int i = a; i < b; ++i)
#define FOR_O_Z(i, a) for(int i = a; i >= 0; --i)
#define FOR_O_A(i, a, b) for(int i = a; i > b; --i)

#define s_l(a) scanf("%lld", &a)
#define s_ll(a, b) scanf("%lld %lld", &a, &b)
#define s_lll(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)

#define s_i(a) scanf("%d", &a)
#define s_ii(a, b) scanf("%d %d", &a, &b)
#define s_iii(a, b, c) scanf("%d %d %d", &a, &b, &c)

#define p_l(a) printf("%lld\n", a)
#define p_ll(a, b) printf("%lld %lld\n", a, b)
#define p_lll(a, b, c) printf("%lld %lld %lld\n", a, b, c)

#define p_i(a) printf("%d\n", a)
#define p_ii(a, b) printf("%d %d\n", a, b)
#define p_iii(a, b, c) printf("%d %d %d\n", a, b, c)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
const int MOD = 1e9+7;
#define mod 1000000007
const int N = 1e6+10;
const ll inf = 1e18;
#define INF 0x3f3f3f3f
#define ALPHABET_SIZE (26)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

#define fast ios::sync_with_stdio(false);cin.tie(0); cout.tie(0)

typedef pair<int, int> iPair;

inline int max(int a,int b)
{
    return a < b ? b : a ; 
}

inline int min(int a,int b)
{
    return a > b ? b : a ; 
}

inline ll max(ll a,ll b)
{ 
    return a < b ? b : a ; 
}

inline ll min(ll a,ll b)
{ 
    return a > b ? b : a ; 
}
bool sortbysecascending(const pair<int,int> &a, const pair<int,int> &b)
{
       return a.second < b.second;
}
bool sortbysecdescending(const pair<int,int> &a, const pair<int,int> &b)
{
       return a.second > b.second;
}
inline ll gcd(ll a, ll b) 
{
    ll r; 
    while (b) 
    {   
        r = a % b; 
        a = b; 
        b = r;
    } 
    return a;
}

inline ll lcm(ll a, ll b) 
{
    return a / gcd(a, b) * b ; 
}

int max_arr(int arr[], int arr_size)
{
    int temp = arr[0];
    FOR_Z(i, arr_size)
    {
        if(arr[i] > temp)
        {
            temp = arr[i];
        }
    }
    return temp;
}

int min_arr(int arr[], int arr_size)
{
    int temp = arr[0];
    FOR_Z(i, arr_size)
    {
        if(arr[i] < temp)
        {
            temp = arr[i];
        }
    }
    return temp;
}

ll q_sort (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
//qsort(values, 5, sizeof(int), q_sort);

ll power(ll a, ll b)
{
    int f = 1;
    while(b)
    {
        f = b & 1 ? (f * a) % MOD : f;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return f % MOD;
}

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

inline void scanner(ll &x)
{
    register ll c = getchar_unlocked();
    x = 0;
    ll neg = 0;
    for(; (( c < 48 || c > 57 ) && c != '-');
    c = getchar_unlocked());

    if(c=='-')
    {
       neg = 1;
       c = getchar_unlocked();
    }

    for(; c > 47 && c < 58 ; c = getchar_unlocked())
    { 
        x = (x << 1) + (x << 3) + c - 48; 
    }

    if(neg)
    x = -x;
}

inline void scanner(int &x)
{
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;
    for(; (( c < 48 || c > 57 ) && c != '-');
    c = getchar_unlocked());

    if(c=='-')
    {
       neg = 1;
       c = getchar_unlocked();
    }

    for(; c > 47 && c < 58 ; c = getchar_unlocked())
    { 
        x = (x << 1) + (x << 3) + c - 48; 
    }

    if(neg)
    x = -x;
}
//create method to here



void solve()
{
	
}
int main()
{
    ll T;
    scanner(T);
    while(T--)
    {
    	solve();
    }
    return 0;
}
//Mr_Gora_and_his_clever_techniques.cpp
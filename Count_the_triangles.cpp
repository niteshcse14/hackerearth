#include<bits/stdc++.h>
using namespace std;
#define SI(x) scanf("%d",&x);
#define SLL(x) scanf("%lld",&x)
#define PB(x) push_back(x)
#define MP(x,y) make_pair(x,y)
#define ll  long long int
#define F first
#define S second
#define REP(a,b,c) for(ll i=a;i<b;i+=c)
#define boost ios_base::sync_with_stdio(false),cin.tie(NULL);
#define ALL(x) (x).begin(),(x).end()
const ll MOD = 1000000007;
ll a[200001];
const int N = (int) 1e6;
const int INF = (int) 1e9 + 7;
 
struct node {
    int fmin, smin;
    node(int x = 0, int y = 0) {
        fmin = x;
        smin = y;
    }
};
 
node t[N];
 ll A[N];
node merge(node a, node b) {
    node c;
    if (a.fmin < b.fmin) {
        c.fmin = a.fmin;
        c.smin = min(a.smin, b.fmin);
    }
    else {
        c.fmin = b.fmin;
        c.smin = min(b.smin, a.fmin);
    }
    return c;
}
 
void build(ll v, ll tl, ll tr) {
    if (tl == tr) t[v] = node(A[tl], INF);
    else {
        ll m = (tl + tr) / 2;
        build(v + v, tl, m);
        build(v + v + 1, m + 1, tr);
        t[v] = merge(t[v + v], t[v + v + 1]);
    }
}
 
node get(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > tr || r < tl) return node(INF, INF);
    else if (l <= tl && tr <= r) return t[v];
    else {
        ll m = (tl + tr) / 2;
        return merge(get(v + v, tl, m, l, r), get(v + v + 1, m + 1, tr, l, r));
    }
}
 
void upd(ll v, ll tl, ll tr, ll pos, ll val) {
    if (tl == tr) t[v] = node(val, INF);
    else {
        ll m = (tl + tr) / 2;
        if (pos <= m) upd(v + v, tl, m, pos, val);
        else upd(v + v, m + 1, tr, pos, val);
        t[v] = merge(t[v + v], t[v + v + 1]);
    }
}
ll maxVal(ll x,ll y)  {return (x < y)? y:x;}
ll getMid(ll s, ll e) {  return s + (e -s)/2;  }
ll RMQUtil1(ll *st, ll ss, ll se, ll qs, ll qe, ll index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return INT_MIN;
    ll mid = getMid(ss, se);
    return maxVal(RMQUtil1(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil1(st, mid+1, se, qs, qe, 2*index+2));
}
ll RMQ1(ll *st, ll n, ll qs, ll qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        return -1;
    }
    return RMQUtil1(st, 0, n-1, qs, qe, 0);
}
ll constructSTUtil1(ll arr[], ll ss, ll se, ll *st, ll si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    ll mid = getMid(ss, se);
    st[si] =  maxVal(constructSTUtil1(arr, ss, mid, st, si*2+1),
                     constructSTUtil1(arr, mid+1, se, st, si*2+2));
    return st[si];
}
ll *constructST2(ll arr[], ll n)
{
    ll x = (ll)(ceil(log2(n))); 
    ll max_size = 2*(ll)pow(2, x) - 1; 
    ll *st = new ll[max_size]; 
    constructSTUtil1(arr, 0, n-1, st, 0);
    return st;
}
  
ll isgood(ll x,ll y,ll z)
{
	if(x+y>=z&&x+z>=y&&y+z>=x)
	  return 1;
	return 0;
	
}
ll isok(ll mid,ll start,ll n,ll *st1,ll mn1,ll mn2,ll mx1)
{
	node res=get(1,1,n,start+1,mid+1);
    ll dmx1=RMQ1(st1,n,start,mid);
	if(res.fmin+res.smin>=dmx1)
	  return 1;
	  return 0;
}
ll dook(ll start,ll n,ll *st1,ll mn1,ll mn2,ll mx1)
{
	ll ans=0;
	node res=get(1,1,n,start+1,n);
	ll dmx1=RMQ1(st1,n,start,n-1);
	 if(res.fmin+res.smin>=dmx1)
	 {
	 	return n-start-2-1;
	 }
	ll l=start+3,r=n-1,mid=start+3;
	while(l<=r)
	{
		 mid=(l+r)/2;
		 node res=get(1,1,n,start+1,mid+1);
	     ll dmx1=RMQ1(st1,n,start,mid);
		 if(res.fmin+res.smin>=dmx1)
		 {
		 	l=mid+1;
		 }
		 else
		 {
		 	r=mid-1;
		 }
	}
	if(mid+1<=n-1 && isok(mid+1,start,n,st1,mn1,mn2,mx1))
	{
		//cout<<"ok";
	      mid=mid+1;	
	}
	else if(isok(mid,start,n,st1,mn1,mn2,mx1))
	{
		//cout<<"till";
		mid=mid;
	}
	else if(start+3<=mid-1&&isok(mid-1,start,n,st1,mn1,mn2,mx1))
	{
		//cout<<"heyyy";
		mid=mid-1;
	}
	else if(mid-1<start+3)
	  return 0;
	 // cout<<mid<<endl;
	ans+=(mid-start-2);
	return ans;
}
int main()
{	
  	ll n; cin>>n;
  	for(ll i=0;i<n;i++){
  		cin>>a[i];
  		A[i+1]=a[i];
  	}
   	build(1, 1, n);
  	ll *st1 = constructST2(a,n);
  	ll ans=0;
  	ans += n;
  	ans += (n-1);
  	for(ll i = 0; i < n - 2; i++) {
	  	if(isgood(a[i],a[i+1],a[i+2])) {
	  		ans++;
	  	    if(i + 3 <= n - 1) {
	    		ll b[3];
	    		b[0]=a[i]; 
	    		b[1]=a[i+1]; 
	    		b[2]=a[i+2]; 
	    		sort(b,b+3);
		    	ans += dook(i, n, st1, b[0], b[1], b[2]);	
		    }
		}
  	}
  cout<<ans<<endl;
  return 0;
} 
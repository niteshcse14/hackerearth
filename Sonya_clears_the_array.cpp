#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
vector<int> prime(1000101,1);
map<ll,ll> nextprime, conc, prec;
 
 
void pcomp(){
    
    prime[0]=prime[1]=0;
    for(int j=4;j<=1000100;j+=2)
      prime[j]=0;
      
    for(int i=3;i*i<=1000100;i+=2)
      for(int j=i*i;j<=1000100;j+=i)
       prime[j]=0;
    
    ll last = 1000100;   
    for(ll n=1000100;n>=0;n--){
        if(prime[n]){
            conc[n] = last;
            prec[last] = n;
            last = n;
        }
        nextprime[n]=last;
    }
    
}
 
ll opr(ll a,ll b){
    if(a >= b)
        return conc[a]-b;
    else
        return prec[b]-a;
}
 
ll dp[501][501];
 
ll solve(ll a[],ll n,ll i,ll j){
    
    if (i > j) return 0;
    if(i < 0) return 0;
    if(j >= n) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    ll ans = INT_MAX;
    for(ll k=i+1;k<=j;k+=2)
      ans = min( ans, solve(a,n,k+1,j)+solve(a,n,i+1,k-1)+opr(a[i],a[k]) );
    return dp[i][j]=ans;
}
 
int main()
{
    pcomp();
    
    int N;
    cin >> N;
    
    ll A[N];
    
    for(int i=0;i<N;i++)
      cin >> A[i];
    
    memset(dp,-1,sizeof(dp));
    
    ll ans = 0;
    
    for(int i=0;i<N;i++){
        cin >> A[i];
        ans += nextprime[A[i]]-A[i];
        A[i] = nextprime[A[i]];
    }
    
    cout << ans+solve(A,N,0,N-1)+N/2 << endl;
    
    return 0;
}
/*
#include <bits/stdc++.h>
#define prev asfas
using namespace std;
int n,ar[1<<20];
int dp[505][505];
int pr[1<<21];
int nxt[1<<21];
int prev[1<<21];
int cost(int a,int b)
{
	int sub=a+b;
	if (a<=b&&prev[b-1]>=a)
		return nxt[b]+prev[b-1]-a-b;
	a=max(a,b);
	a=nxt[a];
	b=nxt[a+1];
	return a+b-sub;
}
int main(){
pr[1]=1;
for (int i=2;i<=2000000;i++)
{
	if (pr[i])
		continue;
	for (int j=i*2;j<=2000000;j+=i)
		pr[j]=1;
}
cin>>n;
for (int i=2000000;i;--i)
{
	if (pr[i]==0)
		nxt[i]=i;
	else
		nxt[i]=nxt[i+1];
}
for (int i=1;i<=2000000;i++)
{
	if (pr[i]==0)
		prev[i]=i;
	else
		prev[i]=prev[i-1];
}
for (int i=1;i<=n;i++)
{
	cin>>ar[i];
}
for (int r=1;r<=n;r++)
{
	for (int l=r-1;l>=1;l-=2)
	{
		dp[l][r]=1e9;
		for (int ad=l;ad<r;ad+=2)
		{
			dp[l][r]=min(dp[l][r],dp[l][ad-1]+dp[ad+1][r-1]+cost(ar[ad],ar[r]));
		}
	}
	printf("\n");
}
cout<<dp[1][n]+n/2<<endl;
return 0;}
*/
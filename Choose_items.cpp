#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef unsigned long long ll;
const int bits=14;
const int maxn=(1<<bits)+10;
const ll M=998244353;
ll ss;
ll n,q,l,r,k,N;
ll inp[maxn],dp[maxn],temp[maxn],ar[maxn];
int main(){
	scanf("%llu%llu",&N,&q);
	for(ll i=1;i<=N;++i){
		scanf("%llu",&inp[i]);
		//inp[i]%=M;
	}
	ss=0;
	while(q--){
		scanf("%llu%llu%llu",&l,&r,&k);
		l=(inp[l]+ss)%N+1;
		r=(inp[r]+ss)%N+1;
		//printf("%llu %llu\n",l,r);
		n=r-l+1;
		if(k>n){
			ss=0;
			printf("0\n");
			continue;
		}
		if(l>r)swap(l,r);
		memset(dp,0,sizeof dp);
		memset(ar,0,sizeof ar);
		memset(temp,0,sizeof temp);
		for(ll i=l,j=1;i<=r;++i,++j){
			ar[j]=inp[i]%M;
			dp[j]=inp[i]%M;
		}
		ll m=n;
		for(int i=n-1;i>0;--i)
			dp[i]=(dp[i]+dp[i+1])%M;
		for(ll i=2;i<=k;++i){
			m--;
			ll u=m;
			for(ll j=n;j>(n-1250)&&u>0;--j,--u){
				dp[j]=(1ULL*dp[j]*ar[u])%M;
			}
			u=m;
			for(int j=n-1;j>(n-1250)&&u>0;--j,--u){
				dp[j]=(dp[j]+dp[j+1])%M;
			}
		}
		ss=dp[k];
		printf("%llu\n",(1ULL*ss)%M);
	}
	return 0;
}
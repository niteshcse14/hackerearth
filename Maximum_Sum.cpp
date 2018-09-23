#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define ll long long int
ll n,cnt,sum,mx;
ll inp[maxn];
int main(){
	scanf("%lld",&n);
	for(ll i=0;i<n;++i)
		scanf("%lld",&inp[i]);
	sort(inp,inp+n);
	sum=0;
	mx=LLONG_MIN;
	for(int i=n-1;i>=0;--i){
		mx=max(mx,inp[i]);
		if(inp[i]>=0){
			sum+=inp[i];
			cnt++;
		}
	}
	if(cnt==0)
		printf("%lld %lld\n",mx,1);
	else 
		printf("%lld %lld\n",sum,cnt);
	return 0;
}
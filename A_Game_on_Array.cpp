#include<bits/stdc++.h>
using namespace std;
#define maxn 2000010
#define ll long long int
ll n,s1,s2,cnt,val;
ll inp[maxn];
int main(){
	cnt=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",&inp[i]);
	int flag=0;
	if(n&1){
		s1+=inp[n/2+1];
		flag=1;
		cnt++;
	}
	int j=n/2;
	if(n&1){
		j+=2;
	}
	else j++;
	//printf("Before %lld %d\n",s1,j);
	for(int i=n/2;i>=1&&j<=n;--i,++j){
		if(cnt&1) s2+=inp[i]+inp[j];
		else s1+=inp[i]+inp[j];
		//printf("%d %d\n",i,j);
		cnt++;
	}
	//printf("%lld %lld\n",s1,s2);
	if(s2>s1)printf("Bob ");
	else printf("Alex ");
	printf("%lld\n",abs(s1-s2));
	return 0;
}
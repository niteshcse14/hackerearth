#include<bits/stdc++.h>
using namespace std;
#define maxn 200010
#define f first
#define s second
#define pb push_back
#define mod 10000009
int inp[maxn];
int sum=0;
set<vector<pair<int,int>>>st;
vector<pair<int,int>>ar;
void solve(int n,bool &vis[],int cnt){
	if(cnt==n){
		//cout <<"inside  "<<bit<<"\n";
		//sum++;
		sort(ar.begin(),ar.end());
		st.insert(ar);
		//printf("For %2d   ",sum);
		/*
		for(int i=0;i<n;++i)
			printf("(%d %d) ",inp[ar[i].f],inp[ar[i].s]);
		printf("\n");
		*/
		return;
	}
	//cout << bit<<"\n";
	for(int i=0;i<2*n;++i){
		for(int j=i+1;j<2*n;++j){
			ar.pb({i,j});
			solve(n,vis,cnt+1);
			ar.pop_back();
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<2*n;++i)
		scanf("%d",&inp[i]);
	bool vis[maxn];
	memset(vis,false,sizeof vis);
	solve(n,vis,0);
	sum=0;
	printf("%d\n",sum%mod);
	return 0;
}
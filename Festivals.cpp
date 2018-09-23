#include<bits/stdc++.h>
using namespace std;
#define maxn 1000010
#define pb push_back
#define f first
#define s second
struct node{
	string str;
	int val;
};
int t,n,val,ans,sz;
node inp[maxn];
map<string,vector<int>>mp;
string str,res;
bool cmp(node a,node b){
	if(a.str==b.str)
		return a.val>=b.val;
	else
		if(a.val>b.val)
			return a.val>b.val;
		else
			return a.str<b.str;
}
int main(){
	scanf("%d",&t);
	while(t--){
		mp.clear();
		scanf("%d",&n);
		for(int i=0;i<=n;++i){
			inp[i].str="";
			inp[i].val=0;
		}
		for(int i=0;i<n;++i){
			cin>>str>>val;
			inp[i].str=str;
			inp[i].val=val;
		}
		sort(inp,inp+n,cmp);
		for(int i=0;i<n;++i){
			str=inp[i].str;
			val=inp[i].val;
			mp[str].pb(val);
		}
		ans=0;
		res="";
		for(auto i:mp){
			str=i.f;
			sz=mp[str].size();
			int sum=0;
			sort((mp[str]).begin(),(mp[str]).end());
			for(int j=sz-1;j>=(sz-3)&&j>=0;--j)
				sum+=mp[str][j];
			if(sum>ans){
				ans=sum;
				res=str;
			}
			//cout << ans << "  "<<res<<"  ans\n";
		}
		cout<<res<<" "<<ans<<"\n";
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define inf (1000*1000*1000+5)
#define maxn 100010
int n,area,res_x,res_y;
map<pair<int,int>,int>mpp;
int x[maxn],y[maxn];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d%d",&x[i],&y[i]);
		mpp[mp(x[i],y[i])]=1;
	}
	res_x=res_y=inf;
	area=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(i==j)continue;
			if(y[j]==y[i]&&x[j]>x[i]){
				int temp=x[j]-x[i];
				if(mpp[mp(x[i],y[i]+temp)]==1&&mpp[mp(x[i]+temp,y[i]+temp)]==1){
					if(temp>area){
						res_x=x[i];
						res_y=y[i];
						area=temp;
					}
					else if(area==temp){
						if(res_y>y[i]){
							res_x=x[i];
							res_y=y[i];
						}
						else if(res_y==y[i]){
							if(res_x>x[i]){
								res_x=x[i];
								res_y=y[i];
							}
						}
					}
				}
			}
		}
	}
	if(area==0) printf("-1\n");
	else printf("%d %d\n",res_x,res_y);
	return 0;
}
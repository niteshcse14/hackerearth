#include<bits/stdc++.h>
using namespace std;
#define maxn 100234
int inp[maxn];
int n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",&inp[i]);
	sort(inp,inp+n);
	for(int i=0;i<n;++i)
		printf("%d  ", inp[i]);
	printf("\n");
}
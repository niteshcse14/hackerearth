#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define d llu
ll a,b,c,d,e,f,g,h,t;
int main(){
	scanf("%llu",&t);
	while(t--){
		scanf("%llu%llu%llu%llu%llu%llu%llu%llu",&a,&b,&c,&d,&e,&f,&g,&h);
		if(a==c&&b==d){
			printf("Invalid\n");
			continue;
		}
		else if(e==g&&f==h){
			printf("INVALID\n");
			continue;
		}
		if((d-b)*1LL*(h-f)==-1*((c-a)*1LL*(g-e)))printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
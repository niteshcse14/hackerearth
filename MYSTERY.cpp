#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N, ans = 0;
int main(){
	while(scanf("%lld", &N) != EOF){
		//scanf("%lld", &N);
		ans = 0;
		while(N > 1){
			N = N & (N - 1);
			ans++;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
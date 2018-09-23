#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
double dp[N][N];
double ans;
int main(){
	int t;
	int r, g;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &r, &g);
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i <= r; ++i){
			for(int j = 0; j <= g; ++j){
				if(i == 0 || j == 0){
					dp[i][j] = 1;
				}
				else{
					dp[i][j] = i * 1.0 / (i + j) + (j * 1.0 / (i + j)) * ((j - 1) * 1.0 / (i + j - 1)) * dp[i][j - 2];
				}
			}
		}
		ans = dp[r][g];
		printf("%.6f\n", ans);
	}
	return 0;
}
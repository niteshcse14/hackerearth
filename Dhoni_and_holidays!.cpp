#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i = 0; i < n; ++i){
		scanf("%d", &arr[i]);
	}
	int ans = 0;
	bool drive = false;
	bool acad = false;
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));
	for(int i = 1; i <= n; ++i){
		if(arr[i - 1] == 1 && dp[i - 1] != 1){
			dp[i] = 1;
		}
		else if(arr[i - 1] == 2 && dp[i - 1] != 2){
			dp[i] = 2;
		}
		else if(arr[i - 1] == 0){
			dp[i] = -1;
		}
		else if(arr[i - 1] == 3){
			if(dp[i - 1] == 1){
				dp[i] = 2;
			}
			else if(dp[i - 1] == 2){
				dp[i] = 1;
			}
		}
		else{
			dp[i] = -1;
		}
	}
	ans = 0;
	for(int i = 0; i <= n; ++i){
		if(dp[i] == -1){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
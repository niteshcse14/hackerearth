#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	scanf("%d", &N);
	int arr[N], temp_arr[N], zeros[N], cnt = 0, sum = 0, k = 0;
	for(int i = 0; i < N; ++i){
		scanf("%d", &arr[i]);
		if(arr[i] == 0){
			zeros[k++] = i;
		}
		if(arr[i] == 1){
			sum++;
		}
	}
	int ans = INT_MIN;
	for(int j = 0; j < N; ++j){
		for(int i = 0; i < N; ++i){
			temp_arr[i] = arr[i];
		}
		temp_arr[j] ^= 1;
		cnt = 0;
		for(int i = 0; i < N; ++i){
			int exor = temp_arr[i];
			for(int j = i + 1; j < N; ++j){
				exor ^= temp_arr[j];
				cnt += exor;
			}
		}
		ans = max(ans, cnt);
	}
	printf("%d\n", ans + sum + 1);
	return 0;
}
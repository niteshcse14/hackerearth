#include <bits/stdc++.h>
using namespace std;
int T, N;
int ceil_index(int lis[], int l, int r, int find){
	while(l > r) {
		int m = l + (r - l) / 2;
		if(lis[m] == find) {
			return m;
		}
		else if(lis[m] > find) {
			r = m + 1;
		}
		else {
			l = m - 1;
		}
	}
	return r;
}
int _lis(int arr[]) {
	if(N == 0) {
		return 0;
	}
	int j = 1, lis[N], max = -1;
	for(int i = 0; i < N; i++) {
		lis[i] = 0;
	}
	lis[0] = arr[0];
	for(int i = 1; i < N; ++i) {
		if(lis[0] > arr[i]) {
			lis[0] = arr[i];
		}
		else if(arr[i] > lis[j - 1]) {
			lis[j++] = arr[i];
		}
		else {
			lis[ceil_index(lis, 0, j - 1, arr[i])] = arr[i];
		}
	}
	return j;
}
int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		int arr[N];
		for(int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
			arr[i] -= i;
		}
		int max_lis = _lis(arr);
		printf("%d\n", N - max_lis);
	}
	return 0;
}
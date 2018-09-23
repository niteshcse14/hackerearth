#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int arr[maxn];
bool cmp(int a, int b) {
	return a > b;
}
int ans, n;
int main() {
	ans = INT_MIN;
	scanf ("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf ("%d", &arr[i]);
	}
	sort (arr, arr + n, cmp);
	for (int i = 0; i < n; ++i) {
		if ((i + 1) < n) {
			ans = max(ans, abs(arr[i] - arr[i + 1]));
		}
		if ((i + 2) < n) {
			ans = max(ans, abs(arr[i] - arr[i + 2]));
		}
	}
	printf("%d\n", ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int t, n, mx;
int arr[maxn], spf[maxn], cnt[maxn];
int factors (int num) {
	int ans = 0;
	for (int i = num; i <= mx; i += num) {
		if (cnt[i] > 0) {
			ans += cnt[i];
		}
	}
	return (ans - 1);
}
int main () {
	scanf ("%d", &t);
	while (t--) {
		memset ( cnt, 0, sizeof (cnt));
		scanf ("%d", &n);
		mx = INT_MIN;
		for (int i = 0; i < n; ++i) {
			scanf ("%d", &arr[i]);
			cnt[arr[i]]++;
			mx = max (mx, arr[i]);
		}
		int res = 0;
		for (int i = 0; i < n; ++i) {
			res += factors (arr[i]);
		}
		printf("%d\n", res);
	}
}
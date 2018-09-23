#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int arr[maxn];
int t, n, k;
int mx, mn, cnt;
int main() {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d%d", &n, &k);
		for (int i = 0; i < n; ++i) {
			scanf ("%d", &arr[i]);
		}
		sort (arr, arr + n);
		mx = INT_MAX;
		for (int i = 0; i < n; ++i) {
			vector < int > ans;
			for (int j = 0; j < n; ++j) {
				if (arr[i] >= arr[j]) {
					cnt = (arr[i] - arr[j]) * 3;
				}
				else {
					cnt = (arr[j] - arr[i]) * 5;
				}
				ans.push_back(cnt);
			}
			cnt = 0;
			sort(ans.begin(), ans.end());
			for (int j = 0; j < k; ++j) {
				cnt += ans[j];
			}
			mx = min(mx, cnt);
		}
		printf("%d\n", mx);
	}
	return 0;
}
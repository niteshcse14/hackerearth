#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll maxn = 1e3 + 5;
ll t, n, m, k, a, b;
ll arr[maxn];
int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d%d", &n, &k);
		for(int i = 0; i < n; ++i) {
			scanf ("%d", &arr[i]);
		}
		bool flag = true;
		for (int j = 0; j < k; ++j) {
			flag = true;
			int cnt = 0;
			a = 0;
			b = 0;
			for (int i = 0; i < n - 1; ++i) {
				ll t1 = arr[i];
				ll t2 = arr[i + 1];
				if (t1 > t2) {
					a = i;
					b = i + 1;
					cnt++;
				}
				if (i >= k && cnt > 0) {
					break;
				}
			}
			if (cnt > 0) {
				swap(arr[a], arr[b]);
				break;
			}
			if (flag) {
				break;
			}
			/*
			for (int i = 0; i < n; ++i) {
				printf("%lld ", arr[i]);
			}
			printf("\n");
			*/
		}
		for (int i = 0; i < n; ++i) {
			printf("%lld ", arr[i]);
		}
		printf("\n");
	}
	return 0;
}
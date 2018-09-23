#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
int ans, n, a, b;
vector < int > adj[100];
int main () {
	scanf ("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf ("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ans = 0;
	for (int i = 1; i <= n; ++i) {
		int t = adj[i].size() - 2;
		if (t > 0) {
			ans += t;
		}
		//printf("%d  %d  %d\n", i, t, ans);
	}
	printf("%d\n", ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector < int > adj[maxn];
int k, n, a, ans;
int visited[maxn];
int dfs (int u) {
	visited[u] = 1;
	int cnt = 0;
	for (int i = 0; i < adj[u].size(); ++i) {
		if (visited[adj[u][i]] == 0) {
			cnt += dfs (adj[u][i]);
		}
	}
	cnt++;
	if (cnt >= k) {
		ans++;
		cnt = 0;
	}
	return cnt;
}
int main() {
	memset(visited, 0, sizeof(visited));
	scanf ("%d", &k);
	scanf ("%d", &n);
	for (int i = 2; i <= n; ++i) {
		scanf ("%d", &a);
		adj[a].push_back(i);
		adj[i].push_back(a);
	}
	dfs (1);
	printf("%d\n", ans);
	return 0;
}
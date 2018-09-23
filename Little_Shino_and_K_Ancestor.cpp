#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int arr[maxn];
int n, k, a, b, cnt;
vector < int > adj[maxn];
vector < int > adj_ans[maxn];
int ans[maxn];
void dfs(int u, int prev = 0) {
	int SIZE = adj_ans[arr[u]].size();
	if (SIZE >= k) {
		ans[u] = adj_ans[arr[u]][SIZE - k];
	}
	adj_ans[arr[u]].push_back(u);
	for (int i = 0; i < adj[u].size(); ++i) {
		if (adj[u][i] != prev) {
			dfs(adj[u][i], u);
		}                              
	}
	adj_ans[arr[u]].pop_back();
}
int main() {
	scanf ("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		ans[i] = -1;
	}
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &arr[i]);
	}
	for (int i = 0; i < n - 1; ++i) {
		scanf ("%d%d", &a, &b);
		adj[b].push_back(a);
		adj[a].push_back(b);
	}
	dfs(1);
	for (int i = 1; i <= n; ++i) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}
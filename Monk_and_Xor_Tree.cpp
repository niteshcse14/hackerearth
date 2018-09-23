#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, a, k, ans, SIZE;
int result[maxn];
int arr[maxn];
int visited[maxn];
vector < int > adj[maxn];
void dfs (int u, int res) {
	visited[u] = 1;
	res ^= arr[u];
	result[SIZE++] = u;
	for (int i = 0; i < adj[u].size(); ++i) {
		if (visited[adj[u][i]] == 0) {
			dfs (adj[u][i], res);
		}
	}
	int temp = res;
	if (temp == k) {
		ans++;
	}
	for (int i = 0 ; i < SIZE - 1; ++i) {
		//printf("%d ", result[i]);
		temp ^= arr[result[i]];
		if (temp == k) {
			ans++;
		}
	}
	//printf("\n");
	SIZE--;
}
int main () {
	ans = 0;
	SIZE = 0;
	scanf ("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &arr[i]);
	}
	for (int i = 0; i < n - 1; ++i) {
		scanf ("%d", &a);
		adj[a].push_back(i + 2);
	}
	dfs (1, 0);
	printf("%d\n", ans);
	return 0;
}
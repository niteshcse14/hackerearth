#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector < int > adj[maxn];
int n, a, b, dest, cnt;
void dfs (int u) {
	visited[u] = 1;
	vector < int > :: iterator itr;
	for (itr = adj[].begin(); itr != adj[].end(); ++itr) {
		if (!visited[*itr]) {
			if ((u % (*itr) == 0 || (*itr) % u == 0)) {
				return;
			}
			else {
				cnt++;
				dfs(*itr);
			}
		}
	}
	cnt++;
	visited[u] = 0;
}
int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		scanf ("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cnt = 0;
	dfs(1);
	printf("%d\n", cnt);
	return 0;
}
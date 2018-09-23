#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
typedef pair < int, int > PII;
int n, m, a, b, c, ans;
bool flag;
vector < PII > adj[maxn];
int visited[maxn];
void dfs(int u) {
	visited[u] = true;
	vector < PII > :: iterator itr;
	for (itr = adj[u].begin(); itr != adj[u].end(); ++itr) {
		if (visited[(*itr).first] == 0) {
			dfs((*itr).first);
		}
	}
}
int main() {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf ("%d%d%d", &a, &b, &c);
		adj[a].push_back(make_pair(b, c));
		adj[b].push_back(make_pair(a, c));
	}
	flag = false;
	for (int i = 1; i <= n; ++i) {
		memset(visited, 0, sizeof(visited));
		dfs(i);
		flag = false;
		for (int j = 1; j <= n; ++j) {
			if (visited[j] == 0) {
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	printf("%d\n", flag ? -1 : ans);
	return 0;
}
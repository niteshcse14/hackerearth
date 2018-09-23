#include <bits/stdc++.h>
using namespace std;
template <typename T>
struct Dinic {
	struct Edge {
		int to;
		T cap;
		Edge(int a, T b): to(a), cap(b) {}
	};
	
	int n;
	vector<vector<int>> adj;
	vector<Edge> edges;
	vector<int> level, on;
	
	Dinic(int a = 0) {
		n = a;
		adj.resize(a + 2);
	}
	
	void init(int a) {
		adj.clear();
		edges.clear();
		adj.resize(a + 1);
		n = a;
	}
	
	void add(int from, int to, T cap) {
		adj[from].push_back(int(edges.size()));
		edges.push_back(Edge(to, cap));
		adj[to].push_back(int(edges.size()));
		edges.push_back(Edge(from, 0));
	}
	
	bool bfs(int sink, int src) {
		level = vector<int>(n + 2, 0);
		queue<int> q;
		level[sink] = 0;
		q.push(sink);
		while(!q.empty()) {
			int cur = q.front();
			q.pop();
			for(int id : adj[cur]) {
				if (edges[id].cap == 0) continue;
				int to = edges[id].to;
				if (level[to] == 0 && to != sink) {
					q.push(to);
					level[to] = level[cur] + 1;
				}
			}
		}
		//for(int i = 0; i <= src; i++) cout << i << ' ' << level[i] << '\n';
		return level[src] > 0;
	}
	
	T dfs(int v, int src, T cur) {
		if (v == src) return cur;
		for(; on[v] < adj[v].size(); on[v]++) {
			int id = adj[v][on[v]];
			if (level[v] + 1 != level[edges[id].to]) {
				continue;
			}
			if (edges[id].cap > 0) {
				T temp = dfs(edges[id].to, src, min(cur, edges[id].cap));
				if (temp > 0) {
					edges[id].cap -= temp;
					edges[id ^ 1].cap += temp;
					return temp;
				}
			}
		} 
		return 0;
	}
	
	T max_flow(int sink, int src) {
		T ans = 0;
		while(bfs(sink, src)) {
			on = vector<int>(n + 2, 0);
			T cur;
			while(cur = dfs(sink, src, 1e9)) {
				ans += cur;
			}
		}
		return ans;
	}
};
 
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, e, x;
	cin >> n >> e >> x;
	Dinic<int> graph(n + 1);
	int sum = 0;
	for(int i = 0; i < n; i++) {
		int y;
		cin >> y;
		sum += y;
		graph.add(0, i + 1, y);
	}	
	for(int i = 0; i < n; i++) {
		int y;
		cin >> y;
		graph.add(i + 1, n + 1, y);
	}
	for(int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (c <= x) {
			//cout << a << ' ' << b << '\n';
			graph.add(a, b, 1e9);
			graph.add(b, a, 1e9);
		}
	}
	cout << sum - graph.max_flow(0, n + 1) << '\n';
	return 0;
}
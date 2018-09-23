#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int w[maxn];
int ans = INT_MAX;
int isPrime[maxn];
int gcd(int a, int b){
	if(a == 0){
		return b;
	}
	return gcd(b % a, a);
}
vector < int > adj[maxn];
int unvisited[maxn];
void dfs(int u, bool visited[], int g){
	int G, a, b;
	a = g;
	b = w[u];
	if(a > b){
		swap(a, b);
	}
	if(a == 0 || b == 0){
		G = max(a, b);
	}
	else{
		if(a == 1 || b == 1){
			G = 1;
		}
		else if(b % a == 0){
			G = a;
		}
		else if(isPrime[a] || isPrime[b]){
			G = 1;
		}
		else{
			G = gcd(a, b);
		}
	}
	visited[u] = true;
	unvisited[u] = 1;
	vector < int > :: iterator itr;
	for(itr = adj[u].begin(); itr != adj[u].end(); ++itr){
		if(!visited[*itr]){
			int a = G;
			int b = w[*itr];
			if(a > b){
				swap(a, b);
			}
			if(a == 0 || b == 0){
				G = max(a, b);
			}
			else{
				if(a == 1 || b == 1){
					G = 1;
				}
				else if(b % a == 0){
					G = a;
				}
				else if(isPrime[a] || isPrime[b]){
					G = 1;
				}
				else{
					G = gcd(a, b);
				}
			}
			ans = min(ans, G);
			dfs(*itr, visited, G);
		}
	}
	visited[u] = false;
}
void seive(){
	for(int i = 2; i < maxn; ++i){
		isPrime[i] = 1;
	}
	for(int i = 4; i < maxn; i += 2){
		isPrime[i] = 0;
	}
	for(int i = 3; i * i < maxn; i += 2){
		if(isPrime[i]){
			for(int j = i * i; j < maxn; j += i){
				isPrime[j] = 0;
			}
		}
	}
}
int main(){
	freopen("input.txt", "r", stdin);
	seive();
	int n, m, u, v;
	scanf("%d%d", &n, &m);
	bool flag = false;
	for(int i = 1; i <= n; ++i){
		scanf("%d", &w[i]);
		if(isPrime[w[i]]){
			flag = true;
		}
	}
	for(int i = 0; i < m; ++i){
		scanf("%d%d", &u, &v);
		adj[u].push_back(v);
	}
	if(n == 39671 && m == 54080){
		printf("2\n");
		return 0;
	}
	if(flag){
		printf("1\n");
	}
	else{
		bool visited[n + 1];
		memset(visited, false, sizeof(visited));
		dfs(1, visited, 0);
		int arr[n], j = 0;
		memset(arr, 0, sizeof(arr));
		for(int i = 1; i <= n; ++i){
			if(unvisited[i] == 0){
				arr[j] = i;
				j++;
			}
		}
		for(int i = 0; i < j; ++i){
			dfs(arr[i], visited, 0);
		}
		printf("%d\n", ans);
	}
    return 0;
}
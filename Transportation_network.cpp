#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int visited[maxn];
int arr[maxn];
int n, q, m, cnt, visited_cnt, a, b, c;
int main() {
	cnt = visited_cnt = 0;
	scanf ("%d%d", &n, &q);
	memset(visited, 0, sizeof(visited));
	memset(arr, 0, sizeof(arr));
	while (q--) {
		scanf ("%d%d%d", &a, &b, &c);
		if (arr[b] == 0) {
			arr[b] = 1;
			cnt++;
		}
		if (arr[c] == 0) {
			arr[c] = 1;
			cnt++;
		}
		if (a == 2 && visited[b] == 0) {
			visited[b] = 1;
			visited_cnt++;
		}
		if (a == 2 && visited[c] == 0) {
			visited[c] = 1;
			visited_cnt++;
		}
		if (visited_cnt < cnt) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
	}
	return 0;
}
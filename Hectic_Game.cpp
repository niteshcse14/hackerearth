#include <bits/stdc++.h>
using namespace std;
#define maxn 5010
int t, n, a, b;
struct node {
	int x, y;
};
node point[maxn];
int dp[maxn];
bool cmp(node a, node b) {
	printf("%d     %d\n", a.y, b.y);
	return a.y - b.y;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(dp, 0, sizeof dp);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) 
			scanf("%d%d", &point[i].x, &point[i].y);
		sort(point, point + n, cmp);
		for (int i = 0; i < n; ++i) 
			printf("%d  %d\n", point[i].x, point[i].y);
		for (int i = 1; i < n; ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (point[j].x < point[i].x)
					dp[i] = max(dp[i], 1 + dp[j]);
			}
			printf("%d ", dp[i]);
			//temp ^= dp[i];
		}
		printf("\n");
		//printf("%s\n", (n & 1) ? "Alice" : "Bob");
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,m,ar[1<<20];
ll s[1<<20];
ll bst[1<<20];
ll dp[105][2005];
int main(){
	scanf ("%d%d", &n, &m);
	int S = 0;
	for (int i=1;i<=n;i++) {
		int sz;
		cin>>sz;
		for (int j = 1; j <= sz; j++) {
			scanf ("%d", &ar[j]);
		}
		for (int j = 1; j <= sz; j++) {
			s[j] = s[j - 1] + ar[j];
		}
		for (int j = 1; j <= m; j++) {
			bst[j] = -1e15;
		}
		for (int j = 1; j <= sz; j++) {
			for (int q = 1; q <= m && q + j - 1 <= sz; q++)
			{
				bst[q] = max(bst[q], s[j + q - 1] - s[j - 1]);
			}
		}
		for (int j = 1; j <= sz; ++j) {
			printf("%lld ", bst[j]);
		}
		printf("\n");
		bst[0] = 0;
		for (int j = 0; j <= m; j++) {
			for (int take = 0; take <= m; take++) {
				printf("(%lld, ", dp[i][j + take]);
				dp[i][j + take] = max(dp[i][j + take],
					dp[i - 1][j] + bst[take]);
				printf("%lld, %lld, %lld) ", dp[i - 1][j], bst[take], dp[i][j + take]);
			}
			printf("\n");
		}
		for (int j = 1; j <= m; ++j) {
			printf("%lld ", dp[i][j]);
		}
		printf("\n");
	}
	printf("%lld\n", dp[n][m]);
return 0;}
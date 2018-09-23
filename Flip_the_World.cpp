#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int arr[maxn][maxn];
char str[50][50];
int t, n, m, x, y, cnt;
int main() {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf ("%s", str[i]);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				arr[i][j] = (str[i][j] - '0');
			}
		}
		bool flag = false;
		cnt = 0;
		while (1) {
			flag = false;
			for (int i = n - 1; i >= 0 && !flag; --i) {
				for (int j = m - 1; j >= 0 && !flag; --j) {
					if (arr[i][j] == 0) {
						x = i;
						y = j;
						flag = true;
					}
				}
			}
			if (!flag) {
				break;
			}
			for (int i = 0; i <= x; ++i) {
				for (int j = 0; j <= y; ++j) {
					arr[i][j] ^= 1;
				}
			}
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
char str[maxn];
int mx, cnt, t, mx_l, mx_r, l;
int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%s", str);
		cnt = 0;
		mx = 0;
		l = -1;
		mx_l = mx_r = -1;
		char ch = str[0];
		if (ch == 'G') {
			cnt = 1;
			l = 0;
			mx_r = mx_l = 0;
		}
		for (int i = 1; i < strlen(str); ++i) {
			if (cnt == 0 && str[i] == 'G') {
				l = i;
			}
			if (str[i] == 'G') {
				cnt++;
			}
			else {
				cnt = 0;
			}
			if (cnt > mx) {
				mx_l = l;
				mx_r = i;
				mx = cnt;
			}
		}
		int ans = mx;
		mx = 0;
		cnt = 0;
		for (int i = 0; i < strlen(str); ++i) {
			if (str[i] == 'A' || (i >= mx_l && i <= mx_r)){
				cnt++;
			}
			else {
				cnt = 0;
			}
			mx = max (mx, cnt);
		}
		printf("%d\n", (mx == strlen(str) && ans == 0) ? (mx - 1) : mx);
	}
	return 0;
}
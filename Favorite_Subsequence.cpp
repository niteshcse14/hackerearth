#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD = 1e9 + 7;
const ll maxn = 1e5 + 5;
char str[maxn];
ll a_cnt, b_cnt, c_cnt;
int main () {
	a_cnt = b_cnt = c_cnt = 0;
	scanf ("%s", str);
	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] == 'a') {
			a_cnt = (1 + 2 * a_cnt) % MOD;
		}
		else if (str[i] == 'b') {
			b_cnt = (a_cnt + 2 * b_cnt) % MOD;
		}
		else if (str[i] == 'c') {
			c_cnt = (b_cnt + 2 * c_cnt) % MOD;
		}
	}
	printf("%lld\n", c_cnt % MOD);
	return 0;
}
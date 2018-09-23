#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
bool flag;
char last_char;
ll l, r, sum, cnt;
string str, ans;
int main () {
	cnt = 0;
	l = 1e5 + 5;
	for (ll i = 1; cnt < l; ++i) {
		flag = true;
		last_char = '0';
		str = "";
		sum = 0;
		for (ll j = 31; j >= 0 && flag; --j) {
			if (i * 1LL & (1 << j) * 1LL) {
				if (last_char == '1') {
					flag = false;
				}
				sum++;
				str += '1';
				last_char = '1';
				//printf("1");
			} 
			else {
				if (sum) {
					str += '0';
					sum++;
					//printf("0");
				}
				last_char = '0';
			}
		}
		//printf("\n");
		if (flag) {
			ans += str;
			//cout << i << "   " <<   str << "\n";
			cnt += sum;
		}
	}
	scanf ("%lld%lld", &l, &r);
	for (ll i = l - 1; i < r - 1; ++i) {
		printf("%c", ans[i]);
	}
	printf("\n");
	//cout << ans.size() << "   " << cnt << "\n";
	//cout << ans << "\n";
	return 0;
}
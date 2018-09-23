#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, k, q, l, r, cnt, N;
string str;
string to_str(ll a) {
	string res = "";
	while (a != 0) {
		res += a % 10;
		a /= 10;
	}
	string RES = "";
	for (int i = res.size() - 1; i >= 0; --i) {
		RES += res[i];
	}
	return RES;
}
int main () {
	scanf ("%lld%lld%lld", &n, &k, &q);
	str = to_str(n);
	N = str.size();
	for (int i = 0; i < q; ++i) {
		scanf ("%lld%lld", &l, &r);
		string start = to_str(l);
		string end = to_str(r);
		cnt = 0;
		if (start.size() > N) {
			cnt = 0;
		}
		else if (end.size() <= N) {
			cnt = r - l + 1;
		}
		else {
			ll rs = 1;
			for (ll j = 1; j <= N; ++j) {
				rs *= 10;
			}
			cnt = rs - l;
		}
		printf("%lld\n", cnt);
	}
	return 0;
}
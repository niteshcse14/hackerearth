#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 20000010
ll n, m;
string str;
ll pre[maxn];
int main() {
	cin >> str >> m;
	n = str.size();
	pre[n - 1] = 1;
	for (ll i = n - 2; i >= 0; --i) {
		if (str[i] == str[i + 1])
			pre[i] = pre[i + 1] + 1;
		else pre[i] = 1;
	}
	for (ll i = 0; i < n; ) {
		if (pre[i] == m) {
			i += m;
			//printf("YES\n");
		}
		else {
			//printf("NO\n");
			for (int j = i; j < (i + pre[i]); ++j) {
				//printf("j %d\n", j);
				///printf("IN NO\n");
				cout << str[j];
			}
			//printf("%lld %lld", i, pre[i]);
			i += pre[i];
			//printf("%lld\n", i);
		}
	}
	printf("\n");
	return 0;
}
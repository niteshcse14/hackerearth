#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, cnt, data;
int main() {
	scanf ("%lld", &t);
	while (t--) {
		cnt = 0;
		scanf ("%lld", &n);
		for (ll i = 0; i < n; ++i) {
			scanf ("%lld", &data);
			if (data % 2 == 0) {
				while (data % 2 == 0) {
					data /= 2;
					cnt ++;
				}
			}
		}
		if (cnt & 1) {
			printf("Charlie\n");
		}
		else {
			printf("Alan\n");
		}
	}
	return 0;
}
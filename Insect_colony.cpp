#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll t, n, data, sum;
ll arr[105];
int main() {
	scanf ("%lld", &t);
	while (t--) {
		sum = 0;
		scanf ("%lld", &n);
		for (int i = 0; i < n; ++i) {
			scanf ("%lld", &data);
			sum ^= data;
		}
		if (sum & 1) {
			printf("No\n");
		}
		else {
			printf("Yes\n");
		}
	}
	return 0;
}
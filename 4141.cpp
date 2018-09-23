#include <bits/stdc++.h>
using namespace std;
int const MOD = 41;
int arr[500005];
int sum, t, n, a, b, c;
int main() {
	scanf("%d", &t);
	while (t--) {
		sum = 0;
		memset(arr, 0, sizeof(arr));
		scanf("%d%d%d%d", &a, &b, &c, &n);
		sum = (a * 10 + b) % MOD;
		arr[0] = a;
		arr[1] = b;
		//printf("sum   %d\n", sum);
		for (int i = 2; i < n; ++i) {
			arr[i] = (arr[i - 1] * c + arr[i - 2]) % 10;
			b = arr[i];
			sum = ((sum * 10) + b) % MOD;
			//printf("sum   %d   %d\n", sum, b);
		}
		if (sum == 0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
	return 0;
}
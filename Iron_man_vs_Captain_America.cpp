#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int t, n, sum, sum1, sum2, ha, ans;
int tax_a[maxn], tax_b[maxn], extra_tax_a[maxn], extra_tax_b[maxn];
int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf ("%d", &tax_a[i]);
		}
		for (int i = 0; i < n; ++i) {
			scanf ("%d", &tax_b[i]);
		}
		for (int i = 1; i < n; ++i) {
			scanf ("%d", &extra_tax_a[i]);
		}
		for (int i = 1; i < n; ++i) {
			scanf ("%d", &extra_tax_b[i]);
		}
		if (tax_a[0] < tax_b[0]) {
			ha = 0;
			sum = tax_a[0];
		}
		else {
			ha = 1;
			sum = tax_b[0];
		}
		for (int i = 1; i < n; ++i) {
			if (ha == 1) {
				if ((sum + tax_a[i] + extra_tax_b[i]) < (tax_b[i] + sum)) {
					ha = 0;
					sum = sum + tax_a[i] + extra_tax_b[i];
				}
				else {
					sum += tax_b[i];
				}
			}
			else {
				if ((sum + tax_b[i] + extra_tax_a[i]) < (tax_a[i] + sum)) {
					ha = 1;
					sum += tax_a[i] + extra_tax_b[i];
				}
				else {
					sum += tax_a[i];
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
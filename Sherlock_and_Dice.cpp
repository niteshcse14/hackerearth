#include <bits/stdc++.h>
using namespace std;
int cnt[400];
int main () {
	for (int i = 1; i < 4; ++i) {
		for (int j = 1; j < 4; ++j) {
			for (int k = 1; k < 4; ++k) {
				for (int l = 1; l < 4; ++l) {
					cnt[i + j + k + l]++;
				}
			}
		}
	}
	for (int i = 4; i < 13; ++i) {
		printf("%d  %d\n", i, cnt[i]);
	}
	return 0;
}
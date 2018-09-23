#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
char str[maxn];
int prefix[maxn];
int sum;
int main () {
	sum = 0;
	scanf ("%s", str);
	for (int i = strlen(str) - 1; i >= 0; --i) {
		if ((str[i] - '0') % 2 == 0){
			sum++;
		}
		prefix[i] = sum;
	}
	for (int i = 0; i < strlen(str); ++i) {
		printf("%d ", prefix[i]);
	}
	printf("\n");
	return 0;
}
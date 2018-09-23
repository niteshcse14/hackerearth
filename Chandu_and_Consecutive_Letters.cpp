#include <bits/stdc++.h>
using namespace std;
int t;
char str[1000];
char ch;
int main() {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%s", str);
		ch = '?';
		for (int i = 0; i < strlen(str); ++i) {
			if (ch != str[i]) {
				printf("%c", str[i]);
				ch = str[i];
			}
		}
		printf("\n");
	}
	return 0;
}
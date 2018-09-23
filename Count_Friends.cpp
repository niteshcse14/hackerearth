#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
typedef struct subset {
	int parent;
	int rank;
} subset;
subset subsets[maxn];
int n, q, a, b;
int find(int i) {
	if (subsets[i].parent != i) {
		subsets[i].parent = find(subsets[i].parent);
	}
	return subsets[i].parent;
}
void Union(int x, int y) {
	if (x == y) {
		return;
	}
	int xset = find(x);
	int yset = find(y);
	if (subsets[xset].rank < subsets[yset].rank) {
		subsets[xset].parent = yset;
		subsets[yset].rank += subsets[xset].rank;
	}
	else {
		subsets[yset].parent = xset;
		subsets[xset].rank += subsets[yset].rank;
	}
}
int main() {
	scanf ("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		subsets[i].parent = i;
		subsets[i].rank = 1;
	}
	for (int i = 1; i <= q; ++i) {
		scanf ("%d%d", &a, &b);
		Union(find(a), find(b));
	}
	printf("\n");
	for (int i = 1; i <= n; ++i) {
		int t = find(i);
		printf("%d ", subsets[t].rank - 1);
	}
	printf("\n");
	return 0;
}
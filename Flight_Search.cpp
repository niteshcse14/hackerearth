#include<bits/stdc++.h>
using namespace std;
#define maxn 1000
int n;
string dep, arr;
struct flight {
	string fli;
	int cost;
};
flight inp[maxn];
bool cmp(flight a, flight b) {
	if (a.cost == b.cost) {
		return a.fli < b.fli;
	}
	return a.cost < b.cost;
}
int main() {
	cin >> dep >> arr;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		cin >> inp[i].fli >> inp[i].cost;
	}
	sort(inp, inp + n, cmp);
	for (int i = 0; i < n; ++i) {
		cout << inp[i].fli << " "  << inp[i].cost << "\n";
	}
	return 0;
}
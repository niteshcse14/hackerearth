#include <bits/stdc++.h>
using namespace std;
#define maxn 100
#define M 1000010
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long int
int n;
struct node {
	string dep, arr;
	ll cost;
};
struct result {
	vector<string> vect, cost;
};
vector<string> output;
string dep, arr;
map<string, vector<pair<string, int> > > res;
node inp[maxn];
map<string, int> vis;
bool solve(string str, int sum) {
	cout << str << "  ";
	output.pb(str);
	vis[str] = 1;
	if (str == arr) {
		//printf("  %d\n", sum);
		return true;
	}
	for (auto i : res[str]) {
		if (vis[i.f] == 1) continue;
		solve(i.f, sum + i.s);
	}
	printf("\n");
	cout << str << "  "  << "yes\n" ;
	return false;
}
int main() {
	cin >> dep >> arr;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		cin >> inp[i].dep >> inp[i].arr;
		cin >> inp[i].cost;
		vector<pair<string, int> > temp = res[inp[i].dep];
		temp.pb({inp[i].arr, inp[i].cost});
		res[inp[i].dep] = temp;
		//vector <string> temp = res[];
		//res["j"].pb(6);
		//res[inp[i].dep].pb({inp[i].arr, inp[i].cost});
	}
	vis.clear();
	for (auto i : res[dep]) {
		output.clear();
		//cout << i.f << "\n";
		if (solve(i.first, i.second)) {
			printf("True\n");
			for (auto j : output) {
				cout << j << "  ";
			}
			printf("\n");
		}
		printf("\n");
		break;
	}
	return 0;
}
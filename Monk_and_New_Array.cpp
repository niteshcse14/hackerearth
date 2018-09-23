#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int inp[1005][1005];
int n, m;
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			scanf("%d", &inp[i]);
		}
	}
	vector < int > S;
	for(int i = 0; i  <m; ++i){
		S.push_back(inp[0][i]);
	}
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < m; ++j){
			vector < int > it = upper_bound(S.begin(), S.end(), inp[i][j]);
		}
	}
	return 0;
}
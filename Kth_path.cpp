#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int N, M, K;
string str;
//char arr[100][100];
vector< string > arr;
vector< string > ans;
void printAllPath(char path[], int i, int j, int n, int m, int idx){
	if(i == n - 1){
		for(int k = j; k < m; ++k){
			path[idx + k - j] = arr[i][k];
		}
		ans.push_back(path);
		return;
	}
	if(j == m - 1){
		for(int k = i; k < n; ++k){
			path[idx + k - i] = arr[k][j];
		}
		ans.push_back(path);
		return;
	}
	path[idx] = arr[i][j];
	printAllPath(path, i + 1, j, n, m, idx + 1);
	printAllPath(path, i, j + 1, n, m, idx + 1);
}
int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i){
		cin >> str;
		arr.push_back(str);
	}
	char *path = new char[N + M];
	printAllPath(path, 0, 0, N, M, 0);
	//scanf("%d\n", &K);
	cin >> K;
	/*
	if(K > (N + M - 1)){
		printf("-1\n");
		return 0;
	}
	*/
	sort(ans.begin(), ans.end());
	cout << ans[K - 1] << "\n";
	return 0;
}
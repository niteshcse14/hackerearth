#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n, -1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (n + 1) / 2; j++) {
      a[(j + i) % n][i] = i;
    }
    for (int j = 0; j < n / 2 + 1; j++) {
      a[i][(j + i) % n] = i;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j > 0) {
        cout << ' ';
      }
      cout << a[i][j] + 1;
    }
    cout << '\n';
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int MAX = 100010;
  vector<vector<int>> divs(MAX);
  for (int i = 1; i < MAX; i++) {
    for (int j = i; j < MAX; j += i) {
      divs[j].push_back(i);
    }
  }
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector<vector<int>> take(MAX);
  for (int i = 0; i < n; i++) {
    for (int j : divs[a[i]]) {
      take[j].push_back(b[i]);
    }
  }
  vector<int> cc(MAX, 0);
  int ans = -1;
  long long ways = -1;
  for (int z = MAX - 1; z >= 1; z--) {
    vector<int> &v = take[z];
    int sz = (int) v.size();
    if (sz <= 1) {
      continue;
    }
    const int MAGIC = 1000;
    if (sz <= MAGIC) {
      for (int i = 0; i < sz; i++) {
        for (int j = i + 1; j < sz; j++) {
          int cur = z + __gcd(v[i], v[j]);
          if (cur > ans) {
            ans = cur;
            ways = 0;
          }
          ways += (cur == ans);
        }
      }
    } else {
      for (int i : v) {
        for (int j : divs[i]) {
          cc[j]++;
        }
      }
      for (int i = MAX - 1; i >= 1 && z + i >= ans; i--) {
        if (cc[i] >= 2) {
          int cur = z + i;
          if (cur > ans) {
            ans = cur;
            ways = 0;
          }
          ways += (cur == ans) * ((long long) cc[i] * (cc[i] - 1) / 2);
          break;
        }
      }
      for (int i : v) {
        for (int j : divs[i]) {
          cc[j]--;
        }
      }
    }
  }
  cout << ans << " " << ways << '\n';
  return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T, typename S> T expo(T b, S e, const T &m){if(e <= 1)return e == 0?1: b;\
	return (e&1) == 0?expo((b*b)%m, e>>1, m): (b*expo((b*b)%m, e>>1, m))%m;}
template<typename T> T modinv(T a, T mod) { return expo(a, mod-2, mod); }
const int MAXN = 2e5 + 100;
const ll mod = 1e9 + 7;
ll fact[MAXN] = {0}, ifact[MAXN] = {0};
void preprocess() {
	fact[0] = (ifact[0] = 1);
    for(int i = 1; i < MAXN; i++) {
		fact[i] = (fact[i-1]*i)%mod;
	}
	ifact[MAXN-1] = modinv(fact[MAXN-1], mod); ifact[0] = 1;
	for(ll i = MAXN-2; i > 0; i--){
		ifact[i] = (ifact[i+1]*(i+1))%mod;
	}
	assert((fact[2]*ifact[2])%mod == 1);
}
ll nCr(int n, int r) {
  return (fact[n] * ((ifact[n-r] * ifact[r])%mod)) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  int t;
  preprocess();
  cin >> t;
  while(t--) {
    ll a, b, c, d, K;
    cin >> a >> b >> c >> d >> K;
    ll x = abs(a - c);
    ll y = abs(b - d);
    ll res = 0;
    for(ll i = x; i <= K; i++) {
      if(i % 2 == x % 2) {
        ll x1 = (i + x) / 2;
        ll x2 = (i - x) / 2;
        ll j = K - i;
        if(j >= y && j % 2 == y % 2) {
          ll y1 = (j + y) / 2;
          ll y2 = (j - y) / 2;
          ll temp = nCr(K, x1) * nCr(K - x1, x2) % mod;
          temp *= nCr(K - x1 - x2, y1);
          temp %= mod;
          res += temp;
          if(res >= mod) res -= mod;
        }
      }
    }
    cout << res << '\n';
  }
  return 0;
}
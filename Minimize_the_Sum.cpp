#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;

template<class T>
constexpr const T& clamp( const T& v, const T& lo, const T& hi) {
    return v < lo ? lo : hi < v ? hi : v;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<ll> ls(n), rs(n);
    for (int i = 0; i < n; i++) scanf("%lld", &ls[i]);
    for (int i = 0; i < n; i++) scanf("%lld", &rs[i]);
    ll ans = 0, lf = -INF, rg = +INF;
    for (int i = 0; i < n; i++) {
        ll l = ls[i], r = rs[i];
        ans += max(0LL, max(l - rg, lf - r));
        lf = clamp(lf, l, r);
        rg = clamp(rg, l, r);
    }
    printf("%lld\n", ans);
}
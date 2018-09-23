#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
#define f first
#define s second
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
int pa[100011];
int sz[100011];
map<ll,ll>M[100011];
int f(int x) {
    if(pa[x] == x) return x;
    return pa[x] = f(pa[x]);
}
ll ans = 0;
int D;
void join(int u,int v) {
    u = f(u);
    v = f(v);
    if(sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    pa[v] = u;
    for(auto x:M[v]) {
        for(int j=-D;j<=D;j++) {
            if(M[u].find(x.f+j)!=M[u].end()) {
                ans+=x.s*M[u][x.f+j];
            }
        }
    }
    for(auto x:M[v]) {
        M[u][x.f]+=x.s;
    }
}
ll pt[100011];
int A[100011];
int main() {
    int N;
    cin >> N >> D;
    for(int i=1;i<=N;i++) {
        cin >> A[i];
        pa[i] = i;
        sz[i] = 1;
        M[i][A[i]] = 1;
    }
    int u,v;
    vector<pi>E;
    rep(i,N-1) {
        cin >> u >> v;
        E.pb({u,v});
    }
    vector<int>s(N-1);
    rep(i,N-1) {
        cin >> s[i];
        s[i]--;
    }
    for(int i=s.size()-1;i>=0;i--) {
        pt[i] = ans;
        join(E[s[i]].f,E[s[i]].s);
    }
    rep(i,N-1) {
        cout << pt[i] << "\n";
    }
}
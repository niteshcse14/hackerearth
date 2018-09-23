#include <bits/stdc++.h>
using namespace std;
int main() {
    int t, n, s, e, ans, cum;
    cin >>t;
    while(t--){
        cin >> n;
        vector< pair<int,int> > vec;
        for(int i = 0; i < n; i ++ ){
            cin >> s >> e;
            vec.push_back( make_pair(e, 1));
            vec.push_back( make_pair(s, -1));
        }
        sort(vec.begin(), vec.end());
        ans = 0, cum = 0;
        for(int i = 0; i < vec.size(); i ++){
            cum += vec[i].second;
            ans = max(ans , cum);
            //printf("%d %d\n", cum, ans);
        }
        cout << ans << endl;
    }
}
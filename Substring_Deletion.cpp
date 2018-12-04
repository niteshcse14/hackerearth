#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define MOD 1000000007
string s;
ll suffixmask[4000006],dist,n,anslen;
queue<ll>q[27];
ll cnt = 0;
void solve(ll l, ll pos)
{
    if(pos > anslen)
        return;
    else {
        ll i, j;
        for(i = 0; i < 26; i++) {
            if(!q[i].empty()) {
                while(q[i].front() < l)
                    q[i].pop();
                printf("qi %lld %lld %c\n", q[i].front(), l, char(i + 'a'));
                j = q[i].front();
                if((suffixmask[j] & dist) == dist) {
                    printf("Hello  ");
                    cout << (char)('a' + i) << "\n\n";
                    dist = dist^(1 << i);
                    while(q[i].size())
                        q[i].pop();
                    solve(j + 1, pos + 1);
                }
            }
        }
    }
}
int main()
{
        ll i,j,k;
        while(cin>>s)
        {
            s=" "+s;
            n=s.size()-1;
            suffixmask[n+1]=0;
            for(i = 0; i < 26; i++) {
                while(!q[i].empty())
                    q[i].pop();
            }
            for(i = n; i >= 1; i--) {
                suffixmask[i]=(suffixmask[i+1]|(1<<(s[i]-'a')));
            }
            for(i = 1; i <= n; i++) {
                q[s[i]-'a'].push(i);
            }
            dist = suffixmask[1];
            anslen = __builtin_popcount(dist);
            //printf("dist %lld\n", anslen);
            solve(1, 1);
            cout<<"\n";
        }
    return 0;
}
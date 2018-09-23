#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define FOR(i,x,y) for(LL i = (x) ; i <= (y) ; ++i)
#define CLR(x,y) memset(x,y,sizeof(x))
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((LL)(x).size())
#define LL long long
int N;
vector<int> A, B, L;
/// Returns number of elements smaller than m in L
int getSmall(vector<int> &L, int m){
    int cnt = (lower_bound(ALL(L), m) - L.begin());
    return cnt;
}
/// Returns number of elements greater than m in L
int getLarge(vector<int> &L, int m){
    int cnt = (upper_bound(ALL(L), m) - L.begin());
    return SZ(L) - cnt;
}
/// Returns number of elements equals to m in L
int getEqual(vector<int> &L, int m){
    int cnt = (upper_bound(ALL(L), m) - lower_bound(ALL(L), m));
    return cnt;
}
int solve(){
    sort(ALL(A));
    sort(ALL(B));
    sort(ALL(L));
    int med1 = L[N-1], med2 = L[N];
    if(med1 != med2) return -1;
    int smallA = getSmall(A, med1);
    int smallB = getSmall(B, med1);
    int equalA = getEqual(A, med1);
    int equalB = getEqual(B, med1);
    int largeA = getLarge(A, med1);
    int largeB = getLarge(B, med1);
    int smallEqualA = smallA + equalA;
    int smallEqualB = smallB + equalB;
    int largeEqualA = largeA + equalA;
    int largeEqualB = largeB + equalB;
    int LMX = N/2 + 1;
    int A2B = 0, B2A = 0;
    if(equalA == 0){
        B2A += 1;
        equalA += 1;
        equalB -= 1;
    }
    if(equalB == 0){
        A2B += 1;
        equalB += 1;
        equalA -= 1;
    }
    smallEqualA = smallA + equalA;
    smallEqualB = smallB + equalB;
    largeEqualA = largeA + equalA;
    largeEqualB = largeB + equalB;
    if(smallEqualA<LMX){
        int x = LMX - smallEqualA;
        B2A += x;
        smallEqualA += x;
        smallEqualB -= x;
    }
    if(smallEqualB<LMX){
        int x = LMX - smallEqualB;
        A2B += x;
        smallEqualA -= x;
        smallEqualB += x;
    }
    if(largeEqualA<LMX){
        int x = LMX - largeEqualA;
        B2A += x;
        largeEqualA += x;
        largeEqualB -= x;
    }
    if(largeEqualB<LMX){
        int x = LMX - largeEqualB;
        A2B += x;
        largeEqualA -= x;
        largeEqualB += x;
    }
    return max(A2B, B2A);
}
int main() {
    int t, x;
    scanf("%d",&t);
    FOR(cs,1,t){
        A.clear();
        B.clear();
        L.clear();
        scanf("%d",&N);
        FOR(i,1,N){
            scanf("%d",&x);
            A.pb(x);
            L.pb(x);
        }
        FOR(i,1,N){
            scanf("%d",&x);
            B.pb(x);
            L.pb(x);
        }
        LL res = solve();
        printf("%lld\n",res);
    }
}
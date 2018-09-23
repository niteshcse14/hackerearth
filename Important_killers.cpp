#include <bits/stdc++.h>
using namespace std;
vector<int> prime;
// long long get(long long x) {
//     vector<int> vc;
//     vc.push_back(1);
//     set<pair<long long,int> > s;
//     static int I[55];
//     for(int i=0;i<prime.size();i++){
//         I[i] = 1;
//         s.insert(make_pair(prime[i],i));
//     }
//     while(vc.size() < x){
//         pair<long long,int> tmp = *s.begin();
//         s.erase(s.begin());
//         if(tmp.first > vc.back()) {
//             vc.push_back(tmp.first);
//         }
//         int ind = tmp.second;
        
//         assert(I[ind] < vc.size());
//         s.insert(make_pair(prime[ind] * prime[ind] * vc[I[ind]], ind));
//         I[ind]++;
//     }
//     return vc.back();
// }
 
long long get(long long x) {
    int sz = prime.size();
    vector<long long> vc;
    for(int i=0;i<(1<<sz);i++){
        long long p = 1;
        for(int j=0;j<sz;j++){
            if((i>>j)&1){
                p *= 1ll * prime[j];
            }
        }
        vc.push_back(p);
    }
    sort(vc.begin(),vc.end());
    if(vc.size() >= x){
        return vc[x-1];
    } else {
        return -1;
    }
}
 
int main(){
    static bool pr[5006];
    for(int i=2;i<=5e3;i++){
        if(pr[i]){
            continue;
        }
        for(int j=i+i;j<=5e3;j+=i){
            pr[j] = true;
        }
    }
	int t;
	scanf("%d",&t);
	while(t--){
	    int p,x;
	    scanf("%d %d",&p,&x);
	    prime.clear();
	    for(int i=2;i<=p;i++){
	        if(!pr[i])
	            prime.push_back(i);
	    }
	    printf("%lld\n",get(x));
	}
	return 0;
}
/*
vector<char>a_ar={'e'};
vector<char>e_ar={'a','i'};
vector<char>i_ar={'a','e','o','u'};
vector<char>o_ar={'i','u'};
vector<char>u_ar={'a'};
char ans[100000];
int anss=0;
int dp[1000010][50];
const int mod=1000000000+7;
int solve(char ch,int cnt,int n){
    if(cnt==n){
        return 1;
    }
    int res=0;
    if(dp[cnt][ch-'a'])return dp[cnt][ch-'a'];
    if(ch=='a'){
        for(int i=0;i<a_ar.size();++i){
            ans[cnt+1]=a_ar[i];
            res=(res+solve(a_ar[i],cnt+1,n))%mod;
        }
    }
    else if(ch=='e'){
        for(int i=0;i<e_ar.size();++i){
            ans[cnt+1]=e_ar[i];
            res=(res+solve(e_ar[i],cnt+1,n))%mod;
        }
    }
    else if(ch=='i'){
        for(int i=0;i<i_ar.size();++i){
            ans[cnt+1]=i_ar[i];
            res=(res+solve(i_ar[i],cnt+1,n))%mod;
       }
    }
    else if(ch=='o'){
        for(int i=0;i<o_ar.size();++i){
            ans[cnt+1]=o_ar[i];
            res=(res+solve(o_ar[i],cnt+1,n))%mod;
        }
    }
    else if(ch=='u'){
        for(int i=0;i<u_ar.size();++i){
            ans[cnt+1]=u_ar[i];
            res=(res+solve(u_ar[i],cnt+1,n))%mod;
       }
    }
    dp[cnt][ch-'a']=res%mod;
    return dp[cnt][ch-'a']%mod;
}
int magicalStrings(int n){
    int res=solve('a',1,n)%mod;
    res=(res+solve('e',1,n))%mod;
    res=(res+solve('i',1,n))%mod;
    res=(res+solve('o',1,n))%mod;
    res=(res+solve('u',1,n))%mod;
    return res%mod;
}
*/
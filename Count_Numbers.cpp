

    #include<bits/stdc++.h>
    using namespace std;
    #define pb push_back
    #define mp make_pair
    #define F first
    #define S second
    #define MOD 1000000007
    #define pdn(n) printf("%d\n",n)
    #define sl(n) scanf("%lld",&n)
    #define sd(n) scanf("%d",&n)
    #define pn printf("\n")
    typedef pair<int,int> PII;
    typedef vector<PII> VPII;
    typedef vector<long long int> VI;
    typedef vector<VI> VVI;
    typedef long long LL;
    LL mpow(LL a, LL n){LL ret=1,b=a;while(n){if(n&1)
        ret=(ret*b)%MOD;b=(b*b)%MOD;n>>=1;}return ret;}
    int main()
    {
        VI ar;
        vector < VI > pp;
        long long int k,i,j,t,tt,cnt=0,a,b;
        cin >> k >> t;
        ar.resize(k);
        pp.resize(k+1);
        for(i=0; i<k; i++)
            cin >> ar[i];
        for(i=0; i<(1<<k); i++)
        {
            tt=1ll;
            cnt=0;
            for(j=0; j<k; j++)
            {
                if((i&(1ll<<j)))
                {
                    cnt++;
                    tt=tt*ar[j];
                }
            }
            pp[cnt].pb(tt);
        }
        while(t--)
        {
            cin >> a >> b;
            long long int ans=0;
            for(i=0; i<k; i++)
                ans += ((b/ar[i]) - ((a-1)/ar[i]));
            for(i=2; i<=k; i++)
            {
                for(j=0; j<pp[i].size(); j++)
                {
                    if(i&1)
                        ans += ((b/pp[i][j]) - ((a-1)/pp[i][j]));
                    else
                        ans -= ((b/pp[i][j]) - ((a-1)/pp[i][j]));
                }
            }
            cout << ans << endl;
        }
        return 0;
    }


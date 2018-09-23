#include<iostream>
using namespace std;
#define ll long long int
#define MOD 1000000007
ll mul( ll x, ll y)
{ ll ans=1;
while(y>0)
{ if(y&1)
ans=(ans*x);
x=(x*x);
y/=2;
}

return ans;
};
int main()
{
	long long int ans=mul(5,6);
	cout<<ans<<endl;
}
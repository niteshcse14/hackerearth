#include<iostream>
using namespace std;
int main()
{
    long long int T;
    cin>>T;
    while(T--)
    {
        long long int N,M,i,flag=0;
        cin>>N>>M;
        for(i=0;i<=m-1;i++)
        {
            if((i*i)%M==N)
            {
                flag=1;
                cout<<i<<endl;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"-1"<<endl;
        }
    }
}

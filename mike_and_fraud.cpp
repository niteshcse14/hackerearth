#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int N,K,i,j=0,count=0,flag=0,jj=0,mul=1,ii;
    cin>>N>>K;
    int arr[N],arr1[N];
    arr1[0]=0;
    ii=1;
    if(N>=1 && K>=1)
    {
        for(i=0;i<N;i++)
        {
            cin>>arr[i];
            if(arr[i]%K==0)
            {
                arr1[ii]=i;
                ii++;
            }
        }
        long long int sum=0;
        for(i=1;i<ii;i++)
        {
            if(arr1[i-1]==0)
            {
                sum+=(arr1[i]-arr1[i-1]+1)*(N-arr1[i]);
            }
            else
            {
                sum+=(arr1[i]-arr1[i-1])*(N-arr1[i]);
            }
        }
        cout<<sum<<endl;
    }
}

#include<iostream>
using namespace std;
int fib(int n)
{
    int i=0;
    int arr[n+1];
    
    arr[0]=1;
    arr[1]=1;
    for(i=2;i<n;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    return arr[n-1];
}
int main()
{
    long long int N,i=0,j=0,type,Q=0,l,r,dif=0,size=0,ii=0,jj=0,ans,sum;
    cin>>N;
    long long int arr[N];
    for(i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    cin>>Q;
    while(Q--)
    {
        cin>>type>>l>>r;
        dif=r-l+1;
        ans=0;
        sum=0;
        long long int arr1[dif];
        if(type==2)
        {
            for(i=0;i<dif;i++)
            {
                ii=0;
                sum=0;
                for(j=i;j<dif;j++)
                {
                    arr1[ii]=arr[j];
                    sum+=arr1[ii];
                    ans+=fib(sum);
                    
                    ii++;
                }
              }
              cout<<ans%(1000000000+7)<<endl;
         }
         if(type==1)
         {
            arr[l-1]=r;
         }  
     }
     return 0;
}

#include<iostream>
using namespace std;
int main()
{
    long long int N,Q,B,M;
    cin>>N>>Q>>B>>M;
    long long int arr[N],i=0;
    for(i=0;i<N;i++)
    {
        cin>>arr[i];
    }
    while(Q--)
    {
        long long int x,y;
        cin>>x>>y;
        long long int j=0,max=0;
        i=0;
        long long int arr1[M];
        for(i=1;i<=M;i++)
        {
            if((x-(i-1)*y)<=0)
            {
                break;
            }
            else
            {
                arr1[j]=arr[(x-(i-1)*y)-1]+i*B;;
                j++;
            }
        }
        max=arr1[0];
        for(i=0;i<j;i++)
        {
            if(max<arr1[i])
            {
                max=arr1[i];
            }
        }
        cout<<max<<endl;
    }
}

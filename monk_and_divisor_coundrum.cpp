#include<iostream>
using namespace std;
int main()
{
    int n,i=0;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int T;
    cin>>T;
    while(T--)
    {
        int P,Q,count=0;
        cin>>P>>Q;
        for(i=0;i<n;i++)
        {
            if(arr[i]%P==0)
            {
                count++;
            }
            else if(arr[i]%Q==0)
            {
                count++;
            }
            else if(arr[i]%P==0 && arr[i]%Q==0)
            {
                count++;
            }
        }
        cout<<count<<endl;
    }
}

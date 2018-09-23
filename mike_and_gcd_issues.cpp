#include<iostream>
#include<cmath>
using namespace std;
long long int gcd(long long int a,long long int b)
    {
        while(a!=b)
        {
            if(a>b)
                a=a-b;
            else
                b=b-a;
        }
        return a;
    }
    
int main()
{
    long long int N,i=0,j=0,flag=0,temp=0,min=0;
    cin>>N;
    long long int arr[N],arr1[N],arr2[N];
    for(i=0;i<N;i++)
    {
        cin>>arr[i];
    }long long int even,odd;
    long long int index=0;
        for(i=0;i<N;i++)
        {
            temp=0;
            flag=0;
            min=0;
            even=0;
            odd=0;
            
            if(arr[i]%2==0)
            {
                for(j=0;j<N;j++)
                {
                    if(i!=j && gcd(arr[i],arr[j])>1 && arr[j]%2==0)
                    {
                        if(temp==0)
                        {
                            min=abs(i-j);
                            index=j;
                            temp++;    
                        }
                        else if(min>abs(i-j))
                        {
                            min=abs(i-j);
                            index=j;
                        }
                        flag=1;
                    }
                }
            }
            else
            {
                for(j=0;j<N;j++)
                {
                    if(i!=j && gcd(arr[i],arr[j])>1 && arr[j]%2!=0)
                    {
                        if(temp==0)
                        {
                            min=abs(i-j);
                            index=j;
                            temp++;    
                        }
                        else if(min>abs(i-j))
                        {
                            min=abs(i-j);
                            index=j;
                        }
                        flag=1;
                    }
                }
            }
            
            
            if(flag==1)
            {
                cout<<(index+1)<<" ";
            }
            else
            {
                cout<<"-1 ";
            }
        }
        cout<<endl;
}

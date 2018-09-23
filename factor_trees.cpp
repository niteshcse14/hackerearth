#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int x,l,r;
        int i=0,count=0,j=0;
        cin>>x>>l>>r;
        
        for(i=x;i<r;)
        {
               count++; 
               //cout<<i<<endl;
            i=i+x;
            
        }
        //cout<<count<<endl;
        for(i=2;i<=r;i++)
        {
            for(j=i;j<=r;j++)
            {
                if(i*j==r)
                {
                    if(i%x==0 || j%x==0)
                    {
                        cout<<"i = "<<i<<" j = "<<j<<endl;
                        count++;
                    }
                }
                
            }
        }
        //cout<<count<<endl;
    }
}

#include<iostream>
using namespace std;
int main()
{
    string str;
    int K,i=0;
    cin>>str>>K;
    while(K--)
    {
        if(str[i]!='9')
        {
            str[i]='9';
        }
        i++;
    }
    cout<<str<<endl;
}

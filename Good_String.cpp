#include<iostream>
#include<stdlib.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int sum=0;
	string str;
	cin>>str;
	int arr[26];
	for(int i=0;i<26;i++)
	{
		arr[i]=0;
	}
	for(int i=0;i<str.length();i++)
	{
		arr[str[i]-97]+=1;
	}
	for(int i=0;i<26;i++)
	{
		if(arr[i]!=0)
		{
			sum++;
		}
	}
	cout<<str.length()-sum<<endl;
	return 0;
}
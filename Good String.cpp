#include<iostream.h>
using namespace std;
int int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	int arr[26];
	char ch[]=str;
	for(int i=0;i<strlen(str);i++)
	{
		arr[ch[i]]+=1;
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	getline(cin, str);
	int N1, N2;
	cin >> N1 >> N2;
	int convert = (int)(str[N1 - 1]);
	if(convert > 96 && convert < 123)
	{
		convert -= 32;
		str[N1 - 1] = (char)(convert);
	}
	else if(convert < 91 && convert > 64)
	{
		convert += 32;
		str[N1 - 1] = (char)(convert);
	}
	convert = (int)(str[N2 - 1]);
	if(convert > 96 && convert < 123)
	{
		convert -= 32;
		str[N2 - 1] = (char)(convert);
	}
	else if(convert < 91 && convert > 64)
	{
		convert += 32;
		str[N2 - 1] = (char)(convert);
	}
	cout << str << "\n";
	return 0;
}
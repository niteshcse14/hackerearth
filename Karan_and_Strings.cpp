#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	string str;
	scanf("%d", &T);
	while(T--)
	{
		cin >> str;
		stack<char> stack;
		stack.push(str[0]);
		for(int i = 1; i < str.length(); i++)
		{
			char top = stack.top();
			if(stack.size() == 0)
			{
				stack.push(str[i]);
			}
			else if(top != str[i])
			{
				stack.push(str[i]);
			}
			else if(top == str[i])
			{
				stack.pop();
				if(stack.size() == 0)
				{
					stack.push(str[i]);
				}
				else
				{
					if(stack.top() != str[i])
					{
						stack.push(str[i]);
					}
				}
			}
			//printf("%d  %c  %c\n", i, stack.top(), str[i]);
		}
		string ans = "";
		while(!stack.empty())
		{
			ans += stack.top();
			stack.pop();
		}
		for(int i = ans.length() - 1; i >= 0; i--)
		{
			printf("%c", ans[i]);
		}
		printf("\n");
		//printf("%s\n", reverse(ans));
	}
	return 0;
}
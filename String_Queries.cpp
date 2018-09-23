#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int MAXN = (int)(1e5 + 5);
char str[100000];
int N, Q, a, b;
int ans[26];
struct node
{
	node *left;
	node *right;
	int arr[26];
	node(){}
	node(node *l, node *r)
	{
		left = l;
		right = r;
		memset(arr, 0, sizeof(arr));
	}
};
void build(node *n, int low, int high)
{
	if(low == high)
	{
		n->arr[str[low] - 'a'] += 1;
		return;
	}
	int mid = (low + high) / 2;
	n->left = new node(NULL, NULL);
	n->right = new node(NULL, NULL);
	build(n->left, low, mid);
	build(n->right, mid + 1, high);
	for(int i = 0; i < 26; i++)
	{
		n->arr[i] = n->left->arr[i] + n->right->arr[i];
	}
}
int query(node *n, int low, int high, int l, int r)
{
	if(low > high || low > r || high < l)
	{
		return 0;
	}
	if(l <= low && high <= r)
	{
		int cnt = 0;
		//printf("AT  %d   %d\n", low, high);
		for(int i = 0; i < 26; i++)
		{
			ans[i] += n->arr[i];
			//printf("%d  ", n->arr[i]);
		}
		//printf("\n");
		return cnt;
	}
	int mid = (low + high) / 2;
	return query(n->left, low, mid, l, r) + query(n->right, mid + 1, high, l, r);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &N, &Q);
	scanf("%s", str);
	node *root = new node(NULL, NULL);
	build(root, 0, N - 1);
	/*
	for(int i = 0; i < 26; i++)
	{
		printf("%d  ", root->arr[i]);
	}
	printf("\n");
	*/
	while(Q--)
	{
		scanf("%d %d", &a, &b);
		a--;
		b--;
		memset(ans, 0, sizeof(ans));
		query(root, 0, N - 1, a, b);
		
		int check[26];
		memset(check, 0, sizeof(check));
		for(int i = a; i <= b; i++)
		{
			check[str[i] - 'a']++;
		}
		int cnt = 0;
		for(int i = 0; i < 26; i++)
		{
			if(ans[i] > 1)
			{
				cnt++;
			}
			printf("%d  ", ans[i]);
		}
		printf("\n");
		int sum = 0;
		for(int i = 0; i < 26; i++)
		{
			printf("%d  ", check[i]);
			sum += check[i];
		}
		printf("\n%d\n", sum);
		printf("%d\n", cnt);
	}
	return 0;
}
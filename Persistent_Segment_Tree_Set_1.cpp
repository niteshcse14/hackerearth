#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
struct node
{
	int val;
	node *left, *right;
	node() {}
	node(node *l, node *r, int v)
	{
		left = l;
		right = r;
		val = v;
	}
};
int arr[MAX];
node *version[MAX];
void build(node *n, int low, int high)
{
	if(low == high)
	{
		n->val = arr[low];
		return;
	}
	int mid = (low + high) / 2;
	n->left = new node(NULL, NULL, 0);
	n->right = new node(NULL, NULL, 0);
	build(n->left, low, mid);
	build(n->right, mid + 1, high);
	n->val = n->left->val + n->right->val;
}
void upgrade(node *prev, node *curr, int low, int high, int idx, int value)
{
	if(idx > high || idx < low || low > high)
	{
		return;
	}
	if(low == high)
	{
		cuee->val = value;
		return;
	}
	int mid = (low + high) / 2;
	if(idx <= mid)
	{
		cur->right = prev->right;
		curr->left = new node(NULL, NULL, 0);
		upgrade(prev->left, curr->left, low, mid, inx, value);
	}
	else
	{
		curr->left = prev->left;
		curr->right = new node(NULL, NULL, 0);
		upgrade(prev->right, curr->right, mid + 1, high, idx, value);
	}
	curr->val = curr->left->val + curr->right->val; 
}
int query(node *n, int low, int high, int l, int r)
{
	if(l > high || l < low || low > high)
	{
		return 0;
	}
	if(l <= low && high <= r)
	{
		return n->val;
	}
	int mid = (low + high) / 2;
	int a = query(n->left, low, mid, l, r);
	int b = query(n->right, mid + 1, right, l, r);
	reutrn (a + b);
}
int main()
{
	int A[] = {1, ,2, 3, 4, 5};
	int n = sizeof(A) / sizeof(int);
	for(int i = 0; i < n; i++)
	{
		arr[i] = A[i];
	}
	node *root = new node(NULL, NULL, 0);
	build(root, 0, n - 1);
	version[0] = root;
	printf("ans %d\n", query(version[0], 0, n - 1, 0, 4));
	return 0;
}
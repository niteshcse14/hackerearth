#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 55;
const long long INF = 1e16 + 5;
int ar[MAXN];
typedef long long ll;
typedef struct node* pnode;
struct node {
	pnode left, right;
	unsigned int pri;
	ll val, lazyVal;
	ll leftMost, rightMost, best;
};
ll getLeftMost(pnode X) {
	if(X == nullptr) return INF;
	return X -> leftMost;
}
ll getRightMost(pnode X) {
	if(X == nullptr) return -INF;
	return X -> rightMost;
}
ll getBest(pnode X) {
	if(X == nullptr) return INF;
	return X -> best;
}
unsigned int generate() {
	unsigned int x = rand();
	unsigned int y = rand();
	return (x << 16) | y;
}
pnode reassign(pnode X, pnode L, pnode R, unsigned int p, ll v) {
	X -> left = L;
	X -> right = R;
	X -> pri = p;
	X -> val = v;
	X -> best = min(getBest(L), getBest(R));
	X -> leftMost = X -> rightMost = v;
	if(getLeftMost(R) != INF) 
        X -> best = min(X -> best, getLeftMost(R) - X -> rightMost);
	if(getRightMost(L) != INF) 
        X -> best = min(X -> best, X -> leftMost - getRightMost(L));
	X -> leftMost = min(X -> leftMost, getLeftMost(L));
	X -> rightMost = max(X -> rightMost, getRightMost(R));
	return X;
}
pnode reassign(pnode X, pnode L, pnode R) {
	return reassign(X, L, R, X -> pri, X -> val);
}
void apply(pnode X, ll v) {
	X -> lazyVal += v;
	X -> val += v;
	X -> leftMost += v;
	X -> rightMost += v;
}
void down(pnode X) {
	if(X == nullptr) return;
	if(X -> left) apply(X -> left, X -> lazyVal);
	if(X -> right) apply(X -> right, X -> lazyVal);
	X -> lazyVal = 0;
}
pnode getRight(pnode X) {
	down(X);
	while(X -> right != nullptr) {
		down(X);
		X = X -> right;
	}
	down(X);
	return X;
}
pnode getLeft(pnode X) {
	down(X);
	while(X -> left != nullptr) {
		down(X);
		X = X -> left;
	}
	down(X);
	return X;
}
pair<pnode, pnode> split(pnode X, ll v) {
	if(X == nullptr) return make_pair(nullptr, nullptr);
	down(X);
	pair<pnode, pnode> LR;
	if(X -> val < v) {
		LR = split(X -> right, v);
		return make_pair(reassign(X, X -> left, LR.first), LR.second);
	}
	LR = split(X -> left, v);
	return make_pair(LR.first, reassign(X, LR.second, X -> right));
}
pnode merge(pnode L, pnode R) {
	if(L == nullptr) return R;
	if(R == nullptr) return L;
	down(L);
	down(R);
	if(L -> pri > R -> pri) return reassign(L, L -> left, merge(L -> right, R));
	return reassign(R, merge(L, R -> left), R -> right);
}
pnode insert(pnode X, pnode Y) {
	pair<pnode, pnode> LR = split(X, Y -> val);
	return merge(LR.first, merge(Y, LR.second));
}
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	assert(n >= 1 and n <= 200000);
	assert(q >= 1 and q <= 200000);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &ar[i]);
		assert(ar[i] >= 1 and ar[i] <= 1000000000);
	}
	pnode root = nullptr;
	for(int i = 1; i <= n; i++) {
		if(root == nullptr) 
            root = reassign(new node(), nullptr, nullptr, generate(), ar[i]);
		else 
            root = insert(root, reassign(new node(), nullptr, nullptr, generate(), ar[i]));
	}
	while(q--) {
		int type;
		scanf("%d", &type);
		assert(type >= 1 and type <= 3);
		if(type == 1) {
			int x;
			scanf("%d", &x);
			assert(x >= 1 and x <= 1000000000);
			root = insert(root, reassign(new node(), nullptr, nullptr, generate(), x));
		}
		if(type == 2) {
			int l, r;
			scanf("%d%d", &l, &r);
			assert(l <= r and l >= 1 and r <= 1000000000);
			pair<pnode, pnode> LR = split(root, r + 1);
			pnode Third = LR.second;
			pair<pnode, pnode> LRd = split(LR.first, l);
			pnode First = LRd.first;
			pnode Second = LRd.second;
			if(Second == nullptr) {
				root = merge(First, Third);
				continue;
			}
			apply(Second, -l);
			if(First == nullptr) {
				root = merge(Second, Third);
				continue;
			}
			pnode lr = getRight(First);
			pnode rl = getLeft(Second);
			while(rl -> val < lr -> val) {
				pair<pnode, pnode> lfrt = split(Second, rl -> val + 1);
				First = insert(First, lfrt.first);
				Second = lfrt.second;
				if(First == nullptr or Second == nullptr) break;
				lr = getRight(First);
				rl = getLeft(Second);
			}
			root = merge(First, merge(Second, Third));
		}
		if(type == 3) {
			int l, r;
			scanf("%d%d",&l, &r);
			assert(l <= r and l >= 1 and r <= 1000000000);
			pair<pnode, pnode> LR = split(root, r + 1);
			pnode Third = LR.second;
			pair<pnode, pnode> LRd = split(LR.first, l);
			pnode First = LRd.first;
			pnode Second = LRd.second;
			down(Second);
			ll ans = getBest(Second);
			if(ans >= 1000000000) ans = -1;
			printf("%lld\n", ans);
			root = merge(First, merge(Second, Third));
		}
	}
	return 0;
}
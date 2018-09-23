#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define maxn 100010
ll n, temp, rem, a, b;
struct node {
	ll x, y;
};
node inp[maxn];
int main() {
	scanf("%lld", &n);
	for (ll i = 0; i < n; ++i) {
		scanf("%lld%lld", &inp[i].x, &inp[i].y);
	}
	for (ll i = n - 1; i >= 0; --i) {
		a = inp[i].x;
		b = inp[i].y;
		a = a + rem;
		temp = 0;
		if (a % b != 0)
			temp = b - a % b;
		rem += temp;
	}
	printf("%lld\n", rem);
	return 0;
}
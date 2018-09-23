#include <bits/stdc++.h>
using namespace std;
#define maxn 10000010
#define ll long long int
ll n;
ll inp[maxn];
bool flag;
int main() {
	flag = true;
	scanf("%lld", &n);
	for (ll i = 0; i < n; ++i)
		scanf("%lld", &inp[i]);
	if (inp[0] > inp[n - 1]) flag = false;
	for (ll i = 1; i <= (n + 1)/ 2; ++i) {
		if (inp[n - i] >= inp[i - 1] && inp[n - i] <= inp[i]) continue;
		//printf("i %lld\n", i);
		flag = false;
	}
	if (!flag) printf("no\n");
	else printf("yes\n");
	return 0;
}
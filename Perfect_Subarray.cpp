#include <bits/stdc++.h>
using namespace std;
#define maxn 5005
#define M 1000010
#define ll long long int
ll n, sum, cnt;
ll inp[maxn], sq[M];
bool check(ll num) {
	ll temp = sqrt(num);
	if (temp * temp == num) return true;
	return false;
}
int main() {
	//memset(sq, 0, sizeof sq);
	sum = cnt = 0;
	/*
	for (ll i = 1; (i < M) && ((sum + i) < M); i += 2) {
		sum += i;
		sq[sum] = 1;
	}
	*/
	scanf("%lld", &n);
	for (ll i = 0; i < n; ++i) {
		scanf("%lld", &inp[i]);
	}
	for (ll i = 0; i  < n; ++i) {
		sum = 0;
		for (ll j = i; j < n; ++j) {
			sum += inp[j];
			if (check(sum))
				cnt++;
		}
	}
	printf("%lld\n", cnt);
	return 0;
}
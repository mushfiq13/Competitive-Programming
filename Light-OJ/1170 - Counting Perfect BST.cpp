/*
For a root, we have to push some fixed numbers in the left subtree.
Let's choose every possible number as root of left subtree.
Then How many numbers, we can push to this subtree?
Let's say x ways we can push m numbers to this left subtree.
Then if can push m(m>1) numbers for any right subtree, we can do this by x ways.
*/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll lim = (ll)1e10 + 10;
const ll MOD = (int)1e8 + 7;
const int N = (int)1e6;

ll Left[N];
vector<ll> vec;

void pre_cal() {
	set<ll> s;
	for (long long i=2; i*i <= lim; ++i) {
		for (long long j=i*i; j <= lim; j*=i) {
			s.insert(j);
		}
	}

	vec = vector<ll> (s.begin(), s.end());

	// storing possible ways of left subtree.
	Left[1] = 0;
	Left[2] = 1;
	Left[3] = 2;
	// For i, we are storing ways: how many ways we can push (1, 2, 3, ..., i) to the left subtree.
	for (int i=4; i<=1200; ++i) {
		ll cnt = 0;		
		for (int j=1; j<i; ++j) {			
			cnt = (cnt + max(1LL, Left[j]) * max(1LL, Left[i-j]) % MOD + MOD) % MOD;
		}
		Left[i] = cnt;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	pre_cal();

	int t;
	ll a, b;

	scanf("%d", &t);
	for (int cas=1; cas<=t; ++cas) {
		scanf("%lld %lld", &a, &b);		
		int l = lower_bound(vec.begin(), vec.end(), a) - vec.begin() + 1;
		int r = upper_bound(vec.begin(), vec.end(), b) - vec.begin() + 1;		
		ll ans = 0;
		int n = r - l;
		for (int i=1, j=n; i<=n; ++i, --j) {
			ans = (ans + max(1LL, Left[i]) * max(1LL, Left[j]) % MOD + MOD) % MOD;
		}
		printf("Case %d: %lld\n", cas, ans);
	}

	return 0;
}
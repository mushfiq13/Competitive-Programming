#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
const unsigned long long lim = 1000000000000LL;

vector<ull> lucky;
set<ull> veryLucky;

void F(ull cur) {
	if (cur > 1000000000000) return;	
	if (cur > 0) lucky.push_back(cur);
	F(cur * 10 + 4);
	F(cur * 10 + 7);
}

void gen(int i, ull a) {
	if (a > 1 && a <= lim) veryLucky.insert(a);
	if (a > lim || i >= lucky.size()) return;	
	if (a*lucky[i] <= lim) gen(i, a*lucky[i]);
	if (a*lucky[i] <= lim) gen(i+1, a);
}

int main() {
	int t, n;
	
	F(0);
	// sort before call gen(), else some values may not get
	sort(lucky.begin(), lucky.end());
	gen(0, 1);
	for (ull x : lucky) veryLucky.insert(x);	
	//cout << veryLucky.size() << endl;
	vector<ull> vec;
	for (auto x : veryLucky) vec.push_back(x);

	scanf("%d", &t);
	for (int cas=1; cas<=t; ++cas) {
		long long a, b;
		scanf("%lld %lld", &a, &b);
		a = lower_bound(vec.begin(), vec.end(), a) - vec.begin();
		b = upper_bound(vec.begin(), vec.end(), b) - vec.begin();
		printf("Case %d: %d\n", cas, b-a);
	}

	return 0;
}
/*

*/
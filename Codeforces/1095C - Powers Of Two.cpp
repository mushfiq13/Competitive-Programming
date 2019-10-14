//============================================================================
// Name        : Powers Of Two
// Author      : Mushfiqur Rahman
//============================================================================

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e9;

int main() {
	int n, k;
	ll sum = 0;
	vector<int> v;

	cin >> n >> k;

    while (k--) {++sum; v.push_back(1);}
    int r = v.size()-1;
    while (r >= 0 && sum < n) {
        while (sum < n) {
            if (sum+v[r] > n) break;
            sum += v[r];
            v[r] += v[r];
        }
        --r;
    }

    if (sum != n) puts("NO");
    else {
        printf("YES\n%d", v[0]);
        for (int i=1; i<v.size(); ++i) {
            printf(" %d", v[i]);
        }
        puts("");
    }
	return 0;
}

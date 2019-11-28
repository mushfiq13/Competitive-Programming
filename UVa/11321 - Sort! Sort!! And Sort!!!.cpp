#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll, int> a[10005];

bool cmp (pair<ll, int> x, pair<ll, int> y) {
    if (x.second != y.second) return x.second < y.second;
    int q = x.first & 1;
    int r = y.first & 1;
    if (q + r == 1)
        return q > r;
    if (q+r == 2)
        return x.first > y.first;
    if (q+r == 0)
        return x.first < y.first;
}

int main() {
    int n, m;

    while (scanf("%d %d", &n, &m)) {
        printf("%d %d\n", n, m);
        if (n+m == 0) break;
        for (int i=0; i<n; ++i) {
            ll x;
            scanf("%lld", &x);
            a[i] = {x, x%m};
        }

        sort (a, a+n, cmp);

        for (int i=0; i<n; ++i)
            printf("%lld\n", a[i].first);
    }

    return 0;
}

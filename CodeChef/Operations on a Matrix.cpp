#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 10;

ll row[MAX], col[MAX];

int main() {
    int t, n, m, q;

    cin >> t;
    while (t--) {
        scanf("%d %d %d", &n, &m, &q);
        for (int i=1; i<=n; ++i) row[i] = 0;
        for (int i=1; i<=m; ++i) col[i] = 0;
        while (q--) {
            int xi, yi;
            scanf("%d %d", &xi, &yi);
            ++row[xi];
            ++col[yi];
        }
        ll ans = 0, odd = 0;
        for (int i=1; i<=n; ++i)
            if (row[i] & 1) { ans += m; ++odd; }
        for (int i=1; i<=m; ++i) {
            if (col[i] & 1) {ans -= odd; ans += n-odd;}
        }
        printf("%lld\n", ans);
    }
    return 0;
}

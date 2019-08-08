#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

struct data {
    int mx, suffv, prefv, suff, pref;
    data() {}
    data(int mx, int suffv, int prefv, int suff, int pref)
        : mx(mx), suffv(suffv), prefv(prefv), pref(pref), suff(suff) {}
};

int a[MAX];
data seg[4 * MAX];

data combine (data a, data b) {
    data res = data (max(a.mx, b.mx), b.suffv, a.prefv, b.suff, a.pref);
    if (a.suffv == b.suffv)
        res.suff += a.suff;
    if (a.prefv == b.prefv)
        res.pref += b.pref;
    if (a.suffv == b.prefv)
        res.mx = max (res.mx, a.suff + b.pref);
    return res;
}

void build (int v, int L, int R) {
    if (L == R) {
        seg[v] = data (1, a[L], a[L], 1, 1);
        return;
    }
    int mid = (L + R) / 2;
    build (v*2, L, mid);
    build (v*2+1, mid+1, R);
    seg[v] = combine (seg[v*2], seg[v*2+1]);
}

data query (int v, int L, int R, int l, int r) {
    if (l > r) return data (0, 0, 0, 0, 0);
    if (L == l && R == r) return seg[v];
    int mid = (L + R) / 2;
    return combine (
        query (v*2, L, mid, l, min(r, mid)),
        query (v*2+1, mid+1, R, max(l, mid+1), r)
    );
}

int main() {
    int t, n, c, q;

    scanf("%d", &t);
    for (int cs = 1; cs <= t; ++cs) {
        scanf("%d %d %d", &n, &c, &q);
        for (int i=1; i<=n; ++i)
            scanf("%d", &a[i]);

        build (1, 1, n);

        printf("Case %d:\n", cs);
        while (q--) {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%d\n", query (1, 1, n, l, r).mx);
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;

int a[MAX];
int seg[4*MAX];

void update (int v, int L, int R, int pos, int new_val) {
    if (L == R) {
        seg[v] = new_val;
        return;
    }
    int mid = (L + R) / 2;
    int lf = v * 2;
    int rt = v * 2 + 1;
    if (pos <= mid)
        update (lf, L, mid, pos, new_val);
    else
        update (rt, mid+1, R, pos, new_val);
    seg[v] = seg[lf] + seg[rt];
}

int query (int v, int L, int R, int l, int r) {
    if (l > r) return 0;
    if (L == l && R == r)
        return seg[v];
    int mid = (L + R) / 2;
    return query (v*2, L, mid, l, min (mid, r))
            + query (v*2+1, mid+1, R, max (mid+1, l), r);
}

int main() {
    int t, n, k, d;

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &k, &d);
        for (int i=1; i<=n; ++i)
            scanf("%d", &a[i]);

        for (int i=1; i<=4*n; ++i) seg[i] = 0;
        map<int,int> f;
        int ans = MAX;
        for (int i=1; i<=n; ++i) {
            if (f[a[i]]) update (1, 1, n, f[a[i]], 0);
            f[a[i]] = i;
            update (1, 1, n, f[a[i]], 1);
            if (i >= d)
                ans = min (ans, query (1, 1, n, i-d+1, i));
        }
        printf("%d\n", ans);
    }

    return 0;
}

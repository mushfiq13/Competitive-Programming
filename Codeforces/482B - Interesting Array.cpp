#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int
        MAX = 1e5 + 10,
        maxb = 62;

struct info {
    ll val;
    int bit[maxb];
    info() {
        for (int i=0; i<maxb; ++i)
            bit[i] = 0;
    }
};

info seg[4 * MAX];
ll a[MAX];
bool lazy[4 * MAX], cbit[maxb];

void push (int v) {
    int lf = v * 2;
    int rt = v * 2 + 1;
    for (int i=0; i<maxb; ++i) {
        seg[lf].bit[i] = seg[v].bit[i] ? 1 : seg[lf].bit[i];
        seg[rt].bit[i] = seg[v].bit[i] ? 1 : seg[rt].bit[i];
    }
    lazy[v] = 0;
    lazy[lf] = lazy[rt] = 1;
}

void build (int v, int L, int R) {
    if (L == R) {
        ll m = 1, n = 0;
        for (int i=0; i<maxb; ++i, m *= 2)
            if (seg[v].bit[i])
                n += m;
        seg[v].val = a[L] = n;
        return;
    }
    int mid = (L + R) >> 1;
    int lf = v * 2;
    int rt = v * 2 + 1;
    if (lazy[v]) {
        push(v);
    }
    build (lf, L, mid);
    build (rt, mid+1, R);
    seg[v].val = seg[lf].val & seg[rt].val;
}

void update (int v, int L, int R, int l, int r) {
    if (l > r) return;
    if (L == l && R == r) {
        lazy[v] = 1;
        for (int i=0; i<maxb; ++i)
            seg[v].bit[i] = cbit[i] ? 1 : seg[v].bit[i];
        return;
    }
    int mid = (L + R) >> 1;
    int lf = v * 2;
    int rt = v * 2 + 1;
    if (lazy[v]) {
        push(v);
    }
    update (lf, L, mid, l, min(r, mid));
    update (rt, mid+1, R, max(l, mid+1), r);
}

int query (int v, int L, int R, int l, int r) {
    if (L == l && R == r) {
        return seg[v].val;
    }
    int mid = (L + R) >> 1;
    int lf = v * 2;
    int rt = v * 2 + 1;
    if (r <= mid)
        return query (lf, L, mid, l, r);
    if (l > mid)
        return query (rt, mid+1, R, l, r);
    return query (lf, L, mid, l, min(r, mid))
            & query (rt, mid+1, R, max(l, mid+1), r);
}

int main() {
    int n, m, l[MAX], r[MAX], q[MAX];

    cin >> n >> m;

    for (int i=1; i<=m; ++i) {
        cin >> l[i] >> r[i] >> q[i];
        int t = q[i];
        for (int j=0; j<maxb; ++j, t/=2)
            cbit[j] = t%2;
        update (1, 1, n, l[i], r[i]);
    }

    build (1, 1, n);

    for (int i=1; i<=m; ++i) {
        if (query (1, 1, n, l[i], r[i]) != q[i]) {
            puts("NO");
            return 0;
        }
    }

    puts("YES");
    for (int i=1; i<=n; ++i) {
        if (i > 1) putchar(' ');
        printf("%lld", a[i]);
    }
    puts("");

    return 0;
}

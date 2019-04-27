// Maximum sum sub-array
#include <bits/stdc++.h>
using namespace std;

#define SIZE 50001

struct data {
    int sum, pref, suff, ans;
    data() {}
    data(int v) : sum(v), pref(v), suff(v), ans(v) {}
};

int ar[SIZE];
data seg[4*SIZE];

data combine (data l, data r)
{
    data res;
    res.sum = l.sum + r.sum;
    res.suff = max(r.suff, r.sum + l.suff);
    res.pref = max (l.pref, l.sum + r.pref);
    res.ans = max (max (l.ans, r.ans), l.suff + r.pref);
    return res;
}

void build (int node, int L, int R)
{
    if (L == R) {
        seg[node] = data(ar[L]);
        return;
    }
    int mid = (L + R) / 2;
    build (node*2, L, mid);
    build (node*2+1, mid+1, R);
    seg[node] = combine (seg[node*2], seg[node*2+1]);
}

void update (int node, int L, int R, int pos, int new_val)
{
    if (L == R) {
        seg[node] = data(new_val);
        return;
    }
    int mid = (L + R) / 2;
    if (pos <= mid)
        update (node*2, L, mid, pos, new_val);
    else
        update (node*2+1, mid+1, R, pos, new_val);
    seg[node] = combine (seg[node*2], seg[node*2+1]);
}

data get_max (int node, int L, int R, int l, int r)
{
    if (L == l && R == r)
        return seg[node];
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    if (r <= mid)
        return get_max (lf, L, mid, l, r);
    if (l > mid)
        return get_max (rt, mid+1, R, l, r);
    return combine (
        get_max (lf, L, mid, l, mid),
        get_max (rt, mid+1, R, mid+1, r)
    );
}

int main()
{
    int n, m, t, x, y;

    scanf("%d", &n);
    for (int i=1; i<=n; ++i)
        scanf("%d", &ar[i]);

    build (1, 1, n);
    scanf("%d", &m);

    while (m--) {
        scanf("%d %d %d", &t, &x, &y);
        if (t == 1)
            printf("%d\n", get_max (1, 1, n, x, y).ans);
        else
            update (1, 1, n, x, y);
    }

    return 0;
}

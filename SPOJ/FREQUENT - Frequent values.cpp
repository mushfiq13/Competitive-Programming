#include <bits/stdc++.h>
using namespace std;

#define SIZE 100001

struct data {
    int suff, pref, ans;
    data () {}
    data (int suff_, int pref_, int ans_)
            : suff(suff_), pref(pref_), ans(ans_) {}
};

int ar[SIZE];
data seg[4*SIZE];

data combine (data l, data r, int L, int R)
{
    data res = data (r.suff, l.pref, max (l.ans, r.ans));
    int mid = (L + R) / 2;
    if (ar[L] == ar[mid+1])
        res.pref += r.pref;
    if (ar[R] == ar[mid])
        res.suff += l.suff;
    if (ar[mid] == ar[mid+1])
        res.ans = max (res.ans, l.suff + r.pref);
    return res;
}

void build (int node, int L, int R)
{
    if (L == R) {
            seg[node] = data (1, 1, 1);
            return;
    }
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    build (lf, L, mid);
    build (rt, mid+1, R);
    seg[node] = combine (seg[lf], seg[rt], L, R);
}

data query (int node, int L, int R, int l, int r)
{
    if (l > r)
            return data (0, 0, 0);
    if (L == l && R == r)
            return seg[node];
    int mid = (L + R) / 2;
    return combine (
        query (node * 2, L, mid, l, min (r, mid)),
        query (node * 2 + 1, mid+1, R, max (l, mid+1), r),
        L, R
    );
}

int main (int argc, char **argv)
{
    int n, q, x, y;

    while (scanf("%d", &n) and n) {
        scanf("%d", &q);
        for (int i=1; i<=n; ++i)
            scanf("%d", &ar[i]);
        build (1, 1, n);
        while (q--) {
            scanf("%d %d", &x, &y);
            printf("%d\n", query (1, 1, n, x, y).ans);
        }
    }

    return 0;
}

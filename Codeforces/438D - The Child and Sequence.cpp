#include <bits/stdc++.h>
using namespace std;

typedef long long pll;

#define SIZE 100001

struct info {
    pll sum, Max;
    info () {}
    info (pll s, pll mx)
            : sum(s), Max(mx) {}
} seg[4*SIZE];

int ar[SIZE];

void build (int node, int L, int R)
{
    if (L == R) {
            seg[node] = info (ar[L], ar[L]);
            return;
    }
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    build (lf, L, mid);
    build (rt, mid+1, R);
    seg[node] = info (seg[lf].sum + seg[rt].sum, max(seg[lf].Max, seg[rt].Max));
}

void Mod (int node, int L, int R, int l, int r, int x)
{
    if (l > r || seg[node].Max < x)
        return;
    if (L == R) {
            int m = seg[node].sum % x;
            seg[node] = info (m, m);
            return;
    }
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    Mod (lf, L, mid, l, min (r, mid), x);
    Mod (rt, mid+1, R, max (l, mid+1), r, x);
    seg[node] = info (seg[lf].sum + seg[rt].sum, max(seg[lf].Max, seg[rt].Max));
}

void Set (int node, int L, int R, int pos, int x)
{
    if (L == R) {
            seg[node] = info (x, x);
            return;
    }
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    if (pos <= mid)
        Set (lf, L, mid, pos, x);
    else
        Set (rt, mid+1, R, pos, x);
    seg[node] = info (seg[lf].sum + seg[rt].sum, max(seg[lf].Max, seg[rt].Max));
}

pll query (int node, int L, int R, int l, int r)
{
    if (l > r)
            return 0;
    if (L == l && R == r)
            return seg[node].sum;
    int mid = (L + R) / 2;
    return query (node * 2, L, mid, l, min (r, mid))
            + query (node * 2 + 1, mid+1, R, max (l, mid+1), r);
}

int main (int argc, char **argv)
{
    int n, m, t, x, y, v;

    scanf("%d %d", &n, &m);

    for (int i=1; i<=n; ++i)
        scanf("%d", &ar[i]);

    build (1, 1, n);

    while (m--) {
            scanf("%d %d %d", &t, &x, &y);
            if (t == 1)
                    printf("%lld\n", query (1, 1, n, x, y));
            else if (t == 2) {
                    scanf("%d", &v);
                    Mod (1, 1, n, x, y, v);
            }
            else
                Set (1, 1, n, x, y);
    }

    return 0;
}

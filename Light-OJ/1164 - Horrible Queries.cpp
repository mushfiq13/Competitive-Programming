#include <cstdio>
#include <iostream>
using namespace std;

typedef long long pll;

#define SIZE 100001

struct data {
    pll sum, lazy;
    data () {}
    data (int s, int v)
            : sum(s), lazy(v) {}
} seg[4*SIZE];

void propagate (int node, int L, int R)
{
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;

    seg[lf].lazy += seg[node].lazy;
    seg[rt].lazy += seg[node].lazy;
    seg[lf].sum += seg[node].lazy * (mid - L + 1);
    seg[rt].sum += seg[node].lazy * (R - mid);
    seg[node].lazy = 0;
}

void update (int node, int L, int R, int l, int r, int new_val)
{
    if (l > r)
            return;
    if (L == l && R == r) {
            seg[node].sum += (r - l + 1) * new_val;
            seg[node].lazy += new_val;
            return;
    }
    if (seg[node].lazy)
            propagate (node, L, R);
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    update (lf, L, mid, l, min (r, mid), new_val);
    update (rt, mid+1, R, max (l, mid+1), r, new_val);
    seg[node].sum = seg[lf].sum + seg[rt].sum;
}

pll query (int node, int L, int R, int l, int r)
{
    if (l > r)
            return 0;
    if (L == l && R == r)
            return seg[node].sum;
    if (seg[node].lazy)
            propagate (node, L, R);
    int mid = (L + R) / 2;
    return query (node * 2, L, mid, l, min (r, mid))
            + query (node * 2 + 1, mid+1, R, max (l, mid+1), r);
}

int main (int argc, char **argv)
{
    int t, n, c, m, x, y, v, cs=0;

    scanf("%d", &t);

    while (t--) {
            scanf("%d %d", &n, &c);

            for (int i=1; i<=4*n; ++i)
                    seg[i] = data (0, 0);

            printf("Case %d:\n", ++cs);
            while (c--) {
                    scanf("%d %d %d", &m, &x, &y);
                    ++x, ++y;
                    if (m == 0) {
                            scanf("%d", &v);
                            update (1, 1, n, x, y, v);
                    }
                    else
                            printf("%lld\n", query (1, 1, n, x, y));
            }
    }

    return 0;
}

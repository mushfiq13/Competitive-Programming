#include <cstdio>
#include <iostream>
using namespace std;

typedef long long pll;

#define SIZE 100001

struct data {
    pll sum;
    pll prop;
    data () {}
    data (int v, int x)
            : sum(v), prop(x) {}
} seg[4*SIZE];

void build (int node, int L, int R)
{
    seg[node] = data (0, 0);
    if (L == R) {
            return;
    }
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    build (lf, L, mid);
    build (rt, mid+1, R);
}

void update (int node, int L, int R, int l, int r, int add)
{
    if (l > r)
            return;
    if (L == l && R == r) {
            seg[node].prop += add;
            return;
    }
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    update (lf, L, mid, l, min (r, mid), add);
    update (rt, mid+1, R, max (l, mid+1), r, add);
    seg[node].sum = seg[lf].sum + seg[rt].sum + seg[lf].prop * (mid - L + 1) + seg[rt].prop * (R - mid);
}

pll query (int node, int L, int R, int l, int r)
{
    if (l > r)
            return 0;
    if (L == l && R == r)
            return seg[node].sum + seg[node].prop * (r - l + 1);
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    return seg[node].prop * (r - l + 1)
            + query (lf, L, mid, l, min (r, mid))
            + query (rt, mid+1, R, max (l, mid+1), r);

}

int main (int argc, char **argv)
{
    int t, n, c, m, x, y, v;

    scanf("%d", &t);

    while (t--) {
            scanf("%d %d", &n, &c);

            build (1, 1, n);

            while (c--) {
                    scanf("%d %d %d", &m, &x, &y);
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

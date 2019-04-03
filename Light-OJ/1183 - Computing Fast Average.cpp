#include <cstdio>
#include <iostream>
using namespace std;

#define SIZE 100001

struct data {
    int sum, prop, updated;
    data () {}
    data (int s, int v, int u)
            : sum(s), prop(v), updated(u) {}
} seg[4*SIZE];

void propagate (int node, int L, int R)
{
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    seg[lf].updated = seg[rt].updated = 1;
    seg[lf].prop = seg[rt].prop = seg[node].prop;
    seg[lf].sum = seg[lf].prop * (mid - L + 1);
    seg[rt].sum = seg[rt].prop * (R - mid);
}

void update (int node, int L, int R, int l, int r, int new_val)
{
    if (l > r)
            return;
    if (L == l && R == r) {
            seg[node].sum = (r - l + 1) * new_val;
            seg[node].prop = new_val;
            seg[node].updated = 1;
            return;
    }
    if (seg[node].updated)
            propagate (node, L, R);
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    update (lf, L, mid, l, min (r, mid), new_val);
    update (rt, mid+1, R, max (l, mid+1), r, new_val);
    seg[node].sum = seg[lf].sum + seg[rt].sum;
    seg[node].updated = 0;
}

int query (int node, int L, int R, int l, int r)
{
    if (l > r)
            return 0;
    if (L == l && R == r)
            return seg[node].sum;
    if (seg[node].updated)
            propagate (node, L, R);
    int mid = (L + R) / 2;
    return query (node * 2, L, mid, l, min (r, mid))
            + query (node * 2 + 1, mid+1, R, max (l, mid+1), r);
}

int gcd (int a, int b)
{
    if (a == 0) return b;
    return gcd (b%a, a);
}

int main (int argc, char **argv)
{
    int t, n, q, m, x, y, v, cs = 0;

    scanf("%d", &t);

    while (t--) {
            scanf("%d %d", &n, &q);

            for (int i=1; i<=4*n; ++i)
                    seg[i] = data (0, 0, 0);

            printf("Case %d:\n", ++cs);
            while (q--) {
                    scanf("%d %d %d", &m, &x, &y);
                    ++x, ++y;
                    if (m == 1) {
                            scanf("%d", &v);
                            update (1, 1, n, x, y, v);
                    }
                    else {
                            int sum = query (1, 1, n, x, y);
                            if (sum % (y - x + 1) == 0)
                                    printf("%d\n", sum / (y-x+1));
                            else {
                                    int g = gcd (sum, y-x+1);
                                    printf("%d/%d\n", sum / g, (y-x+1) / g);
                            }
                    }
            }
    }

    return 0;
}

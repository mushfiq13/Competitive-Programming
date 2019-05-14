#include <cstdio>
#include <iostream>
using namespace std;

const int Max = 1e5 + 10;

struct data {
    int z, o, t, lazy;
    data() {}
    data (int z, int o, int t, int l) : z(z), o(o), t(t), lazy(l) {}
};

data seg[4*Max];

void build (int node, int L, int R)
{
    if (L == R) {
        seg[node] = data (R-L+1, 0, 0, 0);
        return;
    }
    int mid = (L + R) >> 1;
    build (node*2, L, mid);
    build (node*2+1, mid+1, R);
    seg[node] = data (R-L+1, 0, 0, 0);
}

void propagate (int node, int L, int R)
{
    int mid = (L + R) >> 1;
    int lf = node * 2;
    int rt = node * 2 + 1;

    data now = seg[lf];
    if (seg[node].lazy % 3 == 1)
        seg[lf] = data (now.t, now.z, now.o, now.lazy);
    else if (seg[node].lazy % 3 == 2)
        seg[lf] = data (now.o, now.t, now.z, now.lazy);

    now = seg[rt];
    if (seg[node].lazy % 3 == 1)
        seg[rt] = data (now.t, now.z, now.o, now.lazy);
    else if (seg[node].lazy % 3 == 2)
        seg[rt] = data (now.o, now.t, now.z, now.lazy);

    seg[lf].lazy = (seg[lf].lazy + seg[node].lazy) % 3;
    seg[rt].lazy = (seg[rt].lazy + seg[node].lazy) % 3;
    seg[node].lazy = 0;
}

void update (int node, int L, int R, int l, int r)
{
    if (l > r)
            return;
    if (L == l && R == r) {
            data nw = seg[node];
            seg[node] = data (nw.t, nw.z, nw.o, (nw.lazy+1)%3);
            return;
    }
    if (seg[node].lazy)
            propagate (node, L, R);
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    update (lf, L, mid, l, min (r, mid));
    update (rt, mid+1, R, max (l, mid+1), r);
    seg[node] = data (seg[lf].z + seg[rt].z, seg[lf].o + seg[rt].o, seg[lf].t + seg[rt].t, 0);
}

int query (int node, int L, int R, int l, int r)
{
    if (l > r)
            return 0;
    if (L == l && R == r)
            return seg[node].z;
    if (seg[node].lazy)
            propagate (node, L, R);
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    return query (lf, L, mid, l, min (r, mid))
            + query (rt, mid+1, R, max (l, mid+1), r);
}

int main (int argc, char **argv)
{
    int n, q, m, x, y, v;

    scanf("%d %d", &n, &q);

    build (1, 1, n);

    while (q--) {
        scanf("%d %d %d", &m, &x, &y);
        if (m == 0)
            update (1, 1, n, x+1, y+1);
        else
            printf("%d\n", query (1, 1, n, x+1, y+1));
    }

    return 0;
}

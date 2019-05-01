#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define SIZE 100001

struct Mi {
    int li, ri;
    ll di;
    Mi() {}
    Mi(int li_, int ri_, ll di_) : li(li_), ri(ri_), di(di_) {}
};

struct info {
    ll times = 0, lazy = 0;
};

Mi mi[SIZE];
info Count[4*SIZE];
ll ar[SIZE];
ll seg[4*SIZE];

void push_increasing (int node, int L, int R)
{
    Count[node*2].lazy += Count[node].lazy;
    Count[node*2].times += Count[node].lazy;
    Count[node*2+1].lazy += Count[node].lazy;
    Count[node*2+1].times += Count[node].lazy;
    Count[node].lazy = 0;
}

void update_increasing (int node, int L, int R, int l, int r)
{
    if (l > r)
        return;
    if (L == l && R == r) {
        ++Count[node].lazy ;
        ++Count[node].times ;
        return;
    }
    if (Count[node].lazy)
        push_increasing (node, L, R);
    int mid = (L + R) / 2;
    update_increasing (node*2, L, mid, l, min (r, mid));
    update_increasing (node*2+1, mid+1, R, max (l, mid+1), r);
}

void propagate (int node, int L, int R)
{
    int mid = (L + R) / 2;
    seg[node*2] += seg[node];
    seg[node*2+1] += seg[node];
    seg[node] = 0;
}

void query (int node, int L, int R, int l, int r, ll v)
{
    if (l > r)
        return;
    if (L == l && R == r) {
        seg[node] += v;
        return;
    }
    if (seg[node])
        propagate (node, L, R);
    int mid = (L + R) / 2;
    query (node * 2, L, mid, l, min (r, mid), v);
    query (node * 2 + 1, mid+1, R, max (l, mid+1), r, v);
}

void count_increasing (int node, int L, int R, int n)
{
    if (L == R) {
        query (1, 1, n, mi[L].li, mi[L].ri, mi[L].di * Count[node].times);
        return;
    }
    if (Count[node].lazy)
        push_increasing (node, L, R);
    int mid = (L + R) / 2;
    count_increasing (node*2, L, mid, n);
    count_increasing (node*2+1, mid+1, R, n);
}

void get_ans (int node, int L, int R)
{
    if (L == R) {
        if (L > 1)
            putchar(' ');
        printf("%lld", ar[L] + seg[node]);
        return;
    }
    if (seg[node])
        propagate (node, L, R);
    int mid = (L + R) / 2;
    get_ans (node*2, L, mid);
    get_ans (node*2+1, mid+1, R);
}

int main (int argc, char **argv)
{
    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);
    for (int i=1; i<=n; ++i)
        scanf("%lld", &ar[i]);

    for (int i=1; i<=m; ++i) {
        int l, r;
        ll d;
        scanf("%d %d %lld", &l, &r, &d);
        mi[i] = Mi (l, r, d);
    }

    for (int i=1; i<=k; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        update_increasing (1, 1, m, x, y);
    }

    count_increasing (1, 1, m, n);
    get_ans (1, 1, n);

    return 0;
}

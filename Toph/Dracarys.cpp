#include <bits/stdc++.h>
using namespace std;

#define SIZE 100001

int ar[SIZE];
int seg[4*SIZE];

void build( int node, int L, int R)
{
    if (L == R) {
            seg[node] = ar[L];
            return;
    }
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    build(lf, L, mid);
    build(rt, mid+1, R);
    seg[node] = seg[lf]>seg[rt] ? seg[lf] : seg[rt];
}

int get_max (int node, int L, int R, int l, int r)
{
    if (L == l && R == r)
            return seg[node];
    int mid = (L + R) / 2;
    if (r <= mid)
            return get_max (node*2, L, mid, l, r);
    if (l > mid)
            return get_max (node*2+1, mid+1, R, l, r);
    int a = get_max (node*2, L, mid, l, mid);
    int b = get_max (node*2+1, mid+1, R, mid+1, r);
    return a>b ? a : b;
}

int main()
{
    int t, n, q;

    scanf("%d", &t);

    for (int i=1; i<=t; ++i) {
        printf("Case #%d:\n", i);
        scanf("%d %d", &n, &q);
        for (int i=1; i<=n; ++i)
            scanf("%d", &ar[i]);
        build(1, 1, n);
        while (q--) {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%d\n", get_max(1, 1, n, l, r));
        }
    }

    return 0;
}

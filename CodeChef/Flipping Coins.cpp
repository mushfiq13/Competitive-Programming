#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000001

int on[4*SIZE];
int toggle[4*SIZE];

void propagate (int node, int L, int R)
{
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;

    toggle[node] = 0;
    toggle[lf] ^= 1;
    toggle[rt] ^= 1;

    on[lf] = mid - L + 1 - on[lf];
    on[rt] = R - mid - on[rt];
}

void update (int node, int L, int R, int l, int r)
{
    if (l > r)
            return;
    if (L == l && R == r) {
            on[node] = r - l + 1 - on[node];
            toggle[node] ^= 1;
            return;
    }
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    update (lf, L, mid, l, min (r, mid));
    update (rt, mid+1, R, max (l, mid+1), r);

    if (toggle[node])
            propagate (node, L, R);
    on[node] = on[lf] + on[rt];
}

int query (int node, int L, int R, int l, int r)
{
    if (l > r)
            return 0;
    if (L == l && R == r)
            return on[node];
    if (toggle[node])
            propagate (node, L, R);
    int mid = (L + R) / 2;
    return query (node*2, L, mid, l, min (r, mid))
            + query (node*2+1, mid+1, R, max (l, mid+1), r);
}

int main()
{
    int n, q, c, a, b;

    scanf ("%d %d", &n, &q);

    while (q--) {
            scanf ("%d %d %d", &c, &a, &b);
            ++a, ++b ;
            if (c == 0)
                    update (1, 1, n, a, b);
            else
                    printf ("%d\n", query (1, 1, n, a, b));
    }

    return 0;
}

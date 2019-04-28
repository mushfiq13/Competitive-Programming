// Segment Tree with lazy propagation
#include <bits/stdc++.h>
using namespace std;

#define SIZE 10000001

int seg[4*SIZE+1], mp[SIZE+1];

void propagate (int node)
{
    seg[node*2] = seg[node*2+1] = seg[node];
    seg[node] = 0;
}

void update (int node, int L, int R, int l, int r, int new_val)
{
    if (l > r)
            return;
    if (L == l && R == r) {
            seg[node] = new_val;
            return;
    }
    if (seg[node])
            propagate (node);
    int mid = (L + R) / 2;
    update (node*2, L, mid, l, min (r, mid), new_val);
    update (node*2+1, mid+1, R, max (l, mid+1), r, new_val);
}

int cnt (int node, int L, int R)
{
    if (seg[node]) {
        if (mp[seg[node]])
            return 0;
        mp[seg[node]] = 1;
        return 1;
    }
    if (L == R)
        return 0;
    int mid = (L + R) / 2;
    return cnt (node*2, L, mid)
            + cnt (node*2+1, mid+1, R);
}

int main (int argc, char **argv)
{
    int t, n, l, r;

    scanf("%d", &t);

    while (t--) {
        for (int i=0; i<=4*SIZE; ++i) {
            seg[i] = 0;
            if (i < SIZE)
                mp[i] = 0;
        }

        scanf("%d", &n);
        for (int i=1; i<=n; ++i) {
            scanf("%d %d", &l, &r);
            update (1, 1, SIZE, l, r, i);
        }

        printf("%d\n", cnt (1, 1, SIZE));
    }

    return 0;
}

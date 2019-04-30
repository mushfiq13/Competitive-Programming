#include <bits/stdc++.h>
using namespace std;

#define SIZE 100001

struct info {
    int l, r, x, y;
    info () {}
    info (int ll, int rr, int xx, int yy)
            : l(ll), r(rr), x(xx), y(yy) {}
};

int a[SIZE];
int b[SIZE];
info seg[4*SIZE];

void propagate (int node, int L, int R)
{
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;

    int tmp = L - seg[node].y;
    int d = mid - L;
    seg[node*2] = info (tmp+seg[node].x, tmp+seg[node].x+d, seg[node].x, seg[node].y);

    tmp = mid + 1 - seg[node].y;
    d = R - mid + 1;
    seg[node*2+1] = info (tmp+seg[node].x, tmp+seg[node].x+d, seg[node].x, seg[node].y);

    seg[node] = info (-1, -1, -1, -1);
}

void update (int node, int L, int R, int l, int r, int x, int y)
{
    if (l > r)
            return;
    if (L == l && R == r) {
            int tmp = L - y;
            int d = R - L;
            seg[node] = info (tmp+x, tmp+x+d, x, y);
            return;
    }
    if (seg[node].l != -1)
            propagate (node, L, R);
    int mid = (L + R) / 2;
    update (node*2, L, mid, l, min (r, mid), x, y);
    update (node*2+1, mid+1, R, max(l, mid+1), r, x, y);
}

void query (int node, int L, int R, int pos)
{
    if (L == R) {
            if (seg[node].l != -1) {
                    b[pos] = a[seg[node].l];
                    seg[node] = info (-1, -1, -1, -1);
            }
            return;
    }
    if (seg[node].l != -1)
            propagate (node, L, R);
    int mid = (L + R) / 2;
    if (pos <= mid)
            query (node * 2, L, mid, pos);
    else
            query (node * 2 + 1, mid+1, R, pos);
}

int main (int argc, char **argv)
{
    int n, m, t, x, y, k;

    cin >> n >> m;

    for (int i=1; i <= 4*n; ++i)
            seg[i] = info (-1, -1, -1, -1);

    for (int i=1; i<=n; ++i)
            scanf("%d", &a[i]);
    for (int i=1; i<=n; ++i)
            scanf("%d", &b[i]);

    while (m--) {
            cin >> t;
            if (t == 1) {
                    cin >> x >> y >> k;
                    update (1, 1, n, y, y+k-1, x, y);
            }
            else {
                    int pos;
                    cin >> pos;
                    query (1, 1, n, pos);
                    cout << b[pos]<< endl;
            }
    }

    return 0;
}

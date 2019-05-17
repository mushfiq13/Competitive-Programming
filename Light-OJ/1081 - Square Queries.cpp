#include <bits/stdc++.h>
using namespace std;

#define SIZE 501

int n;
int ar[SIZE][SIZE];
int seg[4*SIZE][4*SIZE];

void build_y (int vx, int lx, int rx, int vy, int ly, int ry)
{
    if (ly == ry) {
        if (lx == rx)
                seg[vx][vy] = ar[lx][ly];
        else
                seg[vx][vy] = max (seg[vx*2][vy], seg[vx*2+1][vy]);
        return;
    }
    int mid = (ly + ry) / 2;
    int lf = vy * 2;
    int rt = vy * 2 + 1;
    build_y (vx, lx, rx, lf, ly, mid);
    build_y (vx, lx, rx, rt, mid+1, ry);
    seg[vx][vy] = max (seg[vx][lf], seg[vx][rt]);
}

void build_x (int vx, int lx, int rx)
{
    if (lx != rx) {
        int mid = (lx + rx) / 2;
        build_x (vx*2, lx, mid);
        build_x (vx*2+1, mid+1, rx);
    }
    build_y (vx, lx, rx, 1, 1, n);
}

int get_y (int vx, int vy, int tly, int try_, int ly, int ry)
{
    if (tly == ly && try_ == ry)
        return seg[vx][vy];
    int mid = (tly + try_) / 2;
    if (ry <= mid)
        return get_y (vx, vy*2, tly, mid, ly, ry);
    if (ly > mid)
        return get_y (vx, vy*2+1, mid+1, try_, ly, ry);
    return max (
            get_y (vx, vy*2, tly, mid, ly, min (ry, mid)),
            get_y (vx, vy*2+1, mid+1, try_, max (ly, mid+1), ry)
    );
}

int get_x (int vx, int tlx, int trx, int lx, int rx, int ly, int ry)
{
    if (tlx == lx && trx == rx)
        return get_y (vx, 1, 1, n, ly, ry);
    int mid = (tlx + trx) / 2;
    if (rx <= mid)
        return get_x (vx*2, tlx, mid, lx, rx, ly, ry);
    if (lx > mid)
        return get_x (vx*2+1, mid+1, trx, lx, rx, ly, ry);
    return max (
            get_x (vx*2, tlx, mid, lx, mid, ly, ry),
            get_x (vx*2+1, mid+1, trx, mid+1, rx, ly, ry)
    );
}

int main()
{
    int t, x, y, s, q, cs=0;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &q);

        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j)
                scanf("%d", &ar[i][j]);

        build_x (1, 1, n);

        printf("Case %d:\n", ++cs);
        while (q--) {
                scanf("%d %d %d", &x, &y, &s);
                printf("%d\n", get_x (1, 1, n, x, x+s-1, y, y+s-1));
        }
    }

    return 0;
}

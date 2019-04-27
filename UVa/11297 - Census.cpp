#include <bits/stdc++.h>
using namespace std;

#define SIZE 501

struct data {
    int Max, Min;
    data() {}
    data(int v) : Max(v), Min(v) {}
};

int n;
int ar[SIZE][SIZE];
data seg[4*SIZE][4*SIZE];

data combine (data l, data r)
{
    data res;
    res.Max = max (l.Max, r.Max);
    res.Min = min (l.Min, r.Min);
    return res;
}

void build_y (int vx, int lx, int rx, int vy, int ly, int ry)
{
    if (ly == ry) {
        if (lx == rx)
                seg[vx][vy] = data (ar[lx][ly]);
        else
                seg[vx][vy] = combine (seg[vx*2][vy], seg[vx*2+1][vy]);
        return;
    }
    int mid = (ly + ry) / 2;
    int lf = vy * 2;
    int rt = vy * 2 + 1;
    build_y (vx, lx, rx, lf, ly, mid);
    build_y (vx, lx, rx, rt, mid+1, ry);
    seg[vx][vy] = combine (seg[vx][lf], seg[vx][rt]);
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

void update_y (int vx, int lx, int rx, int vy, int ly, int ry, int y, int new_val)
{
    if (ly == ry) {
        if (lx == rx)
                seg[vx][vy] = data (new_val);
        else
                seg[vx][vy] = combine (seg[vx*2][vy], seg[vx*2+1][vy]);
        return;
    }
    int mid = (ly + ry) / 2;
    int lf = vy * 2;
    int rt = vy * 2 + 1;
    if (y <= mid)
        update_y (vx, lx, rx, lf, ly, mid, y, new_val);
    else
        update_y (vx, lx, rx, rt, mid+1, ry, y, new_val);
    seg[vx][vy] = combine (seg[vx][lf], seg[vx][rt]);
}

void update_x (int vx, int lx, int rx, int x, int y, int new_val)
{
    if (lx != rx) {
        int mid = (lx + rx) / 2;
        if (x <= mid)
            update_x (vx*2, lx, mid, x, y, new_val);
        else
            update_x (vx*2+1, mid+1, rx, x, y, new_val);
    }
    update_y (vx, lx, rx, 1, 1, n, y, new_val);
}

data get_y (int vx, int vy, int tly, int try_, int ly, int ry)
{
    if (tly == ly && try_ == ry)
        return seg[vx][vy];
    int mid = (tly + try_) / 2;
    if (ry <= mid)
        return get_y (vx, vy*2, tly, mid, ly, ry);
    if (ly > mid)
        return get_y (vx, vy*2+1, mid+1, try_, ly, ry);
    return combine (
            get_y (vx, vy*2, tly, mid, ly, min (ry, mid)),
            get_y (vx, vy*2+1, mid+1, try_, max (ly, mid+1), ry)
    );
}

data get_x (int vx, int tlx, int trx, int lx, int rx, int ly, int ry)
{
    if (tlx == lx && trx == rx)
        return get_y (vx, 1, 1, n, ly, ry);
    int mid = (tlx + trx) / 2;
    if (rx <= mid)
        return get_x (vx*2, tlx, mid, lx, rx, ly, ry);
    if (lx > mid)
        return get_x (vx*2+1, mid+1, trx, lx, rx, ly, ry);
    return combine (
            get_x (vx*2, tlx, mid, lx, mid, ly, ry),
            get_x (vx*2+1, mid+1, trx, mid+1, rx, ly, ry)
    );
}

int main()
{
    int x1, y1, x2, y2, val, q;

    scanf("%d", &n);

    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            scanf("%d", &ar[i][j]);

    build_x (1, 1, n);

    scanf("%d", &q);
    while (q--) {
        char c;
        cin >> c;
        if (c =='c') {
            scanf("%d %d %d", &x1, &y1, &val);
            update_x (1, 1, n, x1, y1, val);
        }
        else {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            data res = get_x (1, 1, n, x1, x2, y1, y2);
            printf("%d %d\n", res.Max, res.Min);
        }
    }

    return 0;
}

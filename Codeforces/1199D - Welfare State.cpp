#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;

struct data {
    int mx, mn;
    data() {}
    data(int mx, int mn)
        :  mx(mx), mn(mn) {}
};

int a[MAX];
bool prop[4 * MAX];
data seg[4 * MAX];

data combine (data a, data b) {
    return data (max(a.mx, b.mx), min(a.mn, b.mn));
}

void push (int v) {
    prop[v] = 0;
    prop[v*2] = prop[v*2+1] = 1;
    seg[v*2] = seg[v*2+1] = seg[v];
}

void build (int v, int L, int R) {
    if (L == R) {
        seg[v] = data (a[L], a[L]);
        return;
    }
    int mid = (L + R) / 2;
    build (v*2, L, mid);
    build (v*2+1, mid+1, R);
    seg[v] = combine (seg[v*2], seg[v*2+1]);
}

void update (int v, int L, int R, int pos, int x) {
    if (L == R) {
        seg[v] = data (x, x);
        return;
    }
    if (prop[v]) {
        push (v);
    }
    int mid = (L + R) / 2;
    if (pos <= mid)
        update (v*2, L, mid, pos, x);
    else
        update (v*2+1, mid+1, R, pos, x);
    seg[v] = combine (seg[v*2], seg[v*2+1]);
}

void update (int v, int L, int R, int x) {
    if (seg[v].mx < x) {
        seg[v] = data (x, x);
        prop[v] = 1;
        return;
    }
    if (L == R) {
        return;
    }
    if (prop[v])
        push (v);
    int mid = (L + R) / 2;
    if (seg[v*2].mn < x)
        update (v*2, L, mid, x);
    if (seg[v*2+1].mn < x)
        update (v*2+1, mid+1, R, x);
    seg[v] = combine (seg[v*2], seg[v*2+1]);
}

void query (int v, int L, int R) {
    if (L == R) {
        if (L > 1) putchar(' ');
        cout << seg[v].mn;
        return;
    }
    if (prop[v])
        push (v);
    int mid = (L + R) / 2;
    query (v*2, L, mid);
    query (v*2+1, mid+1, R);
}

int main() {
    int n, q, c, p, x;

    scanf("%d", &n);
    for (int i=1; i<=n; ++i)
        scanf("%d", &a[i]);

    build (1, 1, n);

    scanf("%d", &q);

    while (q--) {
        scanf("%d", &c);
        if (c == 1) {
            scanf("%d %d", &p, &x);
            update (1, 1, n, p, x);
        }
        else {
            scanf("%d", &x);
            update (1, 1, n, x);
        }
    }

    query (1, 1, n);
    puts("");

    return 0;
}

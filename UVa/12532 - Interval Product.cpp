#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 10;

struct data {
    bool zero;
    int neg;
    data() { zero = neg = 0; }
};

int ar[MAX];
data seg[4*MAX];

data make_data (int v)
{
    data res;
    if (!v) res.zero = 1;
    else if (v < 0) res.neg = 1;
    return res;
}

data combine (data l, data r)
{
    data res;
    res.zero = l.zero + r.zero;
    res.neg = l.neg + r.neg;
    return res;
}

void build (int node, int L, int R)
{
    if (L == R) {
            seg[node] = make_data (ar[L]);
            return;
    }
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    build (lf, L, mid);
    build (rt, mid+1, R);
    seg[node] = combine (seg[lf], seg[rt]);
}

void update (int node, int L, int R, int pos, int v)
{
    if (L == R) {
            seg[node] = make_data (v);
            return;
    }
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    if (pos <= mid)
            update (lf, L, mid, pos, v);
    else
            update (rt, mid+1, R, pos, v);
    seg[node] = combine (seg[lf], seg[rt]);
}

data query (int node, int L, int R, int l, int r)
{
    if (l > r)
            return data ();
    if (L == l && R == r) {
            return seg[node];
    }
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    return combine (
            query (lf, L, mid, l, min (r, mid)),
            query (rt, mid+1, R, max (l, mid+1), r)
    );
}

int main (int argc, char **argv)
{
    int n, q, x, y;
    char ch;

    while (~scanf("%d %d", &n, &q)) {
            for (int i = 1; i <= n; ++i)
                    scanf("%d", &ar[i]);
            build (1, 1, n);
            while (q--) {
                cin >> ch >> x >> y;
                if (ch == 'C')
                        update (1, 1, n, x, y);
                else {
                        data p = query (1, 1, n, x, y);
                        if (p.zero) printf("0");
                        else if (p.neg % 2) printf("-");
                        else printf("+");
                }
            }
            puts("");
    }

    return 0;
}

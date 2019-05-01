#include <bits/stdc++.h>
using namespace std;

#define SIZE 100001

struct data {
    int Max, sMax;
    data () {}
    data (int Max_, int sMax_)
            : Max(Max_), sMax(sMax_) {}
};

int ar[SIZE];
data seg[4*SIZE];

data combine (data l, data r)
{
    int a = max (max (max (l.Max, r.Max), l.sMax), r.sMax);
    int b;
    if (a == l.Max)
        b = max (max (r.Max, l.sMax), r.sMax);
    else if (a == r.Max)
        b = max (max (l.Max, l.sMax), r.sMax);
    else if (a == l.sMax)
        b = max (max (l.Max, r.Max), r.sMax);
    else
        b = max (max (l.Max, r.Max), l.sMax);
    return data (a, b);
}

void build (int node, int L, int R)
{
    if (L == R) {
            seg[node] = data (ar[L], 0);
            return;
    }
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    build (lf, L, mid);
    build (rt, mid+1, R);
    seg[node] = combine (seg[lf], seg[rt]);
}

void update (int node, int L, int R, int pos, int new_val)
{
    if (L == R) {
        seg[node] = data (new_val, 0);
        return;
    }
    int mid = (L + R) / 2;
    if (pos <= mid)
        update (node*2, L, mid, pos, new_val);
    else
        update (node*2+1, mid+1, R, pos, new_val);
    seg[node] = combine (seg[node*2], seg[node*2+1]);
}

data query (int node, int L, int R, int l, int r)
{
    if (l > r)
            return data (0, 0);
    if (L == l && R == r)
            return seg[node];
    int mid = (L + R) / 2;
    return combine (
        query (node * 2, L, mid, l, min (r, mid)),
        query (node * 2 + 1, mid+1, R, max (l, mid+1), r)
    );
}

int main (int argc, char **argv)
{
    int n, q, x, y;
    char ch;

    scanf("%d", &n);

    for (int i=1; i<=n; ++i)
        scanf("%d", &ar[i]);

    build (1, 1, n);

    scanf("%d", &q);
    while (q--) {
        scanf(" %c %d %d", &ch, &x, &y);
        if (ch == 'U')
            update (1, 1, n, x, y);
        else {
            data ans = query (1, 1, n, x, y);
            printf("%d\n", ans.Max + ans.sMax);
        }
    }

    return 0;
}

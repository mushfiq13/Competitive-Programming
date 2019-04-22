#include <bits/stdc++.h>
using namespace std;

#define SIZE 200005

int ar[SIZE];
int seg[4*SIZE];

void build (int node, int L, int R)
{
    if (L == R) {
        seg[node] = ar[L];
        return;
    }
    int mid = (L + R) / 2;
    build (node*2, L, mid);
    build (node*2+1, mid+1, R);
    seg[node] = seg[node*2] + seg[node*2+1];
}

void update (int node, int L, int R, int pos, int new_val)
{
    if (L == R) {
        seg[node] = new_val;
        return;
    }
    int mid = (L + R) / 2;
    if (pos <= mid)
        update (node*2, L, mid, pos, new_val);
    else
        update (node*2+1, mid+1, R, pos, new_val);
    seg[node] = seg[node*2] + seg[node*2+1];
}

int query (int node, int L, int R, int l, int r)
{
    if (l > r)
        return 0;
    if (L == l && R == r)
        return seg[node];
    int mid = (L + R) / 2;
    return query(node*2, L, mid, l, min(r, mid))
            + query(node*2+1, mid+1, R, max(l, mid+1), r);
}

int main()
{
    int n, x, y, cs = 0;
    string s;

    while (scanf("%d", &n) && n) {
        if (cs)
            puts("");

        for (int i=1; i<=n; ++i)
            scanf("%d", &ar[i]);

        build(1, 1, n);

        printf("Case %d:\n", ++cs);
        while (cin >> s) {
            if (s == "END")
                break;
            cin >> x >> y;
            if (s == "S")
                update (1, 1, n, x, y);
            else
                printf("%d\n", query (1, 1, n, x, y));
        }
    }

    return 0;
}

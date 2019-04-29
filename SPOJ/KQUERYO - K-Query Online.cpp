// Segment Tree with vector

#include <bits/stdc++.h>
using namespace std;

#define SIZE 30001
#define INF 10000000

int ar[SIZE];
vector<int> seg[4*SIZE];

void build (int node, int L, int R)
{
    if (L == R) {
            seg[node] = vector<int> (1, ar[L]);
            return;
    }
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    build (lf, L, mid);
    build (rt, mid + 1, R);
    merge (seg[lf].begin(), seg[lf].end(), seg[rt].begin(),
            seg[rt].end(), back_inserter (seg[node]));
}

int query (int node, int L, int R, int l, int r, int x)
{
    if (l > r)
        return 0;
    if (L == l && R == r) {
            return seg[node].end() - upper_bound (seg[node].begin(), seg[node].end(), x);
    }
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    return query (lf, L, mid, l, min (r, mid), x)
           + query (rt, mid+1, R, max (l, mid+1), r, x);
}

int main (int argc, char **argv)
{
    int n, q, a, b, c, x;

    scanf ("%d", &n);

    for (int i=1; i<=n; ++i)
        scanf ("%d", &ar[i]);

    build (1, 1, n);

    scanf ("%d", &q);
    int last_ans = 0;
    while (q--) {
        scanf ("%d %d %d", &a, &b, &c);
        a ^= last_ans;
        b ^= last_ans;
        c ^= last_ans;
        if (a < 1)
            a = 1;
        if (b > n)
            b = n;
        int ans = query (1, 1, n, a, b, c);
        printf ("%d\n", ans);
        last_ans = ans;
    }

    return 0;
}

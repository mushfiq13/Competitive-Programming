#include <cstdio>
#include <iostream>
using namespace std;

#define SIZE 100001

typedef pair<int,int> PII;

int ar[SIZE];
PII tree[4*SIZE];

PII combine (PII l, PII r)
{
    PII res;
    res.first = max (l.first, r.first);
    res.second = min (l.second, r.second);
    return res;
}

void build (int at, int L, int R)
{
    if (L == R) {
        tree[at] = make_pair(ar[L], ar[L]);
        return;
    }
    int mid = (L + R) / 2;
    build (at*2, L, mid);
    build (at*2+1, mid+1, R);
    tree[at] = combine (tree[at*2], tree[at*2+1]);
}

PII query (int at, int L, int R, int l, int r)
{
    if (l > r)
        return make_pair(0,1000000005);
    if (L == l && R == r)
        return tree[at];
    int mid = (L + R) / 2;
    return combine (
        query (at*2, L, mid, l, min (mid, r)),
        query (at*2+1, mid+1, R, max (mid+1, l), r)
    );
}

int main (int argc, char **argv)
{
    int t, n, d, cs=0;

    cin >> t;

    while (t--) {
        cin >> n >> d;

        for (int i=1; i<=n; ++i)
            cin >> ar[i];

        build (1, 1, n);

        int ans = 0;
        for (int i=1; i+d-1<=n; i++) {
            PII p = query (1, 1, n, i, i+d-1);
            ans = max (ans, p.first-p.second);
        }

        printf("Case %d: %d\n", ++cs, ans);
    }

    return 0;
}

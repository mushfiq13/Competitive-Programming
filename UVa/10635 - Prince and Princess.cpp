#include <bits/stdc++.h>
using namespace std;

vector<int> seg;

void update(int v, int L, int R, int pos, int val) {
    if (L == R) {
        seg[v] = val;
        return;
    }
    int mid = (L + R) / 2;
    if (pos <= mid)
        update(v*2, L, mid, pos, val);
    else
        update(v*2+1, mid+1, R, pos, val);
    seg[v] = max(seg[v*2], seg[v*2+1]);
}

int query(int v, int L, int R, int l, int r) {
    if (l > r) return 0;
    if (L == l && R == r) return seg[v];
    int mid = (L + R) / 2;
    return max (
        query(v*2, L, mid, l, min(r, mid)),
        query(v*2+1, mid+1, R, max(l, mid+1), r)
    );
}

int main() {
    int t, n, p, q;

    cin >> t;
    for (int Case=1; Case<=t; ++Case) {
        cin >> n >> p >> q;

        ++p, ++q;

        int A[p+1], B[q+1];
        int posA[n*n+5] = {0};

        for (int i=1; i<=p; ++i) {
            cin >> A[i];
            posA[A[i]] = i;
        }

        int m = 0, r[p+1];
        for (int i=1; i<=q; ++i) {
            cin >> B[i];
            if (posA[B[i]])
                r[++m] = posA[B[i]];
        }

        seg.assign(4*m+10, 0);

        int ans = 0;
        for (int i=1; i<=m; ++i) {
            int val = query(1, 1, m, 1, r[i]-1) + 1;
            update(1, 1, m, r[i], val);
            ans = max(ans, val);
        }

        printf("Case %d: %d\n", Case, ans);
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int MAX = 1e5 + 10;

pii blue[MAX], red[MAX];
vector<int> seg[4*MAX];

bool cmp (pii a, pii b) {
    return a.first < b.first;
}

int upper (int tar, int l, int h) {
    int idx = -1;
    while (l <= h) {
        int mid = (l + h) >> 1;
        if (red[mid].first > tar) {
            idx = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    return idx;
}

int lower (int tar, int l, int h) {
    int idx = -1;
    while (l <= h) {
        int mid = (l + h) >> 1;
        if (red[mid].first < tar) {
            idx = mid;
            l = mid + 1;
        }
        else
            h = mid - 1;
    }
    return idx;
}

void build (int v, int L, int R) {
    if (L == R) {
        seg[v] = vector<int> (1, red[L].second);
        return;
    }
    int mid = (L + R) >> 1;
    int lf = v * 2;
    int rt = v * 2 + 1;
    seg[v].clear();
    build (lf, L, mid);
    build (rt, mid+1, R);
    merge (seg[lf].begin(), seg[lf].end(), seg[rt].begin(),
           seg[rt].end(), back_inserter(seg[v]));
}

ll get_distinct (int v, int L, int R, int l, int r, int x, int t) {
    if (l > r) return 0;
    if (L == l && R == r) {
        if (t == 1)
            return seg[v].end() - lower_bound (seg[v].begin(), seg[v].end(), x);
        return upper_bound (seg[v].begin(), seg[v].end(), x) - seg[v].begin();
    }
    int mid = (L + R) >> 1;
    return get_distinct (v*2, L, mid, l, min(r, mid), x, t)
            + get_distinct (v*2+1, mid+1, R, max(l, mid+1), r, x, t);
}

int main() {
    int t, n, m;

    scanf("%d", &t);
    for (int cs = 1; cs <= t; ++cs) {
        scanf("%d %d", &n, &m);
        for (int i=0; i<n; ++i) {
            int p, q;
            scanf("%d %d", &p, &q);
            blue[i] = make_pair(p, q);
        }
        for (int i=0; i<m; ++i) {
            int p, q;
            scanf("%d %d", &p, &q);
            red[i] = make_pair(p, q);
        }

        sort (red, red+m, cmp);
        build (1, 0, m-1);

        ll ans = 0;
        for (int i=0; i<n; ++i) {
            int up = upper (blue[i].first, 0, m-1);
            int lo = lower (blue[i].first, 0, m-1);
            ans += get_distinct (1, 0, m-1, 0, lo, blue[i].second, 1);
            if (up > -1)
                ans += get_distinct (1, 0, m-1, up, m-1, blue[i].second, 2);
        }

        printf("Case %d: %lld\n", cs, ans);
    }

    return 0;
}

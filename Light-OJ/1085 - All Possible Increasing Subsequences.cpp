#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const ll MOD = 1000000007;
const int MAX = 1e5 + 10;

vector<pii> v;
ll seg[4 * MAX];

bool cmp (pii a, pii b) {
    return a.first != b.first ? a.first < b.first : a.second > b.second;
}

void update (int v, int L, int R, int pos, ll newVal) {
    if (L == R) {
        seg[v] = newVal;
        return;
    }
    int mid = (L + R) / 2;
    int lf = v * 2;
    int rt = v * 2 + 1;
    if (pos <= mid)
        update (lf, L, mid, pos, newVal);
    else
        update (rt, mid+1, R, pos, newVal);
    seg[v] = seg[lf] + seg[rt];
}

ll query (int v, int L, int R, int l, int r) {
    if (l > r) return 0;
    if (L == l && R == r)
        return seg[v];
    int mid = (L + R) / 2;
    return (query (v*2, L, mid, l, min(r, mid))
            + query (v*2+1, mid+1, R, max(l, mid+1), r)) % MOD;
}

int main() {
    int t, n;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; ++cs) {
        scanf("%d", &n);

        v.clear();
        for(int i=1; i<=4*n; ++i)
            seg[i] = 0;

        for (int i=1; i <= n; ++i) {
            ll x;
            scanf("%lld", &x);
            v.push_back(make_pair(x,i));
        }

        sort(v.begin(), v.end(), cmp);

        ll ans = 0;
        for (int i=n-1; i>=0; --i) {
            ll sum = 1 + query (1, 1, n, v[i].second+1, n);
            update (1, 1, n, v[i].second, sum);
            ans = (ans + sum) % MOD;
        }

        printf("Case %d: %lld\n", cs, ans);
    }

    return 0;
}

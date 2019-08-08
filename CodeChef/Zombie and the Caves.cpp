#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;
typedef long long ll;

map<ll,ll> mp;
ll c[MAX], h[MAX];
ll seg[4 * MAX];

void update (int v, int L, int R, ll l, ll r) {
    if (r < L || R < l)
        return;
    if (L >= l && R <= r) {
        ++seg[v] ;
        return;
    }
    if (L == R) {
        return;
    }
    int mid = (L + R) / 2;
    update (v*2, L, mid, l, r);
    update (v*2+1, mid+1, R, l, r);
}

void query (int v, int L, int R) {
    if (L == R) {
        ++mp[seg[v]] ;
        return;
    }
    if (seg[v]) {
        seg[v*2] += seg[v];
        seg[v*2+1] += seg[v];
        seg[v] = 0;
    }
    int mid = (L + R) / 2;
    query (v*2, L, mid);
    query (v*2+1, mid+1, R);
}

int main() {
    int t;
    ll n;

    scanf("%d", &t);
    while (t--) {
        scanf("%lld", &n);

        for (int i=1; i<=n; ++i) {
            scanf("%lld", &c[i]);
            seg[i] = 0;
        }

        for (int i=1; i<=n; ++i) {
            scanf("%lld", &h[i]);
            seg[n+i] = 0;
        }

        for (int i=n*2+1; i <= 4*n; ++i)
            seg[i] = 0;

        for (ll i=1; i<=n; ++i) {
            update (1, 1, n, max(1LL, i-c[i]), min(n, i+c[i]));
        }

        mp.clear();
        query (1, 1, n);

        bool flag = true;
        for (int i=1; i<=n && flag; ++i) {
            if (!mp[h[i]])
                flag = false;
            else
                --mp[h[i]] ;
        }

        if (flag)
            puts("YES");
        else
            puts("NO");
    }

    return 0;
}

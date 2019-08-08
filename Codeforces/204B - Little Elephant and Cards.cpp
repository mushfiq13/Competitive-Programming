#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5 + 10;
const int INF = 1e9 + 10;

ll ft[MAX], bk[MAX];
map<ll, ll> a, b;

int main() {
    ll n, mxft = 0, mx = 0;

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> ft[i] >> bk[i];
        ++a[ft[i]] ;
        if (ft[i] != bk[i])
            ++b[bk[i]] ;
        mxft = max (mxft, a[ft[i]]);
        mx = max (mx, a[ft[i]] + b[ft[i]]);
        mx = max (mx, a[bk[i]] + b[bk[i]]);
    }

    if (mxft*2 >= n) {
        puts("0");
        return 0;
    }
    if (mx < n/2 + n%2) {
        puts("-1");
        return 0;
    }

    ll mn = INF;
    for (int i=1; i<=n; ++i) {
        ll cnt = a[ft[i]] + b[ft[i]];
        if (cnt*2 >= n)
            mn = min(n/2 + n%2 - a[ft[i]], mn);
        cnt = a[bk[i]] + b[bk[i]];
        if (cnt*2 >= n)
            mn = min(n/2 + n%2 - a[bk[i]], mn);
    }

    cout << mn << endl;

    return 0;
}

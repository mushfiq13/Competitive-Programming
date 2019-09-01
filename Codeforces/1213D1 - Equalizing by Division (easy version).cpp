#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9 + 7;
const int MAX = 2e5 + 10;

int a[MAX];
map <ll, ll> f1, f2, op;

int main() {
    int n, k;
    bool zero = false;

    cin >> n >> k;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        ++f1[a[i]] ;
        if (f1[a[i]] == k)
            zero = true;
    }

    if (zero) {
        puts("0");
        return 0;
    }

    sort (a+1, a+n+1);

    ll ans = INF;
    for (int i=1; i<=n; ++i) {
        int cnt = 0;
        while (a[i] > 0) {
            a[i] /= 2;
            ++cnt;
            ++f2[a[i]];
            op[a[i]] += cnt;
            if (f1[a[i]] + f2[a[i]] == k)
                ans = min (ans, op[a[i]]);
        }
    }

    cout << ans << endl;

    return 0;
}

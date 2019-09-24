#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<int, int> pii;

const int MAX = 1e3 + 10;

int m[MAX][MAX];

bool ok (int d, int n) {
    ll ans[n+1];
    ans[1] = d;
    for (int i=2; i<=n; ++i) {
        if (m[i-1][i] % d) { return 0; }
        else d = m[i-1][i] / d;
        ans[i] = d;
    }
    for (int i=1; i<=n; ++i)
        for (int j=i+1; j<=n; ++j)
            if (ans[i] * ans[j] != m[i][j])
                return 0;
    return 1;
}

int main() {
    int n, x = 1e9;

    cin >> n;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j) {
            cin >> m[i][j];
            if (i==1 && j>1) x = min (x, m[i][j]);
        }

    int d;
    for (ll i=1; i*i <= x; ++i) {
        if (x%i == 0) {
            if (ok (i, n)) { d = i; break; }
            if (i*i == x) continue;
            if (ok (x/i, n)) { d = x/i; break; }
        }
    }

    printf("%d", d);
    for (int i=2; i<=n; ++i) {
        d = m[i-1][i] / d;
        printf(" %d", d);
    }
    puts("");

    return 0;
}

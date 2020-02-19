#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 105;

int s[MAX];
ll a[MAX];

int main() {
    int t, n;
    ll d;

    scanf("%d", &t);
    for (int cs = 1; cs <= t; ++cs) {
        scanf("%d %lld", &n, &d);

        for (int i=1; i<=n; ++i) {
            char ch, hyp;
            cin >> ch >> hyp >> a[i];
            s[i] = 0;
            if (ch == 'S') s[i] = 1;
        }

        a[n+1] = d;

        ll mx = 0;
        for (int i=1; i<=n; ++i) {
            if (s[i] == 0)
                mx = max (mx, max (a[i]-a[i-1], a[i+1]-a[i]));
            else
                mx = max (mx, a[i+1]-a[i-1]);
        }
        printf("Case %d: %lld\n", cs, mx);
    }

    return 0;
}

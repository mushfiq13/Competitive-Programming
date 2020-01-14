#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t, n;
    ll a, b, c, d, e;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);

        ll r = 10;
        for (int i=2; i<=n; ++i)
            r = r * 10;

        scanf("%lld", &a);

        ll s = 2 * r + a;
        printf("%lld\n", s);
        fflush(stdout);

        scanf("%lld", &b);

        ll c = r - b;
        printf("%lld\n", c);
        fflush(stdout);

        scanf("%lld", &d);
        ll e = r - d;
        printf("%lld\n", e);
        fflush(stdout);

        int out;
        scanf("%d", &out);
        if (out == -1) break;
    }

    return 0;
}

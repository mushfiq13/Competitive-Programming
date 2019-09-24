#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int q, c, m, x;

    cin >> q;
    while (q--) {
        cin >> c >> m >> x;
        int ans = 0;
        if (x) {
            int d = min (min (c, m), x);
            ans += d;
            c -= d;
            m -= d;
        }
        if (c > m) swap (c, m);
        while (c+m>=3 && (c>=2 && m>=1) || (c>=1 && m>=2)) {
            int d = (m-c) / 2;
            int mn = min (c, d);
            if (mn == 0) break;
            c -= mn;
            m -= mn*2;
            ans += mn;
        }
        if ((c>=2 && m>=1) || (c>=1 && m>=2))
            ans += (c+m) / 3;
        printf("%d\n", ans);
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int r, b[35];

void set_bin (ll n) {
    while (n)
        b[r++] = n % 2, n /= 2;
}

int shift_a_bit () {
    int pos = -1;

    for (int i=0; i+1<r; ++i)
        if (b[i] && !b[i+1]) {
            b[i] = 0; b[i+1] = 1;
            pos = i; break;
        }

    if (pos == -1) {
        pos = r;
        b[r-1] = 0; b[r++] = 1;
    }

    return pos;
}

ll get_deci () {
    ll m = 1, ans = 0;
    for (int i=0; i<r; ++i, m *= 2)
        if (b[i])
            ans += m;
    return ans;
}

int main() {
    ll n;
    int t;

    scanf("%d", &t);
    for (int cs = 1; cs <= t; ++cs) {
        scanf("%lld", &n);

        r = 0;
        set_bin (n);
        int pos = shift_a_bit();
        ll ans = get_deci ();

        while (true) {
            for (int i=0; i<pos; ++i)
                if (!b[i] && b[i+1]) {
                    b[i] = 1, b[i+1] = 0;
                    break;
                }
            ll temp = get_deci ();
            if (temp > n && temp != ans) ans = temp;
            else break;
        }

        printf("Case %d: %d\n", cs, ans);
    }

    return 0;
}

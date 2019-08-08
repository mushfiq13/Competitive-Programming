#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll Pow[35];
int pos;

ll shift_a_bit (ll n) {
    ll t = n;
    pos = -1;
    for (int i=0, prev = 0; n > 0; ++i) {
            if (prev && n%2 == 0)
                return t - Pow[i-1] + Pow[i];
            prev = n % 2;
            n /= 2;
            ++pos;
    }
    return t - Pow[pos] + Pow[pos+1];
}

ll solve (ll Min, ll n) {
    int prev;
    ll temp, m;
    while (true) {
            prev = Min % 2;
            temp = Min;
            m = Min / 2;
            for (int i = 1; i < pos; ++i) {
                    if (!prev && m%2) {
                        temp = temp - Pow[i] + Pow[i-1];
                        break;
                    }
                    prev = m % 2;
                    m /= 2;
            }
            if (temp > n && temp < Min) Min = temp;
            else break;
    }
    return Min;
}

int main() {
    ll n = 1;
    int t;

    for (int i=0; i < 32; ++i) {
        Pow[i] = n;
        n *= 2;
    }

    scanf("%d", &t);
    for (int cs = 1; cs <= t; ++cs) {
        scanf("%lld", &n);
        ll ans = solve (shift_a_bit(n), n);
        printf("Case %d: %d\n", cs, ans);
    }

    return 0;
}

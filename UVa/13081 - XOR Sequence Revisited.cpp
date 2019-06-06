#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(ll l, ll r)
{
    if (r-l>2) {
        puts("0");
        return;
    }

    bool eve=0, one=0, od=0, zero=0;
    for (ll v = l; v <= l+5 && v <= r; ++v) {
        if (v%4 == 0) od = 1;
        else if (v%4 == 1) zero = 1;
        else if (v%4 == 2) eve = 1;
        else if (v%4 == 3) one = 1;
    }

    if ((one && eve) || zero)
        puts("0");
    else if ((one && od) || one)
        puts("1");
    else if (l%4 == 0)
        cout << l+1 << endl;
    else
        cout << l << endl;
}

int main ()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        ll l, r;
        scanf("%lld %lld", &l, &r);
        solve(l, r);
    }
    return 0;
}

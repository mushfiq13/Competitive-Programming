#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int sol (ll n)
{
    ll val = n;
    n = llabs(n);
    for (ll i=2; i*i <= n; ++i) {
        if (n % i == 0) {
            ll m = n;
            int p = 0;
            while (m % i == 0)
                m /= i, ++p;
            if (val>0 && m == 1) return p;
            else if (val < 0 && p%2 && m == 1) return p;
        }
    }
    return 1;
}

int main()
{
    ll n;

    while (cin >> n, n) {
        cout <<  sol(n) << endl;
    }


    return 0;
}

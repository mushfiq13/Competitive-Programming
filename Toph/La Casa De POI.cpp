#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, m, sum = 0;

    scanf("%lld %lld", &n, &m);

    if (n > m)
        swap (n, m);

    for (ll i = 1; i*i <= n; ++i) {
        if (n%i == 0) {
            if (m%i == 0)
                sum += i;
            if (i*i != n && m%(n/i) == 0)
                sum += n/i;
        }
    }

    printf("%lld\n", sum);

    return 0;
}

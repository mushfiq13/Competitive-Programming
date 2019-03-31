#include <cstdio>
using namespace std;

typedef long long LL;

LL bigMod (LL n, LL p, LL m)
{
    if (p == 0) return 1;
    if (p%2 == 0) {
        LL R = bigMod(n, p/2, m);
        return R*R % m;
    } else {
        LL R = bigMod(n, p/2, m);
        return R*R*n % m;
    }
}

int main ()
{
    int t, cs = 1;
    LL n, k, mod;

    scanf ("%d", &t);

    while (t--) {
        scanf ("%lld %lld %lld", &n, &k, &mod);

        LL res = 0, i;
        for (i = 1; i <= n; i++) {
            LL x;
            scanf("%lld", &x);
            res = (res + x%mod) % mod;
        }

        res = k%mod * bigMod(n,k-1,mod)%mod * res%mod;

        printf ("Case %d: %lld\n", cs++, res);
    }

    return 0;
}

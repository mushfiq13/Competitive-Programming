#include <stdio.h>

int main ()
{
    int t, i, cs = 1;
    long long res, n;

    scanf ("%d", &t);

    while (t--){
        scanf("%lld", &n);

        res = 0;
        int sq = sqrt(n*1.0);
        for (i = 1; i <= sq; ++i)
            res += n/i;

        printf ("Case %d: %lld\n", cs++, res*2 - sq*sq);
    }

    return 0;
}

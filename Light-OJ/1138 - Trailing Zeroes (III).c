#include <stdio.h>

typedef long long LL;

int binary_search (LL Q)
{
    LL l = 1, h = 400000020;
    LL mid, P = 0;

    while (l <= h) {
            mid = l + (h-l) / 2;

            int cnt = 0;
            LL n = mid;
            while (n >= 5) {
                cnt += n/5;
                n /= 5;
            }

            if (cnt == Q) {
                P = mid;
                h = mid-1;
            }
            else if (cnt > Q)
                h = mid-1;
            else
                l = mid+1;
    }

    return P;
}

int main ()
{
    int T, cs = 1;
    LL Q;

    scanf ("%d", &T);

    while (T--) {
            scanf ("%lld", &Q);
            LL n = binary_search (Q);
            if (n)
                printf ("Case %d: %lld\n", cs++, n);
            else
                printf ("Case %d: impossible\n", cs++);
    }

    return 0;
}

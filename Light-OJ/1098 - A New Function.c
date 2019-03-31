#include <stdio.h>

int main ()
{
    int t, n, cs = 1;
    long long i, ans;

    scanf ("%d", &t);

    while (t--) {
            scanf ("%d", &n);

            ans = 0;
            for (i = 2; i*i <= n; i++) {
                int l = n/i;
                ans += (l-i+1) * (i+l) / 2;
                ans += (l-i) * i;
            }

            printf ("Case %d: %lld\n", cs++, ans);
    }

    return 0;
}

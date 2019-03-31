#include <stdio.h>

int main ()
{
    int t, n, cs = 1;
    long long k, res;

    scanf ("%d", &t);

    while (t--) {
        scanf ("%d %lld", &n, &k);

        int i;
        for (i=2, res=0; i<=n; i++)
            res = (res+k)%i;

        printf ("Case %d: %lld\n", cs++, res+1);
    }

    return 0;
}

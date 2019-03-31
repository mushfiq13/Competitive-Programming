#include <stdio.h>

int main ()
{
    int t, cs = 1;
    long long n, m;

    scanf ("%d", &t);

    while (t--){
            scanf ("%lld %lld", &n, &m);
            printf ("Case %d: %llu\n", cs++, (n/2 * (n+1+m)/2) - (n/2 * (n-m+1)/2));
    }

    return 0;
}

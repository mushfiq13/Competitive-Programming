#include <stdio.h>

int main ()
{
    int t, cs = 1;
    long long w, i, N, M;

    scanf ("%d", &t);

    while (t--){
        scanf ("%lld", &w);

        if (w%2) {
            printf ("Case %d: Impossible\n", cs++);
            continue;
        }

        long long a = 0, b = 0;
        for (i = 2; i*i <= w; i++){
            if (w%i == 0){
                N = i;
                M = w / i;
                if ((N%2 && M%2==0) || (N%2==0 && M%2)) {
                    a = N, b = M;
                    if (i%2 == 0) break;
                }
            }
        }

        printf ("Case %d: ", cs++);

        if (a%2==0 && b%2==0) {
            puts("Impossible");
        }
        else {
            if (a%2 == 0 && b%2 == 1)
                printf ("%lld %lld\n", b, a);
            else if (a%2 == 1 && b%2 == 0)
                printf ("%lld %lld\n", a, b);
        }
    }

    return 0;
}

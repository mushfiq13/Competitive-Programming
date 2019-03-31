#include <stdio.h>
#include <math.h>
#define size 10000099

typedef long long LL;

int mark[size/2];
LL PM[664599];

void siv ()
{
    LL i, j, k;

    k = 1;
    for (i = 3; i <= size; i+=2) {
        if (mark[i/2] == 0) {
            PM[k++] = i;
            if (i*i <= size)
                for (j = i*i; j <= size; j+=i+i)
                    mark[j/2] = 1;
        }
    }
    PM[0] = 2;
}

int sol (LL n)
{
    LL i, c, ans = 1;

    while (n%2 == 0) n/=2;

    for (i = 1; PM[i]*PM[i] <= n; i++) {
        if (n%PM[i] == 0) {
            c = 0;
            while (n%PM[i] == 0) {
                n /= PM[i];
                c++;
            }
            ans *= c+1;
        }
    }
    if (n > 1) ans *= 2;

    return ans-1;
}

int main ()
{
    LL n;
    int t, cs = 1;

    siv ();
    scanf ("%d", &t);

    while (t--) {
            scanf ("%lld", &n);

            printf ("Case %d: %d\n", cs++, sol(n));
    }

    return 0;
}

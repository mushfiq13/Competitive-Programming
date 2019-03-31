#include <stdio.h>
#define size 1000007

typedef long long LL;

int mark[size/2];
LL PM[79000];

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
    int i, c, ans = 1;

    for (i = 0; PM[i]*PM[i] <= n; i++) {
        if (n%PM[i] == 0) {
            c = 0;
            while (n%PM[i] == 0) {
                c ++;
                n /= PM[i];
            }
            ans *= c+1;
        }
    }
    if (n > 1) ans *= 2;

    return ans-1;
}

int main ()
{
    int T, cs = 1;
    LL N;

    siv();
    scanf ("%d", &T);

    while (T--) {
        scanf ("%lld", &N);
        printf ("Case %d: %d\n", cs++, sol(N));
    }

    return 0;
}

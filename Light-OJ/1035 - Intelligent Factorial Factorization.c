#include <stdio.h>

int PM[50];

void siv ()
{
    int i, j, k = 0;
    int mark[102] = {};

    PM[k++] = 2;
    for (i = 3; i <= 101; i+=2) {
        if (mark[i] == 0) {
            PM[k++] = i;
            if (i <= 10)
                for (j = i*i; j <= 101; j+=i+i)
                    mark[j] = 1;
        }
    }
}

void sol (int n)
{
    int i, count, val, flag = 0;

    for (i = 0; PM[i] <= n; i++) {
        val = n;
        count = 0;
        while (val >= PM[i]) {
            count += val / PM[i];
            val /= PM[i];
        }
        if (count && flag)
            printf (" * ");
        printf ("%d (%d)", PM[i], count);
        flag = 1;
    }
    printf ("\n");
}

int main ()
{
    int T, N, cs = 1;

    siv();
    scanf ("%d", &T);

    while (T--) {
        scanf ("%d", &N);
        printf ("Case %d: %d = ", cs++, N);
        sol (N);
    }

    return 0;
}

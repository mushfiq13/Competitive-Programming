#include <stdio.h>

int main ()
{
    int t, n, p, q, i, gm, cs = 1;

    scanf ("%d", &t);

    while (t--){
            scanf("%d %d %d", &n, &p, &q);

            if (n < p)
                p = n;

            int sum = 0, cnt = 0;
            for (i = 0; i < n; i++){
                    scanf ("%d", &gm);
                    if (i < p){
                        sum += gm;
                        if (sum <= q)
                            cnt++;
                    }
            }

            printf ("Case %d: %d\n", cs++, cnt);
    }

    return 0;
}

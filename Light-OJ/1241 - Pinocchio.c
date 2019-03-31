#include <stdio.h>

int main ()
{
    int t, n, i, cs = 1;
    int val, prev;

    scanf ("%d", &t);

    while (t--){
            scanf ("%d", &n);

            int cnt = 0, sm = 0;
            for (i = 0; i<n; ++i){
                    scanf ("%d", &val);

                    if (i == 0) sm = val - 2;
                    else sm = val - prev;

                    cnt += sm/5;
                    if (sm%5 != 0)
                        cnt++;
                    prev = val;
            }

            printf ("Case %d: %d\n", cs++, cnt);
    }

    return 0;
}

#include <stdio.h>

int main ()
{
    int t, n, i, count, Case = 1;

    scanf ("%d", &t);

    while (t--){
            scanf ("%d", &n);

            count = 0;
            while (n > 0){
                    count += n%2;
                    n /= 2;
            }

            if (count%2 == 0)
                printf ("Case %d: even\n", Case++);
            else
                printf ("Case %d: odd\n", Case++);
    }

    return 0;
}

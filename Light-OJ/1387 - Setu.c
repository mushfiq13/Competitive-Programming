#include <stdio.h>

int main ()
{
    int t, n, k, Case, amount;
    char s[20], s2[] = "report";

    scanf ("%d", &t);

    Case = 1;
    while (t--){
            scanf ("%d", &n);

            amount = 0;
            printf ("Case %d:\n", Case);

            while (n--){
                    scanf (" %s", s);
                    if (strcmp(s, s2) == 0)
                        printf ("%d\n", amount);
                    else{
                        scanf ("%d", &k);
                        amount += k;
                    }
            }

            Case ++;
    }

    return 0;
}

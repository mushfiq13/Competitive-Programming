#include <stdio.h>

int main ()
{
    int t, i, Case = 1, deci[10];
    long long bin[10];
    char ch;

    scanf("%d", &t);

    while (t--){
            for (i = 0; i < 4; i++){
                    scanf ("%d", &deci[i]);
                    if (i < 3)
                        scanf("%c", &ch);
            }

            int con = 1;
            for (i = 0; i < 4; i++){
                    scanf("%lld",&bin[i]);
                    if (i < 3)
                        scanf("%c", &ch);

                    int mul = 1, rev = 0;
                    long long num = bin[i];
                    while (num != 0){
                            rev += mul * (num%10);
                            num /= 10;
                            mul *= 2;
                    }

                    if (rev != deci[i] && con == 1)
                        con = 0;
            }

            if (con == 0)
                printf ("Case %d: No\n", Case++);
            else
                printf ("Case %d: Yes\n", Case++);
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

int main ()
{
    int t, i, cs = 1;
    long long B, mod;
    char A[1000];

    scanf ("%d ", &t);

    while (t--) {
            scanf (" %s %lld", A, &B);

            mod = i = 0;
            if (!isdigit(A[0]))
                i++;

            while (A[i] != '\0') {
                    mod = (mod*10 + A[i]-'0') % B;
                    i++;
            }

            if (mod)
                printf ("Case %d: not divisible\n", cs++);
            else
                printf ("Case %d: divisible\n", cs++);
    }

    return 0;
}

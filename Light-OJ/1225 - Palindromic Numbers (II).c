#include <stdio.h>

int main ()
{
    int t, i, j, cs = 1;
    char s[100];

    scanf ("%d", &t);

    while (t--){
            scanf(" %s", s);

            int len = strlen(s);
            for (i=0, j = len-1; i <= len/2; ++i, --j)
                if (s[i] != s[j])
                    break;

            if (i > len/2)
                printf ("Case %d: Yes\n", cs++);
            else
                printf ("Case %d: No\n", cs++);
    }

    return 0;
}

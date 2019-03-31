#include <stdio.h>
#include <string.h>

int main ()
{
    short t, n, i, cs;
    char ch;

    scanf ("%hd ", &t);

    cs = 1;
    while (t--) {
            int freqFirst[27] = {};
            int freqSecond[27] = {};
            n = 2;

            while (n--) {
                    while (ch=getchar(), ch!='\n') {
                            if (isupper(ch))
                                ch += 32;
                            if (n)
                                freqFirst[ch-'a']++;
                            else
                                freqSecond[ch-'a']++;
                    }
            }

            for (i = 0; i < 26; i++)
                if (freqFirst[i] != freqSecond[i])
                    break;

            if (i == 26)
                printf ("Case %d: Yes\n", cs++);
            else
                printf ("Case %d: No\n", cs++);
    }

    return 0;
}

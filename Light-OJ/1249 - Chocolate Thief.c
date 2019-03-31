#include <stdio.h>

int main ()
{
    short t, n, i, cs = 1;
    short volume[100];
    char name[100][50];

    scanf ("%hd", &t);

    while (t--) {
            scanf ("%hd", &n);

            i = 0;
            while (i < n) {
                    short len, wid, high;
                    scanf (" %s %hd %hd %hd", name[i], &len, &wid, &high);
                    volume[i] = len*wid*high;
                    i++;
            }

            short mx = volume[0];
            short min = volume[0];
            short victim = 0, thif = 0;

            for (i = 1; i < n; i++) {
                    if (mx < volume[i]) {
                        thif = i;
                        mx = volume[i];
                    } else if (min > volume[i]) {
                        victim = i;
                        min = volume[i];
                    }
            }

            if (victim || thif) {
                printf ("Case %hd: %s took chocolate from %s\n", cs++, name[thif], name[victim]);
            } else {
                printf ("Case %hd: no thief\n", cs++);
            }
    }

    return 0;
}

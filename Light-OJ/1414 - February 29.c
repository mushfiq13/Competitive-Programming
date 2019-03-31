#include <stdio.h>

int isMatch (char mn[])
{
    if (strcmp(mn, "January") == 0)
        return 1;
    if(strcmp(mn, "February") == 0)
        return 2;

    return 0;
}

int main ()
{
    int t, cs = 1;
    int d1, d2, y1, y2;
    char m1[15], m2[15];

    scanf ("%d", &t);

    while (t--){
            scanf (" %s %d, %d", m1, &d1, &y1);
            scanf (" %s %d, %d", m2, &d2, &y2);

            if (!isMatch(m1)) y1++;
            int tmp = isMatch(m2);
            if (tmp==1 || (tmp==2 && d2 < 29)) y2--;

            int ans = y2/4 - (y1-1)/4;
            ans -= y2/100 - (y1-1)/100;
            ans += y2/400 - (y1-1)/400;

            printf ("Case %d: %d\n", cs++, ans);
    }

    return 0;
}

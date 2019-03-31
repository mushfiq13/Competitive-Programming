#include <stdio.h>

int main ()
{
    int t, x1, x2, y1, y2, m;
    int a, b, cs = 0;

    scanf ("%d", &t);

    while (t--){
            scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);
            scanf ("%d", &m);

            printf ("Case %d:\n", ++cs);
            while (m--){
                scanf ("%d %d", &a, &b);

                if (a >= x1 && a <= x2 && b >= y1 && b <= y2)
                    puts ("Yes");
                else
                    puts ("No");
            }
    }

    return 0;
}

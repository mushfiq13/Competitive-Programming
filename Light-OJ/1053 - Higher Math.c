#include <stdio.h>

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main ()
{
    int a, b, c, T, cs = 0;

    scanf ("%d", &T);

    while (T--) {
        scanf ("%d %d %d", &a, &b, &c);

        if (a > c && a > b)
            swap (&a, &c);
        else if (b > a && b > c) {
            swap (&b, &c);
        }

        if (a*a + b*b == c*c)
            printf ("Case %d: yes\n", ++cs);
        else
            printf ("Case %d: no\n", ++cs);
    }

    return 0;
}

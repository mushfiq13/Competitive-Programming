#include <stdio.h>

void swap (int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int main ()
{
    char ch;
    int t, n, m, i, j, y, z;
    int num, Case = 1;
    int a[100];

    scanf ("%d", &t);

    while (t--){
            scanf ("%d %d", &n, &m);

            for (i = 0; i < n; i++)
                scanf ("%d", &a[i]);

            while (m--){
                    scanf (" %c", &ch);
                    switch(ch)
                    {
                        case 'R':
                                j = 0;
                                for (i = n-1; i >= n/2; i--){
                                    swap (&a[i], &a[j]);
                                    j++;
                                }
                                break;
                        case 'P':
                                scanf ("%d %d", &y, &z);
                                swap (&a[y], &a[z]);
                                break;
                        case 'S':
                                scanf ("%d", &num);
                                for (i = 0; i < n; i++)
                                    a[i] += num;
                                break;
                        case 'M':
                                scanf ("%d", &num);
                                for (i = 0; i < n; i++)
                                    a[i] *= num;
                                break;
                        default:
                                scanf ("%d", &num);
                                for (i = 0; i < n; i++)
                                    a[i] /= num;
                    }
            }

            printf ("Case %d:\n%d", Case++, a[0]);
            for (i = 1; i < n; i++)
                printf (" %d", a[i]);
            puts("");
    }

    return 0;
}

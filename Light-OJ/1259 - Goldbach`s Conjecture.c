#include <stdio.h>
#include <math.h>
#define size 10000007

typedef long long LL;

int mark[size/2];
int PM[664579];

void siv ()
{
    LL i, j, k;

    k = 1;
    for (i = 3; i <= size; i+=2) {
        if (mark[i/2] == 0) {
            PM[k++] = i;
            if (i*i <= size)
                for (j = i*i; j <= size; j+=i+i)
                    mark[j/2] = 1;
        }
    }
    PM[0] = 2;
}

int BS (int n, int l, int h)
{
    int m;
    while (l <= h) {
        m = l + (h-l)/2;
        if (PM[m] == n) return m;
        else if (PM[m] > n) h = m - 1;
        else l = m + 1;
    }

    if (PM[m] > n) m--;
    return m;
}

int main ()
{
    int t, n, i, c, cs = 1;

    siv();
    scanf ("%d", &t);

    while (t--) {
            scanf ("%d", &n);

            int h = BS(n, 0, 664578);
            i = c = 0;
            while (i <= h) {
                    if (PM[i]+PM[h] == n)
                        c++, i++, h--;
                    else if (PM[i]+PM[h-1] >= n)
                        h--;
                    else if (PM[i+1]+PM[h] <= n)
                        i++;
                    else i++, h--;
            }

            printf ("Case %d: %d\n", cs++, c);
    }

    return 0;
}

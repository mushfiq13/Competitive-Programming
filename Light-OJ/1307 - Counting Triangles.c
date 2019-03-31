#include <stdio.h>

int cmp (const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int BS (int n1, int n2, int ar[], int hi)
{
    int lo = 0, indx = -1;

    while (lo <= hi) {
        int mid = (lo+hi)/2;
        if (n1+n2 > ar[mid] && n1+ar[mid] > n2 && n2+ar[mid] > n1) {
            indx = mid;
            lo = mid+1;
        }
        else if (ar[mid] <= n2)
            lo = mid+1;
        else hi = mid-1;
    }

    return indx;
}

int sol (int ar[], int n)
{
    int i, j, c = 0;

    for (i = 0; i < n; i++) {
        for (j = i+1; j < n; j++) {
            int tmp = BS(ar[i], ar[j], ar, n-1);
            if (tmp-j > 0)
                c += tmp-j;
        }
    }

    return c;
}

int main ()
{
    int T, N, i, cs = 1, ar[2000];

    scanf ("%d", &T);

    while (T--) {
        scanf ("%d", &N);
        for (i = 0; i < N; i++)
            scanf ("%d", &ar[i]);

        qsort (ar, N, sizeof(int), cmp);

        printf ("Case %d: %d\n", cs++, sol(ar, N));
    }

    return 0;
}

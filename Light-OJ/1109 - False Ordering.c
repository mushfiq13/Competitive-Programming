#include <stdio.h>

#define SIZE 1000

typedef struct {
    int x, d;
} N;

int mark[101];
int PM[101];

void siv ()
{
    int i, j, k = 0;

    PM[k++] = 2;
    for (i = 3; i <= 100; i+=2) {
        if (mark[i]) continue;
        PM[k++] = i;
        if (i*i >= 100) continue;
        for (j = i*i; j <= 100; j+=i+i)
            mark[j] = 1;
    }
}

int NOD (int n)
{
    int i, ans = 1;
    for (i = 0; PM[i]*PM[i] <= n; i++) {
        if (n%PM[i] == 0) {
            int c = 0;
            while (n%PM[i] == 0)
                n/=PM[i], c++;
            ans *= c+1;
        }
    }
    if (n>1) ans *= 2;
    return ans;
}

int cmp (N *x, N *y)
{
    if (x->d == y->d) return y->x - x->x;
    return x->d - y->d;
}

int main ()
{
    N num[SIZE+1];
    int i, t, n, cs = 1;

    siv();

    for (i = 0; i <= SIZE; i++) {
        num[i].x = i;
        num[i].d = NOD (num[i].x);
    }

    qsort (num, SIZE+1, sizeof(N), cmp);
    num[1].x = 1;

    scanf ("%d", &t);

    while (t--) {
        scanf ("%d", &n);
        printf ("Case %d: %d\n", cs++, num[n].x);
    }

    return 0;
}

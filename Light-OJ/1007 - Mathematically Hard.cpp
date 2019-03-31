#include <cstdio>
using namespace std;

#define size 5000007

typedef unsigned long long uLL;

uLL phi[size];
int mark[size];

void sivPhi ()
{
    int i, j;

    for (i = 2; i < size; ++i)
        phi[i] = i;

    for (i = 2; i < size; ++i) {
        if (mark[i] == 0) {
            for (j = i; j < size; j+=i) {
                mark[j] = 1;
                phi[j] -= phi[j]/i;
            }
        }
    }

    for (i = 2; i < size; ++i)
        phi[i] = phi[i]*phi[i] + phi[i-1];
}

int main ()
{
    int T, a, b, cs = 1;

    sivPhi();

    scanf ("%d", &T);

    while (T--) {
        scanf ("%d %d", &a, &b);
        printf ("Case %d: %llu\n", cs++, phi[b]-phi[a-1]);
    }

    return 0;
}

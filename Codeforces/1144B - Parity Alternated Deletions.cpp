#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
    int n, even = 0, odd = 0;
    int ar[2000];

    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
            scanf("%d", &ar[i]);
            if (ar[i]%2)
                    ++odd;
            else
                    ++even;
    }

    if (abs(even-odd) < 2)
            puts("0");
    else {
            sort(ar, ar+n);
            even = odd = min(even, odd) + 1;
            long long sum = 0;
            for (int i=n-1; i>=0; --i) {
                    if (even && ar[i]%2==0)
                            --even;
                    else if (odd && ar[i]%2)
                            --odd;
                    else
                            sum += ar[i];
            }

            printf("%lld\n", sum);
    }

    return 0;
}

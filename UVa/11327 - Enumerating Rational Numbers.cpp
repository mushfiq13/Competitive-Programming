#include <bits/stdc++.h>
using namespace std;

const int Max = 2e5 + 10;

typedef long long ll;

int mark[Max];
int phi[Max];
ll phiSum[Max] = {0,2};

void sivPhi ()
{
    for (int i = 1; i < Max; ++i)
        phi[i] = i;

    for (int i=2; i<Max; ++i) {
        if (mark[i]) continue;
        for (int j = i; j < Max; j += i) {
            mark[j] = 1;
            phi[j] -= phi[j] / i;
        }
    }

    for (int i = 2; i < Max; ++i)
        phiSum[i] = phiSum[i-1] + phi[i];
}

int main()
{
    sivPhi();
    ll k;

    while (scanf("%lld", &k), k) {
        int d = lower_bound(phiSum, phiSum + Max, k) - phiSum;
        k -= phiSum[d-1];
        for (int i = 0; i <= d; ++i) {
            if (__gcd(i, d) == 1)
                --k ;
            if (k == 0) {
                printf("%d/%d\n", i, d);
                break;
            }
        }
    }

    return 0;
}

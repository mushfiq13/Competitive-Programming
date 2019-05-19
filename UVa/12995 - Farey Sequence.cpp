#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 5;

int phi[MAX], mark[MAX];
long long phiSum[MAX];

void phiSiv ()
{
    for (int i=1; i<MAX; ++i)
        phi[i] = i;
    for (int i=2; i<MAX; ++i) {
        if (mark[i]) continue;
        for (int j = i; j < MAX; j += i) {
            mark[j] = 1;
            phi[j] -= phi[j] / i;
        }
    }
    for (int i=2; i<MAX; ++i)
        phiSum[i] = phiSum[i-1] + phi[i];
}

int main()
{
    phiSiv();
    int n;
    while (scanf("%d", &n), n) {
        printf("%lld\n", phiSum[n]);
    }
    return 0;
}

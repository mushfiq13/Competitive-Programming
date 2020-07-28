#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;

    scanf("%d", &t);
    for (int Case=1; Case<=t; ++Case) {
        scanf("%d", &n);

        int h[n], w[n];
        for (int i=0; i<n; ++i) scanf("%d", &h[i]);
        for (int i=0; i<n; ++i) scanf("%d", &w[i]);

        int sumInc[n] = {}, sumDec[n] = {};
        int ansInc = 0, ansDec = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                if (h[j] < h[i])
                    sumInc[i] = max(sumInc[i], sumInc[j]);
                if (h[j] > h[i])
                    sumDec[i] = max(sumDec[i], sumDec[j]);
            }
            sumInc[i] += w[i];
            sumDec[i] += w[i];
            ansInc = max(ansInc, sumInc[i]);
            ansDec = max(ansDec, sumDec[i]);
        }

        if (ansInc >= ansDec)
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", Case, ansInc, ansDec);
        else
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", Case, ansDec, ansInc);
    }

    return 0;
}

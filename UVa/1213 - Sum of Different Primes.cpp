#include <bits/stdc++.h>
using namespace std;

int dp[1125][15];

int main() {
    int n, k, p = 1;
    int pr[1000];

    for (int i=2; i<=1120; i++) {
        int j;
        for (j=2; j*j<=i; ++j)
            if (i % j == 0) break;
        if (j*j > i) pr[p++] = i;
    }

    while (1) {
        cin >> n >> k;
        if (!n && !k) break;
        memset(dp, 0, sizeof(dp));

        dp[0][0] = 1;

        long long ans = 0;
        for (int i=1; i<p && pr[i] <= n; ++i)
            for (int j=n; j>=pr[i]; --j)
                for (int q=1; q <= k; ++q)
                    dp[j][q] += dp[j-pr[i]][q-1];

        cout << dp[n][k] << endl;
    }
}

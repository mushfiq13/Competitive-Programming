#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = (int)1e8 + 7;

int coins[105];
ll dp[10005][105];

int main() {
    int t, n, k;

    scanf("%d", &t);
    for (int casi = 1; casi <= t; casi++) {
        scanf("%d %d", &n, &k);

        for (int i = 0; i<n; ++i) {
            scanf("%d", &coins[i]);
            dp[0][i] = 1;
        }

        for (int i=1; i<=k; ++i) {
            for (int j=0; j<n; ++j) {
                dp[i][j] = 0;
                if (i - coins[j] >= 0)
                    dp[i][j] = dp[i - coins[j]][j];
                if (j)
                    dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }

        printf("Case %d: %lld\n", casi, dp[k][n-1]);
    }
}

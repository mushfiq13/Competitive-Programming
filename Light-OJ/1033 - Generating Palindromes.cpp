#include <bits/stdc++.h>
using namespace std;

int dp[105][105];

int main() {
    int t;

    scanf("%d", &t);
    for (int Case=1; Case<=t; ++Case) {
        string A;
        cin >> A;

        string B{A};
        reverse(B.begin(), B.end());

        int n = A.size();
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j)
                if (A[i-1] == B[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);

        printf("Case %d: %d\n", Case, n - dp[n][n]);
    }
}

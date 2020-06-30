#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000007;

int LCS(string& A, string& B) {
    int n = (int)A.length();
    int m = (int)B.length();

    vector<vector<int>> dp (n+1, vector<int> (m+1, 0));
    vector<vector<long long>> ans (n+1, vector<long long> (m+1, 0));

    for (int i=0; i<=n; ++i) {
        for (int j=0; j<=m; ++j) {
            if (i == 0 || j == 0) {
                ans[i][j] = 1;
                continue;
            }

            if (A[i-1] == B[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans[i][j] = ans[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (dp[i][j] == dp[i][j-1])
                    ans[i][j] += ans[i][j-1];
                if (dp[i][j] == dp[i-1][j])
                    ans[i][j] += ans[i-1][j];
                if (dp[i][j] == dp[i-1][j-1])
                    ans[i][j] -= ans[i-1][j-1];
                ans[i][j] = (ans[i][j] + MOD) % MOD;
            }
        }
    }

    return ans[n][m];
}

int main() {
    int t;
    string a, b;

    scanf("%d", &t);
    for (int Case=1; Case<=t; ++Case) {
        cin >> a >> b;
        printf("Case %d: %d\n", Case, LCS(a, b));
    }
}

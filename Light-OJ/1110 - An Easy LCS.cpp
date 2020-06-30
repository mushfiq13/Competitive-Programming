#include <bits/stdc++.h>
using namespace std;

void LCS(string& A, string& B) {
    int n = (int)A.length();
    int m = (int)B.length();
    string dp[n+1][m+1];

    for (int i=0; i<=n; ++i) {
        for (int j=0; j<=m; ++j) {
            if (i == 0 || j == 0)
                dp[i][j] = "";
            else if (A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1] + A[i-1];
            else if (dp[i-1][j].size() > dp[i][j-1].size())
                dp[i][j] = dp[i-1][j];
            else if (dp[i-1][j].size() < dp[i][j-1].size())
                dp[i][j] = dp[i][j-1];
            else
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
        }
    }

    if (dp[n][m] == "") puts(":(");
    else cout << dp[n][m] << endl;
}

int main() {
    int t;
    string a, b;

    scanf("%d", &t);
    for (int Case=1; Case<=t; ++Case) {
        cin >> a >> b;
        printf("Case %d: ", Case);
        LCS(a, b);
    }
}

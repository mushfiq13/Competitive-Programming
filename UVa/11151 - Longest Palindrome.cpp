#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        string A;
        getline(cin, A);

        if (A.empty()) {
            puts("0");
            continue;
        }

        string B{A};
        reverse(B.begin(), B.end());

        int n = A.size();
        vector<vector<int>> dp (n+1, vector<int> (n+1, 0));
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j)
                dp[i][j] = (A[i-1] == B[j-1]) ? 1 + dp[i-1][j-1] : max(dp[i][j-1], dp[i-1][j]);

        cout << dp[n][n]<<endl;
    }
}

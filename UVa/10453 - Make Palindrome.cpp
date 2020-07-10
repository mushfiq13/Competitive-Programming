#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int main() {
    //freopen("out.txt", "w", stdout);
    string A;

    while (cin >> A) {
        string B{A};
        reverse(B.begin(), B.end());

        int n = A.size();
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n; ++j) {
                if (A[i-1] == B[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }

        string palinSub;
        for (int i=n, j=n; dp[i][j]; ) {
            if (A[i-1] == B[j-1]) palinSub += A[i-1], --i, --j;
            else if (dp[i][j] == dp[i][j-1]) --j;
            else --i;
        }

        string firstHalf;
        int l = 0, r = palinSub.size()-1;
        int i = 0, j = A.size() - 1;
        while (l <= r) {
            string leftSide, rightSide;
            while (A[i] - palinSub[l]) leftSide += A[i++];
            while (A[j] - palinSub[r]) rightSide += A[j--];
            firstHalf += rightSide + leftSide + palinSub[l];
            ++l, --r;
            ++i, --j;
        }

        string ans{firstHalf};
        if (palinSub.size() & 1)
            firstHalf.pop_back();
        reverse(firstHalf.begin(), firstHalf.end());
        ans += firstHalf;

        cout << n - palinSub.size() << " " << ans << endl;
    }
}

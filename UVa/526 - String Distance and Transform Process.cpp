#include <bits/stdc++.h>
using namespace std;

int step, Count;
string A, B;
int dp[82][82];

int editDistance() {
    int n = A.size(), m = B.size();

    for (int i=0; i<=n; ++i) {
        for (int j=0; j<=m; ++j) {
            if (!i) dp[i][j] = j;
            if (!j) dp[i][j] = i;

            if (!i || !j) continue;

            if (A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j-1],
                           min(dp[i-1][j], dp[i][j-1]));
        }
    }

    return dp[n][m];
}

void print() {
    int i = A.size(), j = B.size();

    while (i || j) {
        if (i>0 && dp[i][j] == 1 + dp[i-1][j]) {
            printf("%d Delete %d\n", ++step, i--);
        }
        else if (j>0 && dp[i][j] == 1 + dp[i][j-1]) {
            printf("%d Insert %d,%c\n", ++step, i+1, B[j-1]);
            --j;
        }
        else if (i>0 && j>0) {
            if (dp[i][j] == 1 + dp[i-1][j-1])
                printf("%d Replace %d,%c\n", ++step, i, B[j-1]);
            --i, --j;
        }
    }
}

int main() {
    int n = -1, m;

    while (getline(cin, A)) {
        getline(cin, B);
        if (n > -1) puts("");

        cout << editDistance() << endl;
        step = Count = 0;
        print();
    }

    return 0;
}

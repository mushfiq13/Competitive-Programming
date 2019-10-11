#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 10;

int S[MAX], col[MAX][MAX];

int main () {
    int n;

    scanf ("%d", &n);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int x;
            scanf ("%d", &x);
            col[i][j] = col[i-1][j] + x;
        }
    }

    int ans = INT_MIN;
    for (int a=1; a<=n; ++a) {
        for (int c=a; c<=n; ++c) {
            for (int i=1; i<=n; ++i) {
                S[i] = col[c][i] - col[a-1][i];
            }
            int sum = 0, Max = INT_MIN;
            for (int i=1; i<=n; ++i) {
                sum += S[i];
                if (sum < 0) sum = 0;
                else ans = max (ans, sum);
                Max = max (Max, S[i]);
            }
            ans = max (ans, Max);
        }
    }

    printf ("%d\n", ans);

    return 0;
}

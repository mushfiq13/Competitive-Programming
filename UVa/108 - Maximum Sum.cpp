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
                S[i] = S[i-1] + col[c][i] - col[a-1][i];
            }
            int Min = 0;
            for (int i=1; i<=n; ++i) {
                ans = max (ans, S[i] - Min);
                Min = min (Min, S[i]);
            }
        }
    }

    printf ("%d\n", ans);

    return 0;
}

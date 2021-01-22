#include <bits/stdc++.h>
using namespace std;

const int N = 22;
const int INF = (int)1e9;

int dp[N][3], ar[N][3];

int rec(int i, int col, int n) {
    if (i == n) return ar[i][col];

    int& ret = dp[i][col];
    if (ret - INF) return ret;

    for (int k=0; k<3; ++k) {
        if (i>0 && col == k) continue;
        ret = min(ret, rec(i+1, k, n));
    }

    if (i>0) ret += ar[i][col];

    return ret;
}

int main() {
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);

    int t, n;

    scanf("%d", &t);
    for (int cas=1; cas<=t; ++cas) {
        scanf("%d", &n);

        for (int i=1; i<=n; ++i) {
            for (int j=0; j<3; ++j) {
                scanf("%d", &ar[i][j]);
                dp[i][j] = INF;
            }
        }

        dp[0][0] = INF;
        printf("Case %d: %d\n", cas, rec(0, 0, n));
    }

    return 0;
}
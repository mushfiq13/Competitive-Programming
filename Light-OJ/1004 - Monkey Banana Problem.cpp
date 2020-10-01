#include <bits/stdc++.h>
using namespace std;

int a[205][105];
int dp[205][105];

int F(int i, int j, int n) {
    if (i >= 2*n || j > n) return 0;
    int& ret = dp[i][j];
    if (ret != -1) return ret;

    ret = a[i][j] + max(F(i+1, j, n), F(i+1, j+1, n));
    return ret;
}

int main() {
    int t, n;

    scanf("%d", &t);
    for (int cs=1; cs<=t; ++cs) {
        scanf("%d", &n);

        for (int i=0; i<=2*n-1; ++i)
            for (int j=0; j<=n; ++j)
                a[i][j] = 0, dp[i][j] = -1;

        for (int i=1, k = 2; i<=2*n-1; ++i) {
            if (i <= n)
            for (int j=1; j<=i; ++j)
                scanf("%d", &a[i][j]);
            else
            for (int j=k++; j<=n; ++j)
                scanf("%d", &a[i][j]);
        }

        printf("Case %d: %d\n", cs, F(1, 1, n));
    }
}

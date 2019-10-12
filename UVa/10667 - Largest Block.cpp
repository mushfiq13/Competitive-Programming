#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 10;

int a[MAX][MAX], col[MAX][MAX];

int sol (int n) {
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            col[i][j] = col[i-1][j] + a[i][j];

    int ans = 0;
    for (int a=1; a<=n; ++a) {
        for (int c=a; c<=n; ++c) {
            int sum = 0;
            for (int i=1; i<=n; ++i) {
                if (col[c][i] - col[a-1][i] != c-a+1)
                    sum = 0;
                else
                    sum += col[c][i] - col[a-1][i];
                ans = max(ans, sum);
            }
        }
    }

    return ans;
}

int main() {
    int t, n, b;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i=1; i<=n; ++i)
            for (int j=1; j<=n; ++j)
                a[i][j] = 1;

        scanf("%d", &b);
        while (b--) {
            int r1, r2, c1, c2;
            scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
            for (int i=r1; i<=r2; ++i)
                for (int j=c1; j<=c2; ++j)
                    a[i][j] = -1;
        }

        printf("%d\n", sol (n));
    }

    return 0;
}

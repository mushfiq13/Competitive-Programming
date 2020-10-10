#include <bits/stdc++.h>
using namespace std;

int dp[1001][6005];
int w[1001], c[1001];

int F(int i, int curW = 0) {
    if (i < 0) return 0;

    int &ret = dp[i][curW];
    if (ret != -1) return ret;

    ret = F(i-1, curW);
    if (curW <= c[i])
        ret = max(ret, 1 + F(i-1, curW+w[i]));

    return ret;
}

int main() {
    int n;

    while (cin >> n, n) {
        for (int i=0; i<n; ++i)
            cin >> w[i] >> c[i];

        memset(dp, -1, sizeof(dp));

        cout << F(n-1) << endl;
    }
}


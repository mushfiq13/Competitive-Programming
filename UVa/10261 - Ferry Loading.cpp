#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;

int car[1000], port[1000];
vector<vector<int>> dp;
vector<vector<char>> take;

int F(int i, int n, int remL, int remR) {
    if (remL < 0 || remR < 0) return -1;
    if (i == n) return 0;

    int &ret = dp[i][max(remL, remR)];
    if (ret != -1) return ret;

    int a = 1 + F(i+1, n, remL-car[i], remR);
    int b = 1 + F(i+1, n, remL, remR-car[i]);

    if (a >= b) take[i][remL] = 1;

    return ret = max(a, b);
}

int main() {
    int t, ferry, n;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &ferry);
        n = 0;
        while (scanf("%d", &car[n]), car[n])
            ++n;

        ferry *= 100;

        dp = vector<vector<int>> (n+1, vector<int>(ferry+1, -1));
        take = vector<vector<char>> (n+1, vector<char>(ferry+1, 0));
        fill (port, port+n+1, 0);

        int k = F(0, n, ferry, ferry);
        for (int i=0; i<k; ++i) {
            if (take[i][ferry] && ferry >= car[i])
                port[i] = 1, ferry -= car[i];
        }

        printf("%d\n", k);
        for (int i=0; i<k; ++i)
            if (port[i]) puts("port");
            else puts("starboard");

        if (t) puts("");
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9;

vector<int> coins;
vector<vector<pii>> dp;
vector<vector<char>> mem;

pii coinChange(int amount, int i) {
    if (amount <= 0) return {0, 0};
    if (i >= coins.size()) return {INF, INF};

    pii& ret = dp[amount][i];
    if (mem[amount][i]) return ret;
    mem[amount][i] = 1;

    pii a = coinChange(amount, i+1);
    pii b = coinChange(amount - coins[i], i+1);

    b.second += 1;
    b.first += coins[i];

    if (a.first < b.first) ret = a;
    else if (a.first > b.first) ret = b;
    else if (a.second > b.second) ret = b;
    else ret = a;

    return ret;
}

int main() {
    int t, n, k;

    scanf("%d", &t);
    for (int casi = 1; casi <= t; casi++) {
        scanf("%d %d", &k, &n);

        coins.resize(n);
        for (int i=0; i<n; ++i) scanf("%d", &coins[i]);

        dp = vector<vector<pii>> (k+1, vector<pii>(n+1, {INF,INF}));
        mem = vector<vector<char>> (k+1, vector<char>(n+1, 0));
        pii ans = coinChange(k, 0);

        printf("%d %d\n", ans.first, ans.second);
    }
}

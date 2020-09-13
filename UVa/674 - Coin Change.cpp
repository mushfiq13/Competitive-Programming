#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = (int)1e8 + 7;

vector<int> coins;
vector<vector<ll>> dp;
vector<vector<char>> mem;

void coinChange(int n) {
    dp = vector<vector<ll>> (n+5, vector<ll> (coins.size()+5, 0));

    for (int i=0; i<coins.size(); ++i)
        dp[0][i] = 1;

    for (int i=1; i<=n; ++i) {
        for (int j=0; j<coins.size(); ++j) {
            if (i - coins[j] >= 0)
                dp[i][j] = dp[i - coins[j]][j];
            if (j)
                dp[i][j] += dp[i][j-1];
        }
    }
}

int main() {
    int n;

    coins = {1, 5, 10, 25, 50};
    coinChange(7489+5);

    while (~scanf("%d", &n)) {
        printf("%lld\n", dp[n][coins.size()-1]);
    }
}

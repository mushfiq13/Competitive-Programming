#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MOD = (int)1e8 + 7;

vector<int> A, C;
vector<vector<ll>> dp;
vector<vector<char>> mem;

ll coinChange(int amount, int i) {
    if (amount == 0) return 1;
    if (amount < 0) return 0;
    if (i >= A.size()) return 0;

    ll& ret = dp[amount][i];
    if (mem[amount][i]) return ret;
    mem[amount][i] = 1;

    for (int j=0; j*A[i] <= amount && j<=C[i]; ++j) {
        ret += coinChange(amount -  j * A[i], i+1) % MOD;
    }

    return ret % MOD;
}

int main() {
    int t, n, k;

    scanf("%d", &t);
    for (int casi = 1; casi <= t; casi++) {
        scanf("%d %d", &n, &k);

        A.resize(n);
        C.resize(n);
        for (int i = 0; i<n; ++i) scanf("%d", &A[i]);
        for (int i = 0; i<n; ++i) scanf("%d", &C[i]);

        dp = vector<vector<ll>> (k+1, vector<ll> (55, 0));
        mem = vector<vector<char>> (k+1, vector<char> (55, 0));

        printf("Case %d: %lld\n", casi, coinChange(k, 0));
    }
}

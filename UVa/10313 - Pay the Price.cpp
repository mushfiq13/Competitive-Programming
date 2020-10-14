#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;

long long dp[301][301][301];

long long F(int amount, int rem, int coin = 1) {
    if (amount == 0 && rem == 0) return 1;
    if (rem > 300 || amount <= 0 || !rem || coin > amount) return 0;

    long long &ret = dp[coin][amount][rem];
    if (ret != -1) return ret;

    return ret = F(amount, rem, coin+1) + F(amount-coin, rem-1, coin);
}

int main() {
    memset(dp, -1, sizeof(dp));

    char s[15];
    while (gets(s)) {
        int amount, l, r;
        int n = sscanf(s, "%d %d %d", &amount, &l, &r);

        if (n == 1) l = 0, r = amount;
        else if (n == 2) r = l, l = 0;

        long long sum = 0;
        for (int i=l; i<=r; ++i) {
            sum += F(amount, i, 1);
        }

        cout << sum << endl;
    }
}

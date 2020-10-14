#include <bits/stdc++.h>
using namespace std;

int amount;
vector<vector<int>> dp;
vector<int> price, favour;

int F(int i = 0, int curW = 0){
    if (curW > amount+200) return INT_MIN;
    if (i == price.size()) {
        if (amount <= 1800 && curW > amount) return INT_MIN;
        if (amount > 1800 && curW > amount && curW <= 2000) return INT_MIN;
        return 0;
    }

    int &ret = dp[i][curW];
    if (ret != -1) return ret;

    return ret = max(F(i+1, curW), favour[i] + F(i+1, curW+price[i]));
}

int main() {
    int n;
    while (~scanf("%d %d", &amount, &n)) {
        dp = vector<vector<int>> (n, vector<int> (amount+205, -1));
        price.resize(n);
        favour.resize(n);

        for (int i=0; i<n; ++i)
            scanf("%d %d", &price[i], &favour[i]);

        printf("%d\n", F());
    }
}


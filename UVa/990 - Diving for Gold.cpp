#include <bits/stdc++.h>
using namespace std;

int d[35], v[35];
int dp[35][1005];
char used[35][1005];

int F(int n, int t, int w) {
    if (t<0) return -1000000;
    if (n<0 || !t)
        return 0;

    int &ret = dp[n][t];
    if (ret != -1) return ret;

    int a = F(n-1, t, w);
    int b = v[n] + F(n-1, t - (w*d[n] + 2*w*d[n]), w);
    if (a < b) used[n][t] = 1;
    return ret = max(a, b);
}

int main() {
    int t, w, n = -1;
    while (~scanf("%d %d", &t, &w)) {
        if (n > -1) puts("");
        cin >> n;
        for (int i=0; i<n; ++i) {
            cin >> d[i] >> v[i];
        }

        memset(dp, -1, sizeof(dp));
        memset(used, 0, sizeof(used));

        cout << F(n-1, t, w) << endl;

        set<int> id;
        for (int i=n-1; i>=0; --i) {
            if (used[i][t] && t >= (w*d[i] + 2*w*d[i])) {
                id.insert(i);
                t -= w*d[i] + 2*w*d[i];
            }
        }

        cout << id.size() << endl;
        if (!id.empty())
        for (int i : id)
            cout << d[i] << " " << v[i] << endl;
    }
}


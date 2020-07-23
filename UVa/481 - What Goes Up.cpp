#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    vector<int> a;

    while (~scanf("%d", &x))
        a.push_back(x);

    int n = a.size();
    vector<int> pos(n+1, -1), dp(n+1, 1), L(n+1, 1000000009), p(n+1, -1);

    L[0] *= -1;
    int mx = 0, id = 0;
    for (int i=0; i<n; ++i) {
        int j = upper_bound(L.begin(), L.end(), a[i]) - L.begin();
        if (L[j-1] == a[i]) --j;
        if (a[i] > L[j-1] && a[i] <= L[j]) {
            L[j] = a[i], dp[i] = j;
            pos[j] = i;
            if (j > 1) p[i] = pos[j-1];
        }
        if (dp[i] >= mx) mx = dp[i], id = i;
    }

    vector<int> ans;
    int cur = id;
    while (p[cur] != -1)
        ans.push_back(a[cur]), cur = p[cur];
    ans.push_back(a[cur]);

    cout << ans.size() << "\n-\n";
    for (int i=ans.size()-1; i>=0; --i)
        printf("%d\n", ans[i]);

    return 0;
}

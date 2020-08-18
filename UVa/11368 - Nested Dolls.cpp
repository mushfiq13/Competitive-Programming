#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 99;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second - b.second) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    int t, n;

    cin >> t;
    while (t--) {
        cin >> n;

        pair<int, int> ar[n];
        for (int i=0; i<n; ++i) {
            int w, h;
            cin >> w >> h;
            ar[i] = {w, h};
        }

        sort(ar, ar+n, cmp);

        vector<int>  L (n+1, INF);

        L[0] = -INF;
        int ans = 0;
        for (int i=0; i<n; ++i) {
            int j = upper_bound(L.begin(), L.end(), ar[i].first) - L.begin();
            if (L[j] > ar[i].first)
                L[j] = ar[i].first;
            ans = max(ans, j);
        }

        cout << ans << endl;
    }
}

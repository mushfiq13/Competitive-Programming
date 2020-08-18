#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 99;

int main() {
    int n;

    while (cin >> n) {
        if (n == 0) {
            puts("*");
            return 0;
        }

        pair<int, int> ar[n];
        for (int i=0; i<n; ++i) {
            int a, b;
            cin >> a >> b;
            ar[i] = {a, b};
        }

        sort(ar, ar+n);

        vector<int>  L (n+1, INF);

        L[0] = -INF;
        int ans = 0;
        for (int i=0; i<n; ++i) {
            int j = upper_bound(L.begin(), L.end(), ar[i].second) - L.begin();
            if (L[j] > ar[i].second)
                L[j] = ar[i].second;
            ans = max(ans, j);
        }

        cout << ans << endl;
    }
}

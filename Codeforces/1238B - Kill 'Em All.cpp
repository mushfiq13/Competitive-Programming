#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 10;

int x[MAX];

int main() {
    int q, n, r;

    cin >> q;
    while (q--) {
        cin >> n >> r;
        for (int i=0; i<n; ++i)
            cin >> x[i];
        sort (x, x+n);
        int ans = 0;
        ll tot = 0;
        for (int i=n-1; i>=0; --i) {
            if (x[i]-tot <= 0) break;
            if (i<n-1 && x[i] == x[i+1]) continue;
            ++ans;
            tot += r;
        }
        cout << ans << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x;
    while (cin >> m >> n) {
        if (!n && !m) break;
        vector<int> cus;
        for (int i=0; i<m; ++i) {
            cin >> x;
            cus.push_back(x);
        }
        int ans = 0;
        while (n--) {
            bool can = true;
            for (int i=0; i<m; ++i) {
                cin >> x;
                if (cus[i] < x) can = false;
            }
            ans += (int) can;
        }
        cout << ans << endl;
    }
    return 0;
}

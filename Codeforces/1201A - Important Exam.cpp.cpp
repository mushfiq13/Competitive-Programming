#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    string s[1000];

    cin >> n >> m;
    for (int i=0; i<n; ++i) {
        cin >> s[i];
    }

    int ans = 0;
    for (int i=0; i<m; ++i) {
        int x, mx = 0, f[27] = {};
        cin >> x;
        for (int j=0; j<n; ++j) {
            ++f[s[j][i]-'A'] ;
            mx = max (mx, f[s[j][i]-'A']);
        }
        ans += mx * x;
    }

    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    string s;

    cin >> t;
    while (t--) {
        cin >> n;

        int f[10] = {};
        while (n--) {
            cin >> s;
            for (int i=0; s[i]; ++i)
                if (s[i] == '1')
                    f[i] ^= 1;
        }

        int ans = 0;
        for (int i=0; i<10; ++i)
            ans += f[i];
        cout << ans << endl;
    }
}

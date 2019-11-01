#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, a, b, c;
    string s;

    cin >> t;
    while (t--) {
        cin >> n >> a >> b >> c >> s;

        string res = "";
        int S = 0, R = 0, P = 0;
        for (int i=0; i<n; ++i) {
            res += '!';
            if (s[i] == 'R') ++R;
            else if (s[i] == 'P') ++P;
            else ++S;
        }

        int win = 0;
        for (int i=0; i<n; ++i) {
            if (s[i] == 'R') {
                if (b) res[i] = 'P', ++win, --b;
            } else if (s[i] == 'P') {
                if (c) res[i] = 'S', ++win, --c;
            } else {
                if (a) res[i] = 'R', ++win, --a;
            }
        }

        for (int i=0; i<n; ++i) {
            if (res[i] == '!') {
                if (a) res[i] = 'R', --a;
                else if (b) res[i] = 'P', --b;
                else res[i] = 'S', --c;
            }
        }

        if (win >= n/2 + n%2) cout << "YES\n" << res << endl;
        else puts("NO");
    }

    return 0;
}

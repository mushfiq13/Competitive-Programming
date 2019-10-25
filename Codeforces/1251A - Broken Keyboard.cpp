#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 10;


int main() {
    int t;
    string s;

    cin >> t;
    while (t--) {
        cin >> s;

        string res = "";
        int r = (int) s.length();
        for (int i=0; i<r; ++i) {
            if (s[i] == s[i+1]) ++i;
            else res += s[i];
        }

        sort (res.begin(), res.end());

        if (res.size()) {
            for (int i=0; res[i]; ++i) {
                if (i && res[i] == res[i-1]) continue;
                putchar(res[i]);
            }
        }
        puts("");
    }
    return 0;
}

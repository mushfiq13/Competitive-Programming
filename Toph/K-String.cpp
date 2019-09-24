#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, cnt = 0;
    string s;
    int f[27] = {};

    cin >> n >> k >> s;

    for (int i=0; s[i]; ++i) {
        f[s[i]-'a']++;
        if (f[s[i]-'a'] == 1) ++cnt;
    }

    int d = 0;
    if (cnt < k)
        d = k-cnt;
    else {
        sort (f, f+27);
        for (int i=0; cnt > k && i < 27; ++i) {
            if (f[i]) {
                d += f[i];
                f[i] = 0;
                --cnt;
            }
        }
    }

    cout << d << endl;

    return 0;
}

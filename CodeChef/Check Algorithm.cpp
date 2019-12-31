#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    string s;

    cin >> t;
    while (t--) {
        cin >> s;
        string ans = "";
        int c = 1;
        for (int i=0; s[i]; ++i) {
            if (s[i] == s[i+1])
                ++c;
            else {
                ans += s[i];
                while (c)
                    ans += '1', c /= 10;
                c = 1;
            }
        }
        if (ans.length() < s.length()) puts("YES");
        else puts("NO");
    }

    return 0;
}

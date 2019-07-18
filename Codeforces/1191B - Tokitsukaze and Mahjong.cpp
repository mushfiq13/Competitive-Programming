#include <bits/stdc++.h>
using namespace std;

bool cmp (string a, string b) {
    if (a[1] == b[1]) return a[0] < b[0];
    return a[1] < b[1];
}

int main() {
    string s[3];

    cin >> s[0] >> s[1] >> s[2];

    sort (s, s+3, cmp);

    if (s[0][1] == s[1][1] && s[0][1] == s[2][1])
        if ((s[0][0] == s[1][0] && s[0][0] == s[2][0]) || (s[0][0]+1 == s[1][0] && s[1][0]+1 == s[2][0])) {
            puts("0");
            return 0;
        }

    if ((s[0][0] == s[1][0] && s[0][1] == s[1][1]) || (s[1][0] == s[2][0] && s[1][1] == s[2][1])
        || (s[0][1] == s[1][1] && (s[0][0]+1 == s[1][0] || s[0][0]+2 == s[1][0])) || (s[1][1] == s[2][1] && (s[1][0]+1 == s[2][0] || s[1][0]+2 == s[2][0])))
            puts("1");
    else puts("2");

    return 0;
}

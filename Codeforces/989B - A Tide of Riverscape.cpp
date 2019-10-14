//============================================================================
// Name        : A Tide of Riverscape
// Author      : Mushfiqur Rahman
//============================================================================

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p;
    string s;
    bool yes = true;

    cin >> n >> p >> s;
    for (int i=0; i<n; ++i) {
        if (i < n-p) {
            if (s[i] == '.' && s[i+p] == '.') { s[i] = '0'; s[i+p] = '1'; }
            else if (s[i] == '.') s[i] = s[i+p] == '1' ? '0' : '1';
            else if (s[i+p] == '.') s[i+p] = s[i] == '1' ? '0' : '1';
            if (s[i] != s[i+p]) yes = false;
        } else if (s[i] == '.') s[i] = '0';
    }

    if (!yes) cout << s << endl;
    else puts("NO");

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    string s;

    cin >> n >> k >> s;

    if (n == 1 && k) {s[0] = '0'; k=0;}
    if (k && s[0]>'1') {--k; s[0] = '1';}
    for (int i=1; s[i] && k; ++i) {
        if (s[i] != '0') {
            s[i] = '0';
            --k;
        }
    }

    cout << s << endl;

    return 0;
}

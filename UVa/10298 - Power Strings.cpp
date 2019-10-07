#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int prefix_function (string s) {
    int now;
    int n = (int) s.length();
    vi pi (n);
    now = pi[0] = -1;
    for (int i=1; i<n; ++i) {
        while (now > -1 && s[i] != s[now+1])
            now = pi[now];
        if (s[i] == s[now+1]) ++now;
        else now = -1;
        pi[i] = now;
    }
    return pi[n-1];
}

int main() {
    string s;
    while (getline(cin, s)) {
        if (s == ".") break;
        int l = prefix_function (s);
        int n = (int) s.length();
        int k = n-l-1;
        if (n % k) k = n;
        cout << n/k << endl;
    }
    return 0;
}

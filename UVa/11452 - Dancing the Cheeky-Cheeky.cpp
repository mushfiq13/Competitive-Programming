#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

int prefix_function (string P) {
    int now, r=0;
    int n = (int) P.length();
    vi pi (n);
    pi[0] = now = -1;
    for (int i=1; i<n; ++i) {
        while (now > -1 && P[i] != P[now+1])
            now = pi[now];
        if (P[i] == P[now+1]) ++now;
        else now = -1;
        pi[i] = now;
        if ((now+1)*2 == i+1) r = max (now+1, r);
    }
    return r;
}

int main() {
    int t;
    string s;

    scanf("%d", &t);
    while (t--) {
        cin >> s;
        int r = prefix_function (s);
        int n = (int) s.length();
        for (int i=(n-(r*2))%r, j=0; j<8; ++j, i = (i+1) % r)
            putchar(s[i]);
        puts("...");
    }

    return 0;
}

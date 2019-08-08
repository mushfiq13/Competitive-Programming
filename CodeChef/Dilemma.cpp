#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

string s;
int a[MAX];

bool solve () {
    int n;

    for (n=0; s[n]; ++n)
        a[n+1] = s[n] - '0';

    for (int i=1; i<=n; ++i) {
        if (a[i] == 1) {
            a[i] = -1;
            if (i-1 > 0 && a[i-1] != -1) a[i-1] ^= 1;
            if (i+1 <= n && a[i+1] != -1) a[i+1] ^= 1;
            if (a[i-1] == 1) i -= 2;
        }
    }

    for (int i=1; i<=n; ++i)
        if (a[i] == 0)
            return 0;

    return 1;
}

int main() {
    int t;

    scanf("%d", &t);
    while (t--) {
        cin >> s;
        if (solve())
            puts("WIN");
        else
            puts("LOSE");
    }

    return 0;
}

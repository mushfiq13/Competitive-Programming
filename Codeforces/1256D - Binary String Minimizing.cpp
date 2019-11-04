#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e6 + 10;

int a[MAX];

int main() {
    ll k;
    int q, n;
    string s;

    cin >> q;
    while (q--) {
        cin >> n >> k >> s;

        for (int i=1; i<=n; ++i)
            a[i] = s[i-1] - '0';

        int pos = 1;
        while (a[pos] == 0 && pos<=n) ++pos;

        for (int i=pos+1; i<=n && k>0; ++i) {
            if (a[i] == 0) {
                while (a[pos] == 1 && pos<=n) {
                    int d = i-pos;
                    if (d > k) ++pos;
                    else {
                        k -= d;
                        a[pos] = 0;
                        a[i] = 1;
                        while (a[pos] == 0 && pos<=n) ++pos;
                        break;
                    }
                }
            }
        }

        for (int i=1; i<=n; ++i)
            printf("%d", a[i]);
        puts("");
    }

    return 0;
}

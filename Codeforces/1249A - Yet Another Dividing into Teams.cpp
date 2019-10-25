#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 10;

int a[MAX];

int main() {
    int q, n;

    cin >> q;
    while (q--) {
        cin >> n;
        for (int i=0; i<n; ++i) cin >> a[i];

        sort (a, a+n);

        bool ok = true;
        for (int i=1; i<n && ok; ++i) {
            if (a[i] - a[i-1] == 1)
                ok = false;
        }

        if (ok) puts("1");
        else puts("2");
    }

    return 0;
}

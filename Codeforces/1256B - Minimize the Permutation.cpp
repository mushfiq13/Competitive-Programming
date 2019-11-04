#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 100 + 10;

int a[MAX];

int main() {
    int q, n;

    cin >> q;
    while (q--) {
        cin >> n;
        for (int i=1; i<=n; ++i)
            cin >> a[i];

        map<int, bool> f[n+1];
        for (int cur=1; cur<n; ++cur) {
            for (int i=1; i<=n; ++i) {
                if (a[i] == cur) {
                    while (a[i-1]>a[i] && !f[i-1][i]) {
                        swap (a[i-1], a[i]);
                        f[i-1][i] = 1;
                        --i;
                    }
                    break;
                }
            }
        }

        for (int i=1; i<=n; ++i) {
            if (i>1) putchar(' ');
            cout << a[i];
        }
        puts("");
    }

    return 0;
}

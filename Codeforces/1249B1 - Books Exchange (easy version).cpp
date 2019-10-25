#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;

int a[MAX], ans[MAX];

int main() {
    int q, n;

    cin >> q;
    while (q--) {
        cin >> n;
        for (int i=1; i<=n; ++i) {
            cin >> a[i];
            ans[i] = 0;
        }

        for (int i=1; i<=n; ++i) {
            if (ans[i]) continue;
            if (i == a[i]) { ans[i] = 1; continue; }
            int now = a[i], Count = 1;
            while (a[i] != a[now]) { ++Count; now = a[now]; }
            now = a[i];
            ans[i] = Count;
            while (a[i] != a[now]) { ans[now] = Count; now = a[now]; }
        }

        for (int i=1; i<=n; ++i) {
            if (i>1) putchar(' ');
            cout << ans[i];
        }
        puts("");
    }

    return 0;
}

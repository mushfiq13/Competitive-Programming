#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int a[MAX], b[MAX];
map<int, bool> f;

int main() {
    int n;

    cin >> n;
    for (int i=1; i<=n; ++i) cin >> a[i];
    for (int i=1; i<=n; ++i) cin >> b[i];

    int Count = 0, j = 1;
    for (int i=1; i<=n; ++i) {
        if (f[a[i]]) continue;
        while (j <= n && a[i] != b[j]) { f[b[j]] = 1; ++j; ++Count; }
        ++j;
        f[a[i]] = 1;
    }

    cout << Count << endl;

    return 0;
}

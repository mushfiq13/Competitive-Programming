#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

map<int, int> f;
int a[MAX], l[MAX], h[MAX];

int main() {
    int n, m;

    cin >> n >> m;
    for (int i=1; i<=n; ++i)
        a[i] = l[i] = h[i] = f[i] = i;

    for (int i=1; i<=m; ++i) {
        int x;
        cin >> x;
        if (f[x] == 1) continue;
        int id = f[x];
        swap (a[id], a[id-1]);
        f[x] = id-1;
        f[a[id]] = id;
        l[a[id]] = min (l[a[id]], f[a[id]]);
        l[a[id-1]] = min (l[a[id-1]], f[a[id-1]]);
        h[a[id]] = max (h[a[id]], f[a[id]]);
        h[a[id-1]] = max (h[a[id-1]], h[a[id-1]]);
    }

    for (int i=1; i<=n; ++i)
        printf("%d %d\n", l[i], h[i]);

    return 0;
}

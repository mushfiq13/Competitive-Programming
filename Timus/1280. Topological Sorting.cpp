#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    vector<int> g[n+1];
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }

    int idx[n+1], order[n+1];
    for (int i=1; i<=n; ++i) {
        cin >> order[i];
        idx[order[i]] = i;
    }

    bool ok = true;
    for (int i=1; i<=n && ok; ++i) {
        int v = order[i];
        for (int to: g[v])
            if (idx[to] < idx[v])
                ok = false;
    }

    if (ok) puts("YES");
    else puts("NO");

    return 0;
}

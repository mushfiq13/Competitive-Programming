#include <bits/stdc++.h>
using namespace std;

vector<int> order;
vector<bool> used;
vector<vector<int>> g, gr;

void dfs(int v, int f) {
    used[v] = 1;

    vector<int> grap;
    grap = (f == 1) ? g[v] : gr[v];

    for (int to : grap)
        if (!used[to]) dfs(to, f);
    order.push_back(v);
}

int SCC(int n) {
    order.clear();
    used.assign(n+1, false);
    for (int i=1; i<=n; ++i)
        if (!used[i]) dfs(i, 1);

    int cnt = 0;
    used.assign(n+1, 0);
    for (int i=n-1; i>=0; --i)
        if (!used[order[i]]) ++cnt, dfs(order[i], 2);

    return cnt == 1 ? 1 : 0;
}

int main() {
    int n, m;

    while (cin >> n >> m) {
        if (!n && !m) return 0;

        g = gr = vector<vector<int>> (n+1);
        for (int i=1; i<=m; ++i) {
            int u, v, p;
            cin >> u >> v >> p;
            g[u].push_back(v);
            gr[v].push_back(u);
            if (p == 2) {
                g[v].push_back(u);
                gr[u].push_back(v);
            }
        }

        printf("%d\n", SCC(n));
    }
}

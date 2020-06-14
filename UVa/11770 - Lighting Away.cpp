#include <bits/stdc++.h>
using namespace std;

vector<int> order;
vector<bool> used;
vector<vector<int>> g;

void dfs(int v) {
    used[v] = 1;
    for (int to : g[v])
        if (!used[to]) dfs(to);
    order.push_back(v);
}

int sol(int n) {
    order.clear();
    used.assign(n+1, false);
    for (int i=1; i<=n; ++i)
        if (!used[i]) dfs(i);

    int cnt = 0;
    used.assign(n+1, 0);
    for (int i=n-1; i>=0; --i)
        if (!used[order[i]]) ++cnt, dfs(order[i]);

    return cnt;
}

int main() {
    int t, n, m;

    cin >> t;
    for (int Case=1; Case<=t; ++Case) {
        cin >> n >> m;

        g = vector<vector<int>> (n+1);
        for (int i=1; i<=m; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
        }

        printf("Case %d: %d\n", Case, sol(n));
    }
}

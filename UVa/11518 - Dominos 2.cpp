#include <bits/stdc++.h>
using namespace std;

vector<bool> vis(10000 + 10);
vector<int> adj[10000 + 10];

void dfs(int v, int& Count) {
    vis[v] = 1;
    ++Count;
    for (int to: adj[v])
        if (!vis[to])
            dfs(to, Count);
}

int main() {
    int t, n, m, l;

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &n, &m, &l);
        vis.assign(n+1, 0);
        for (int i=1; i<=n; ++i)
            adj[i].clear();
        while (m--) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
        }
        int Count = 0;
        while (l--) {
            int v;
            scanf("%d", &v);
            if (!vis[v]) dfs(v, Count);
        }
        printf("%d\n", Count);
    }

    return 0;
}

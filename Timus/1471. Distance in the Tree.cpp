#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 99;
const int K = ceil(log2(N));

int timer;
int par[N][K+1];
int tin[N], tout[N];
long long dist[N];
vector<pair<int, int>> adj[N];

void dfs(int v, int p, int w) {
    tin[v] = ++timer;
    dist[v] = dist[p] + w;
    par[v][0] = p;

    for (int i=1; i<=K; ++i)
        par[v][i] = par[par[v][i-1]][i-1];

    for (auto e: adj[v])
        if (p - e.first) dfs(e.first, v, e.second);

    tout[v] = ++timer;
}

bool isAnc(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int LCA(int u, int v) {
    if (isAnc(u, v)) return u;
    if (isAnc(v, u)) return v;

    for (int i=K; i>=0; --i)
        if (!isAnc(par[u][i], v))
            u = par[u][i];
    return par[u][0];
}

int main() {
    int n, m, a, b;

    cin >> n;

    for (int i=1; i<n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dfs(0, 0, 0);

    cin >> m;
    while (m--) {
        cin >> a >> b;
        int l = LCA(a, b);
        cout << dist[a] - dist[l] + dist[b] - dist[l] << endl;
    }

    return 0;
}

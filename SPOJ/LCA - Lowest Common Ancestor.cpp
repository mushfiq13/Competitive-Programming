#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 99;
const int K = ceil(log2(N));

int par[N][K+1];
vector<int> h;
vector<vector<int>> adj;

void dfs(int v, int p) {
    h[v] = h[p] + 1;
    par[v][0] = p;
    for (int i=1; i<=K; ++i)
        par[v][i] = par[par[v][i-1]][i-1];
    for (int to: adj[v])
        if (p - to) dfs(to, v);
}

int LCA(int u, int v) {
    if (h[u] < h[v])
        swap(u, v);
    for (int i=K; i>=0; --i)
        if (h[par[u][i]] >= h[v])
            u = par[u][i];
    if (u == v) return u;
    for (int i=K; i>=0; --i)
        if (par[u][i] - par[v][i])
            u = par[u][i], v = par[v][i];
    return par[u][0];
}

int main() {
    int t, n, m, q;

    cin >> t;
    for (int Case = 1; Case <= t; ++Case) {
        cin >> n;

        adj = vector<vector<int>> (n+1, vector<int> ());
        for (int i=1; i<=n; ++i) {
            cin >> m;
            while (m--) {
                int v;
                cin >> v;
                adj[i].push_back(v);
            }
        }

        h.assign(n+1, 0);
        h[1] = -1;
        dfs(1, 1);

        printf("Case %d:\n", Case);
        cin >> q;
        while (q--) {
            int a, b;
            cin >> a >> b;
            cout << LCA(a, b) << endl;
        }
    }
}

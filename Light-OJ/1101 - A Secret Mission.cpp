#include <bits/stdc++.h>
using namespace std;

const int N = (int)5e4 + 99;
const int K = 16;

typedef pair<int, int> pii;

struct Edge {
    int u, v, w;
};

int h[N], par[N], Size[N];
int L[N][K+1], Max[N][K+1];
vector<vector<pii>> g;

void dfs(int v, int p, int w = 0) {
    h[v] = h[p] + 1;
    L[v][0] = p;
    Max[v][0] = w;
    for (int i=1; i<=K; ++i) {
        L[v][i] = L[L[v][i-1]][i-1];
        Max[v][i] = max(Max[v][i-1], Max[L[v][i-1]][i-1]);
    }
    for (auto e: g[v])
        if (p - e.first) dfs(e.first, v, e.second);
}

int LCA(int u, int v) {
    int mx = 0;
    if (h[u] < h[v]) swap(u, v);
    for (int i=K; i>=0; --i)
        if (h[L[u][i]] >= h[v])
            mx = max(mx, Max[u][i]), u = L[u][i];
    if (u == v) return mx;
    for (int i=K; i>=0; --i) {
        if (L[u][i] - L[v][i]) {
            mx = max(mx, Max[u][i]);
            mx = max(mx, Max[v][i]);
            u = L[u][i];
            v = L[v][i];
        }
    }
    mx = max(mx, Max[u][0]);
    mx = max(mx, Max[v][0]);
    return mx;
}

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int find_set(int v) {
    return par[v] = v == par[v] ? v : find_set(par[v]);
}

int main() {
    int t, n, m, q;

    scanf("%d", &t);
    for (int Case=1; Case<=t; ++Case) {
        scanf("%d %d", &n, &m);

        vector<Edge> ed;
        for (int i=1; i<=m; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            ed.push_back({u, v, w});
        }

        sort(ed.begin(), ed.end(), cmp);

        for (int i=1; i<=n; ++i)
            par[i] = i, Size[i] = 1;

        g = vector<vector<pii>> (n+1, vector<pii> ());
        for (auto e : ed) {
            int u = find_set(e.u);
            int v = find_set(e.v);
            if (u != v) {
                if (Size[u] < Size[v]) swap(u, v);
                par[v] = u;
                Size[u] += Size[v];
                g[e.u].push_back({e.v, e.w});
                g[e.v].push_back({e.u, e.w});
            }
        }

        h[1] = -1;
        dfs(1, 1);

        printf("Case %d:\n", Case);
        scanf("%d", &q);
        while (q--) {
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%d\n", LCA(a, b));
        }
    }

    return 0;
}

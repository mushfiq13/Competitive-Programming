#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 99;

vector<bool> used;
vector<int> order, comp, sc, Count, d, Min;
vector<vector<int>> g, gr, adj;

void dfs(int v, int f) {
    used[v] = 1;

    vector<int> grap;
    grap = (f == 1) ? g[v] : gr[v];
    if (f == 2) comp.push_back(v);

    for (int to : grap)
        if (!used[to]) dfs(to, f);
    order.push_back(v);
}

int SCC(int n) {
    used.assign(n+1, false);
    order.clear();

    for (int i=1; i<=n; ++i)
        if (!used[i]) dfs(i, 1);

    used.assign(n+1, false);
    sc.assign(n+1, 0);
    Count.assign(n+1, 0);
    Min.assign(n+1, INF);

    int numScc = 0;
    for (int i=n-1; i>=0; --i) {
        if (!used[order[i]]) {
            ++numScc;
            comp.clear();
            dfs(order[i], 2);
            for (int v : comp) {
                sc[v] = numScc;
                Min[numScc] = min(Min[numScc], v);
            }
            Count[numScc] = comp.size();
        }
    }

    return numScc;
}

void construct(int n, int m) {
    adj = vector<vector<int>> (m+1);
    for (int i=1; i<=n; ++i)
        for (int to: g[i])
            if (sc[i] - sc[to])
                adj[sc[i]].push_back(sc[to]);
}

void dfs2(int v) {
    used[v] = 1;
    for (int to: adj[v]) {
        if (!used[to]) dfs2(to);
        d[v] = max(d[v], d[to]);
    }
    d[v] += Count[v];
}

int solve(int n) {
    d.assign(n+1, 0);
    used.assign(n+1, false);
    int mx = 0, ans = 0;
    for (int i=1; i<=n; ++i) {
        if (!used[i]) {
            dfs2(i);
            if (d[i] > mx)
                mx = d[i], ans = Min[i];
            else if (d[i] == mx)
                ans = min(Min[i], ans);
        }
    }
    return ans;
}

int main() {
    int t, n;

    scanf("%d", &t);
    for (int Case=1; Case<=t; ++Case) {
        scanf("%d", &n);

        g = gr = vector<vector<int>> (n+1);
        for (int i=1; i<=n; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            gr[v].push_back(u);
        }

        int k = SCC(n);
        construct(n, k);

        printf("Case %d: %d\n", Case, solve(k));
    }
}

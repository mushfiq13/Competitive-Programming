#include <bits/stdc++.h>
using namespace std;

const int N = (int)2e4 + 10;
const int INF = (int)1e9 + 10;

typedef pair<int, int> pii;

vector<int> order, comp, sc;
vector<int> used;
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
    order.clear();
    used.assign(n+1, false);
    for (int i=1; i<=n; ++i)
        if (!used[i]) dfs(i, 1);

    used.assign(n+1, 0);
    sc.assign(n+1, 0);
    int numScc = 0;
    for (int i=n-1; i>=0; --i) {
        if (!used[order[i]]) {
            ++numScc;
            comp.clear();
            dfs(order[i], 2);
            for (int x : comp) sc[x] = numScc;
        }
    }

    return numScc;
}

void construct(int n, int m) {
    adj = vector<vector<int>> (m+1);
    for (int i=1; i<=n; ++i) {
        for (int to : g[i]) {
            if (sc[i] - sc[to]) adj[sc[i]].push_back(sc[to]);
        }
    }
}


int solve(int n) {
    if (n == 1) return 0;

    vector<bool> indegree (n+1), outdegree (n+1);

    for (int i=1; i<=n; ++i) {
        for (int to : adj[i])
            indegree[to] = 1;
        if (adj[i].empty()) outdegree[i] = 1;
    }

    int a = 0, b = 0;
    for (int i=1; i<=n; ++i) {
        if (!indegree[i]) ++a;
        if (outdegree[i]) ++b;
    }

    return max(a, b);
}

int main() {
    int t, n, m;

    scanf("%d", &t);
    for (int Case=1; Case<=t; ++Case) {
        scanf("%d %d", &n, &m);

        g = gr = vector<vector<int>> (n+1);
        for (int i=1; i<=m; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            gr[v].push_back(u);
        }

        int k = SCC(n);
        construct(n, k);

        printf("Case %d: %d\n", Case, solve(k));
    }

    return 0;
}


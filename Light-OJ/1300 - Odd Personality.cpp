#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
const int N = 10000 + 5;

int timer, isBip;
int used[N], col[N];
int tin[N], low[N];

set<pii> bridge;
vector<vector<int>> g;

void dfsAP(int v, int p = -1) {
    used[v] = 1;
    low[v] = tin[v] = ++timer;

    for (int to : g[v]) {
        if (p == to) continue;
        if (!used[to]) {
            dfsAP(to, v);
            low[v] = min(low[v], low[to]);
            if (tin[v] < low[to])
                bridge.insert({min(v, to), max(v, to)});
        } else {
            low[v] = min(low[v], tin[to]);
        }
    }
}

int dfsCC(int v, int p) {
    used[v] = 1;

    int compSize = 1;
    for (int to : g[v]) {
        if (bridge.find({min(v, to), max(v, to)}) != bridge.end())
            continue;
        if (p - to && !used[to]) {
            col[to] = col[v] ^ 1;
            compSize += dfsCC(to, v);
        }
        if (col[v] == col[to]) isBip = 0;
    }

    return compSize;
}

int solve(int n) {
    timer = 0;
    bridge.clear();
    for (int i=0; i<n; ++i) {
        col[i] = used[i] = tin[i] = low[i] = 0;
    }

    for (int i=0; i<n; ++i)
        if (!used[i])
            dfsAP(i);

    fill(used, used+n, 0);
    int ans = 0;
    for (int i=0; i<n; ++i) {
        if (!used[i]) {
            isBip = 1;
            ans += dfsCC(i, i) * (isBip == 0);
        }
    }

    return ans;
}

int main() {
    int t, n, m, u, v;

    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas) {
        scanf("%d %d", &n, &m);

        g = vector<vector<int>> (n, vector<int>());
        for (int i=0; i<m; ++i) {
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        printf("Case %d: %d\n", cas, solve(n));
    }

    return 0;
}


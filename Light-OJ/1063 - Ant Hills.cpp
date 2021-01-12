#include <bits/stdc++.h>
using namespace std;

int timer, Count;
vector<char> used;
vector<vector<int>> g;
vector<int> time_in, low;

void init(int n) {
    timer = Count = 0;
    used.assign(n+1, 0);
    low.assign(n+1, 0);
    time_in.assign(n+1, 0);
    g = vector<vector<int>> (n+1, vector<int>());
}

void dfs(int v, int p = -1) {
    used[v] = 1;
    time_in[v] = low[v] = ++timer;
    int cnt = 0;
    for (int to : g[v]) {
        if (p == to) continue;
        if (!used[to]) {
            dfs(to, v);            
            low[v] = min(low[v], low[to]);
            if (time_in[v] <= low[to])
                ++cnt;
        } else {
            low[v] = min(low[v], time_in[to]);
        }
    }

    if (p > -1) ++cnt;
    Count += (cnt > 1);
}

int main() {
    int t, n, m, u, v;

    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas) {
        scanf("%d %d", &n, &m);

        init(n);

        for (int i=1; i<=m; ++i) {
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        dfs(1);
        printf("Case %d: %d\n", cas, Count);
    }

    return 0;
}

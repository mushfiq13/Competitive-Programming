#include <bits/stdc++.h>
using namespace std;

int timer;
vector<int> used;
vector<vector<int>> g;
vector<int> time_in, low;
map<int, int> mp;

void dfs(int v, int p = -1) {
    used[v] = 1;
    time_in[v] = low[v] = ++timer;
    int subtree = 0, cnt = 0;
    for (int to : g[v]) {
        if (p == to) continue;
        if (!used[to]) {
            dfs(to, v);
            ++subtree;
            low[v] = min(low[v], low[to]);
            printf("%d %d\n", v, to);
            if (time_in[v] < low[to]) {
                printf("%d %d\n", to, v);
            }
        } else {
            low[v] = min(low[v], time_in[to]);
            if (used[to] == 1)
                printf("%d %d\n", v, to);
        }
    }
    used[v] = 2;
}

void findBridges(int n) {
    timer = 0;
    used.assign(n+1, 0);
    low.assign(n+1, 0);
    time_in.assign(n+1, 0);
    for (int i=1; i<=n; ++i) {
        if (!used[i])
            dfs(i);
    }
}

int main() {
    int t, n, m, u, v;

    for (int cas = 1; ; ++cas) {
        scanf("%d %d", &n, &m);
        if (!n && !m) break;

        g = vector<vector<int>> (n+1, vector<int>());

        for (int i=1; i<=m; ++i) {
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        printf("%d\n\n", cas);
        findBridges(n);
        puts("#");
    }

    return 0;
}

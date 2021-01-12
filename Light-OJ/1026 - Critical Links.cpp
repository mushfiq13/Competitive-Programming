#include <bits/stdc++.h>
using namespace std;

int timer;
vector<char> used;
vector<vector<int>> g;
vector<int> time_in, low;
set<int> ans[10002];

void init(int n) {
    timer = 0;
    used.assign(n+1, 0);
    low.assign(n+1, 0);
    time_in.assign(n+1, 0);
    for (int i=0; i<n; ++i) {
        ans[i].clear();
    }
    g = vector<vector<int>> (n+1, vector<int>());
}

void dfs(int v, int p = -1) {
    used[v] = 1;
    time_in[v] = low[v] = ++timer;
    for (int to : g[v]) {
        if (p == to) continue;
        if (!used[to]) {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (time_in[v] < low[to])
                ans[min(v, to)].insert(max(v, to));
        } else {
            low[v] = min(low[v], time_in[to]);
        }
    }
}

void findBridges(int n) {
    for (int i=0; i<n; ++i) {
        if (!used[i])
            dfs(i);
    }
}

int main() {
    char ch;
    int t, n, u, v, k;

    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas) {
        scanf("%d", &n);

        init(n);

        for (int i=1; i<=n; ++i) {
            scanf("%d %c%d%c", &u, &ch, &k, &ch);
            while (k--) {
                scanf("%d", &v);
                g[u].push_back(v);
            }
        }

        findBridges(n);

        int cnt = 0;
        for (int i=0; i<n; ++i) {
            cnt += ans[i].size();
        }

        printf("Case %d:\n", cas);
        printf("%d critical links\n", cnt);
        for (int i=0; i<n; ++i) {
            if (ans[i].empty()) continue;
            for (int to : ans[i])
                printf("%d - %d\n", i, to);
        }
    }

    return 0;
}

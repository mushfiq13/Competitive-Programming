/*
 * this code find out, how many connected components are possible after removing a vertex.
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 10000 + 5;

int timer;
char used[N];
int par[N], Count[N];
int time_in[N], low[N];
vector<vector<int>> g;
vector<pair<int, int>> ans;

void dfs(int v, int p = -1) {
    used[v] = 1;
    par[v] = p;
    time_in[v] = low[v] = ++timer;
    
    // finding how many components will create after cutting v.
    for (int to : g[v]) {
        if (p == to) continue;
        if (!used[to]) {
            dfs(to, v);            
            low[v] = min(low[v], low[to]);
            if (time_in[v] <= low[to])
                ++Count[v]; // v is an AP, so, we need to send a pegion to its child.
        } else {
            low[v] = min(low[v], time_in[to]);
        }
    }

    // we checked for every child of v, but did not checked for its parent.
    // if v has a parent, then we should send a pegion for it.
    if (p > -1) ++Count[v];
}

void findCutVertices(int n) {
    timer = 0;
    ans.clear();
    for (int i=0; i<n; ++i) {
        used[i] = Count[i] = 0;
        time_in[i] = low[i] = 0;
    }

    dfs(0);

    for (int i=0; i<n; ++i) {                
        ans.push_back({i, Count[i]});
    }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second - b.second)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {    
    int n, m, u, v;

    while (scanf("%d %d", &n, &m)) {
        if (!n && !m) break;

        g = vector<vector<int>> (n+1, vector<int>());

        while (scanf("%d %d", &u, &v)) {
            if (u == -1 && v == -1) break;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        findCutVertices(n);

        sort(ans.begin(), ans.end(), cmp);
        for (int i=0; i<m; ++i)
            printf("%d %d\n", ans[i].first, ans[i].second);
        puts("");
    }

    return 0;
}
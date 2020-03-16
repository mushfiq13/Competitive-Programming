#include <bits/stdc++.h>
using namespace std;


const int MAX = (int)1e3 + 99;
const int INF = (int)1e9 + 99;

vector<bool> vis;
vector<pair<int, int>> g[MAX];

void dfs(int v, vector<int>& ans) {
    if (vis[v]) return;
    vis[v] = 1;
    ans.push_back(v);
    for (auto e : g[v])
        if (!vis[e.first])
            dfs(e.first, ans);
}

vector<int> bellmanFord(int n) {
    vector<int> d (n+1, 0);

    bool any;
    for (int i=1; i<=n; ++i) {
        any = false;
        for (int j=0; j<n; ++j) {
            for (auto e : g[j]) {
                if (d[e.first] > d[j] + e.second)
                    d[e.first] = d[j] + e.second, any = true;
            }
        }
    }

    if (!any) return vector<int> ();

    vis.assign(n+1, 0);
    vector<int> ans;
    for (int j=0; j<n; ++j)
        for (auto e : g[j])
            if (d[e.first] > d[j] + e.second)
                d[e.first] = d[j] + e.second, dfs(e.first, ans);

    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    int t, n, m;

    scanf("%d", &t);
    for (int Case=1; Case<=t; ++Case) {
        scanf("%d", &n);

        for (int i=0; i<n; ++i)
            g[i].clear();

        scanf("%d", &m);
        for (int i=1; i<=m; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            g[v].push_back({u, w});
        }

        vector<int> ans = bellmanFord(n);

        printf("Case %d:", Case);
        if (ans.empty()) printf(" impossible");
        else
            for (int x : ans)
                printf(" %d", x);
        puts("");
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> vis;
vector<int> adj[10000 + 10];

void dfs(const int v, int& ans) {
    vis[v] = 1;
    for (int to: adj[v])
        if (!vis[to])
            dfs(to, ans);
        else if (vis[to] == 1)
            return;
    vis[v] = 2;
    ++ans;
}

void topSort(const int n, int& ans) {
    vis.assign(n+1, 0);
    ans = 0;

    for (int i=1; i<=n; ++i)
        if (!vis[i])
            dfs(i, ans);
}

int main() {
    int test, n, ans;
    static char a[15], b[15];
    map<string, int> pp;

    scanf("%d", &test);
    for (int Case=1; Case<=test; ++Case) {
        pp.clear();
        int m = 0;

        scanf("%d", &n);
        for (int i=1; i<=n; ++i) {
            scanf("%s %s", &a, &b);
            if (!pp[a]) {
                pp[a] = ++m;
                adj[m].clear();
            }
            if (!pp[b]) {
                pp[b] = ++m;
                adj[m].clear();
            }
            adj[pp[a]].push_back(pp[b]);
        }

        topSort(m, ans);

        printf("Case %d: ", Case);
        if (ans == m) puts("Yes");
        else puts("No");
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 10;
typedef pair<int, int> pii;

int a[MAXN];
int Count, vis[MAXN];
vector<int> adj[MAXN];

pii dfs (int v) {
    pii p = {a[v], 1};
    for (int i=0, r=adj[v].size(); i<r; ++i) {
        int to = adj[v][i];
        if (vis[to] == 0) {
            vis[to] = 1;
            pii t = dfs(to);
            p.first += t.first;
            p.second += t.second;
        }
    }
    return p;
}

int main()
{
    int t, n, m;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; ++cs) {
        scanf("%d %d", &n, &m);

        int money = 0;
        for (int i=1; i<=n; ++i) {
            scanf("%d", &a[i]);
            money += a[i];
            vis[i] = 0;
            adj[i].clear();
        }

        bool flag = true;
        if (money % n) {
            flag = false;
        }

        for (int i=1; i<=m; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            if (flag) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        for (int i=1; flag && i <= n; ++i) {
            if (!vis[i]) {
                vis[i] = 1;
                pii p = dfs(i);
                if (p.second > 1 && p.first % p.second)
                    flag = false;
                else if (p.second == 1 && a[i] != money/n)
                    flag = false;
            }
        }

        if (flag == true)
            printf("Case %d: Yes\n", cs);
        else
            printf("Case %d: No\n", cs);
    }

    return 0;
}

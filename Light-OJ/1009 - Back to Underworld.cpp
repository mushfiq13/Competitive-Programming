#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e4 + 5;

vector<int> adj[MAXN];
int cntone, cntzero;
int vis[MAXN];

void dfs(int v)
{
    for (int i=0, sz = adj[v].size(); i<sz; ++i) {
        int to = adj[v][i];
        if (vis[to] == -1) {
            vis[to] = vis[v] ^ 1;
            if (vis[to] == 0) ++cntzero;
            else ++cntone;
            dfs(to);
        }
    }
}

int main()
{
    int t, n;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; ++cs) {
        for (int i=1; i<=MAXN; ++i) {
             vis[i] = -1;
             adj[i].clear();
        }
        scanf("%d", &n);
        int mnn = MAXN+1, mxn = 0;
        for (int i=1; i<=n; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
            mxn = max (mxn, max(u, v));
            mnn = min (mnn, min(u, v));
        }

        int ans = 0;
        for (int i = mnn; i <= mxn; ++i) {
            if (vis[i] == -1 && adj[i].size()) {
                cntone = 1;
                cntzero = 0;
                vis[i] = 1;
                dfs(i);
                ans += cntone > cntzero ? cntone : cntzero;
            }
        }

        printf("Case %d: %d\n", cs, ans);
    }

    return 0;
}

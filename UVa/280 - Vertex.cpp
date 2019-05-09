#include <bits/stdc++.h>
using namespace std;

const int Max = 101;

vector <int> adj[Max];
int vis[Max];

void dfs (int u)
{
    for (int i=0, sz=adj[u].size(); i<sz; ++i) {
        int v = adj[u][i];
        if (vis[v] == 0) {
            vis[v] = 1;
            dfs(v);
        }
    }
}

int main()
{
    int n, q, s, v;

    while (cin >> n, n) {
        for (int i=1; i<=n; ++i)
            adj[i].clear();

        while (cin >> s, s) {
            while (cin >> v && v)
                adj[s].push_back(v);
        }

        cin >> q;
        while (q--) {
            cin >> s;
            for (int i=1; i<=n; ++i)
                vis[i] = 0;
            dfs(s) ;
            int c = 0;
            for (int i=1; i<=n; ++i)
                if (vis[i] == 0) ++c ;
            cout << c;
            for (int i=1; i<=n; ++i)
                if (vis[i] == 0)
                    printf(" %d", i);
            puts("");
        }
    }
}

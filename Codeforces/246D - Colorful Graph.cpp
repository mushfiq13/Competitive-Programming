#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 5;

bool mp[MAX];
int c[MAX];
vector<int> V[MAX], adj[MAX];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; ++i) {
        cin >> c[i];
        V[c[i]].push_back(i);
    }
    for (int i=1; i<=m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int maxc, mx = 0;
    for (int i=1; i<=n; ++i) {
        if (mp[c[i]] == 0) {
            mp[c[i]] = 1;
            int cnt = 0;
            map<int,int> diverse;
            for (int j=0, sz=V[c[i]].size(); j < sz; ++j) {
                int node = V[c[i]][j];
                for (int k=0, r=adj[node].size(); k < r; ++k)
                    if (c[adj[node][k]] != c[i] && diverse[c[adj[node][k]]] == 0)
                        ++cnt, diverse[c[adj[node][k]]] = 1;
            }
            if (cnt > mx)
                mx = cnt, maxc = c[i];
            else if (cnt == mx)
                maxc = min(maxc, c[i]);
        }
    }

    cout << maxc << endl;

    return 0;
}

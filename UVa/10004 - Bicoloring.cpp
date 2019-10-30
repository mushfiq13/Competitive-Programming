#include <bits/stdc++.h>
using namespace std;

const int MAX = 200 + 10;

vector<int> adj[MAX];

bool bfs (int n, int s) {
    queue<int> q;
    vector<int> col (n, 0);
    vector<bool> used (n, 0);

    q.push (s);
    used[s] = 1;
    col[s] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : adj[v]) {
            if (used[to] && col[to] == col[v])
                return false;
            else if (!used[to]) {
                used[to] = 1;
                col[to] = (col[v]+1) % 2;
                q.push(to);
            }
        }
    }

    return true;
}

int main() {
    int n, m;

    while (cin >> n, n) {
        cin >> m;
        for (int i=0; i<n; ++i)
            adj[i].clear();
        for (int i=0; i<m; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        if (bfs (n, 0)) puts("BICOLORABLE.");
        else puts("NOT BICOLORABLE.");
    }

    return 0;
}

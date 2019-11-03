#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 1e5 + 10;
const int INF = 1e9;

vector<pii> adj[MAX];

int bfs (int n) {
    deque<int> q;
    vector<int> d (n+1, INF);

    q.push_front (1);
    d[1] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (auto e : adj[v]) {
            int to = e.second, len = e.first;
            if (d[to] > d[v] + len) {
                d[to] = d[v] + len;
                if (len) q.push_back (to);
                else q.push_front (to);
            }
        }
    }

    return d[n] == INF ? -1 : d[n];
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);
    for (int i=1; i<=m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back ({0, y});
        adj[y].push_back ({1, x});
    }

    printf ("%d\n", bfs (n));
    return 0;
}

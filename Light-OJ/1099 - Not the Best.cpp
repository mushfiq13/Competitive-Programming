#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int
        MAX = 5000 + 10,
        INF = 1e9;

vector<pii> adj[MAX];

int dijkstra (int n) {
    priority_queue<pii> pq;
    vector<int> d (n+1, INF), d2 (n+1, INF);

    d[1] = 0;
    pq.push (make_pair (0, 1));
    while (!pq.empty()) {
        int v = pq.top().second, cur_d = -pq.top().first;
        pq.pop();
        if (cur_d > d[v]) {
            continue;
        }

        for (pii e : adj[v]) {
            int to = e.second, len = e.first;
            if (d[to] > d[v] + len) {
                d2[to] = min (d[to], min (d2[v]+len, d[v]+3*len));
                d[to] = d[v] + len;
                pq.push (make_pair (-d[to], to));
            }
            else if (to > 1 || to == v) {
                d2[to] = min (d2[to], min (d2[v]+len, d[v]+3*len));
                if (d[v]+len != d[to])
                    d2[to] = min (d2[to], d[v]+len);
            }
        }
    }

    int t = INF;
    for (pii e: adj[1])
        t = min (t, 2*e.first);

    return min (d2[n], d[n]+t);
}

int main() {
    int t, n, r;

    scanf("%d", &t);
    for (int cs = 1; cs <= t; ++cs) {
        scanf("%d %d", &n, &r);

        for (int i=1; i<=n; ++i)
            adj[i].clear();

        for (int i=1; i<=r; ++i) {
            int x, y, w;
            scanf("%d %d %d", &x, &y, &w);
            adj[x].push_back(make_pair(w, y));
            adj[y].push_back(make_pair(w, x));
        }

        printf("Case %d: %d\n", cs, dijkstra(n));
    }

    return 0;
}

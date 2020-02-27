#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b, w;
};

const int INF = (int)1e9;
vector<Edge> edge;

void bellmanFord(int n, vector<int>& d) {
    d.assign(n+1, INF);
    d[1] = 0;
    for (int i=1; i<n; ++i) {
        for (auto e: edge) {
            if (d[e.a] < INF && d[e.b] > d[e.a]+e.w)
                d[e.b] = d[e.a] + e.w;
        }
    }

    for (auto e: edge)
        if (d[e.a] < INF && d[e.b] > d[e.a]+e.w)
            d[e.b] = -INF;
}

int main() {
    int n, m;

    for (int Case=1; scanf("%d", &n) == 1; ++Case) {
        int busy[n+1];
        for (int i=1; i<=n; ++i)
            cin >> busy[i];

        edge.clear();
        cin >> m;
        while (m--) {
            int u, v;
            cin >> u >> v;
            int d = busy[v] - busy[u];
            int cost = d*d*d;
            edge.push_back({u,v,cost});
        }

        vector<int> d (n+1);
        bellmanFord(n, d);

        printf("Set #%d\n", Case);
        int q;
        cin >> q;
        while (q--) {
            int v;
            cin >> v;
            if (d[v]==INF || d[v]==-INF || d[v] < 3) puts("?");
            else cout << d[v] << endl;
        }
    }

    return 0;
}

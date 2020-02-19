#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b, w;
};

vector<Edge> edge;

bool bellmanFord(int n, int src) {
    int INF = INT_MIN;
    vector<int> d (n+1, INF);

    d[src] = 0;
    for (int i=1; i<=n; ++i) {
        for (auto e: edge) {
            if (d[e.a]>INF && d[e.b] < d[e.a]+e.w)
                d[e.b] = d[e.a] + e.w;
        }
    }

    if (d[src] > 0) return true;
    return false;
}

int main() {
    int n, b;

    while (cin >> n >> b) {
        if (!n && !b) return 0;

        edge.clear();
        while (b--) {
            int u, v, w;
            cin >> u >> v >> w;
            edge.push_back({u,v,w});
            edge.push_back({v,u,-w});
        }

        bool ok = false;
        for (int i=1; i<=n && !ok; ++i) {
            if (bellmanFord(n, i))
                ok = true;
        }

        if (ok) puts("Y");
        else puts("N");
    }

    return 0;
}

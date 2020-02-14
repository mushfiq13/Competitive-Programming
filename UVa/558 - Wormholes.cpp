#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

bool bellmanFord(int n, int m, vector<Edge>& edge) {
    const int INF = (int)1e9;
    vector<int> d (n, INF);

    d[edge[0].u] = 0;
    for (int i=0; i<n; ++i) {
        bool any = false;
        for (Edge e: edge) {
            if (e.u != INF && d[e.v] > d[e.u] + e.w) {
                d[e.v] = d[e.u] + e.w;
                any = true;
            }
        }
        if (!any) return true;
    }

    return false;
}

int main() {
    int t, n, m, x, y, w;
    vector<Edge> edge;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        edge.clear();
        for (int i=0; i<m; ++i) {
            cin >> x >> y >> w;
            edge.push_back({x, y, w});
        }

        if (bellmanFord(n, m, edge)) puts("not possible");
        else puts("possible");
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b, w;
};

const int INF = (int)1e9;

int main() {
    int n, r;
    int c1, c2, p;
    vector<Edge> edge;

    for (int Case=1; ; ++Case) {
        cin >> n >> r;
        if (!n && !r) return 0;

        edge.clear();
        for (int i=1; i<=r; ++i) {
            cin >> c1 >> c2 >> p;
            edge.push_back({c1,c2,p});
            edge.push_back({c2,c1,p});
        }

        int src, dest, passen;
        cin >> src >> dest >> passen;

        if (src == dest) {
            printf("Scenario #%d\nMinimum Number of Trips = 0\n\n", Case);
            continue;
        }

        vector<int> d(n+1, INF);
        for (Edge e: edge)
            if (e.a == src)
                d[e.b] = e.w;

        for (int i=1; i<=n; ++i) {
            for (Edge e: edge) {
                if (d[e.a] != INF) {
                    if (d[e.b] == INF && e.b != src)
                        d[e.b] = min(d[e.a], e.w);
                    else
                        d[e.b] = max(d[e.b], min(d[e.a], e.w));
                }
            }
        }

        --d[dest];
        int ans = passen / d[dest];
        if (passen % d[dest]) {
            passen = passen%d[dest] + 1;
            ++d[dest];
            ans += passen / d[dest];
            if (passen % d[dest]) ++ans;
        }

        printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", Case, ans);
    }

    return 0;
}

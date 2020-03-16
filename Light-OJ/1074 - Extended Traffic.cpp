#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b, w;
};

const int INF = (int)1e9 + 99;

vector<Edge> edge;

vector<int> bellmanFord(int n) {
    vector<int> d (n+1, INF);

    d[1] = 0;
    for (int i=1; i<n; ++i)
        for (auto e : edge)
            if (d[e.a]<INF && d[e.b] > d[e.a] + e.w)
                d[e.b] = d[e.a] + e.w;

    //for (int i=1; i<n; ++i)
        for (auto e : edge)
            if (d[e.a]<INF && d[e.b] > d[e.a] + e.w)
                d[e.b] = -INF;

    return d;
}

int main() {
    int t, n, m, q;

    scanf("%d", &t);
    for (int Case=1; Case<=t; ++Case) {
        scanf("%d", &n);

        int busy[n+1];
        for (int i=1; i<=n; ++i)
            scanf("%d", &busy[i]);

        edge.clear();
        scanf("%d", &m);
        for (int i=1; i<=m; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            int w = busy[v] - busy[u];
            edge.push_back({u, v, w*w*w});
        }

        vector<int> d = bellmanFord(n);

        scanf("%d", &q);
        printf("Case %d:\n", Case);
        while (q--) {
            int to;
            scanf("%d", &to);
            if (d[to]<3 || d[to]==INF) puts("?");
            else printf("%d\n", d[to]);
        }
    }

    return 0;
}

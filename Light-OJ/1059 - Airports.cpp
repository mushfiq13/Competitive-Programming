#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 99;

struct Edge {
    int u, v, w;
    bool operator<(Edge const& other) {
        return w < other.w;
    }
};

int par[N], Size[N];
vector<Edge> edge;

int find_set(int v) {
    return par[v] = v == par[v] ? v : find_set(par[v]);
}

pair<int, int> Kruskal(int n, int m, int A) {
    for (int i=1; i<=n; ++i)
        par[i] = i, Size[i] = 1;

    sort(edge.begin(), edge.end());

    int Y = 0;
    vector<bool> used (m, 0);
    for (int i=0; i<m; ++i) {
        Edge e = edge[i];
        int u = find_set(e.u);
        int v = find_set(e.v);
        if (u - v && e.w < A) {
            if (Size[u] < Size[v])
                swap(u, v);
            par[v] = u;
            Size[u] += Size[v];
            Y += e.w;
        }
    }

    int Z = 0;
    for (int i=1; i<=n; ++i)
        if (find_set(i) == i)
            ++Z, Y += A;

    return {Y, Z};
}

int main() {
    int t, n, m, A;

    scanf("%d", &t);

    for (int Case=1; Case<=t; ++Case) {
        scanf("%d %d %d", &n, &m, &A);

        edge.clear();
        for (int i=1; i<=m; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            edge.push_back({u,v,w});
        }

        pair<int, int> ans = Kruskal(n, m, A);
        printf("Case %d: %d %d\n", Case, ans.first, ans.second);
    }

    return 0;
}



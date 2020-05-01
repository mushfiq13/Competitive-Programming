#include <bits/stdc++.h>
using namespace std;

const int N = 50 + 99;
const int INF = (int)1e9 + 99;

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

int Kruskal(int n) {
    for (int i=1; i<=n; ++i)
        par[i] = i, Size[i] = 1;

    sort(edge.begin(), edge.end());

    int cnt = 0, weight = 0;
    for (Edge e : edge) {
        int u = find_set(e.u);
        int v = find_set(e.v);
        if (u - v) {
            if (Size[u] < Size[v])
                swap(u, v);
            par[v] = u;
            Size[u] += Size[v];
            weight += e.w;
            ++cnt;
        }
    }

    return cnt+1 == n ? weight : INF;
}

int main() {
    int t, m;

    scanf("%d", &t);
    for (int Case=1; Case<=t; ++Case) {
        scanf("%d", &m);

        map<string, int> pp;
        int n = 0;
        edge.clear();
        for (int i=0; i<m; ++i) {
            string a, b;
            int w;
            cin >> a >> b >> w;
            if (!pp[a]) pp[a] = ++n;
            if (!pp[b]) pp[b] = ++n;
            edge.push_back({pp[a],pp[b],w});
        }

        int ans = Kruskal(n);

        if (ans == INF)
            printf("Case %d: Impossible\n", Case);
        else
            printf("Case %d: %d\n", Case, ans);
    }

    return 0;
}

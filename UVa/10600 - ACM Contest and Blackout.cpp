#include <bits/stdc++.h>
using namespace std;

const int N = (int)100 + 99;
const int INF = (int)1e9 + 99;

struct Edge {
    int u, v, w, enable;
};

bool used[N*N];
int par[N], Size[N];
vector<Edge> edge;

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int find_set(int v) {
    return par[v] = v == par[v] ? v : find_set(par[v]);
}

int Kruskal(int n, int m, int f = 0) {
    for (int i=1; i<=n; ++i)
        par[i] = i, Size[i] = 1;

    int weight = 0, cnt = 0;
    for (int i=0; i<m; ++i) {
        Edge e = edge[i];
        if (e.enable == 0) continue;
        int u = find_set(e.u);
        int v = find_set(e.v);
        if (u - v) {
            if (Size[u] < Size[v])
                swap(u, v);
            par[v] = u;
            Size[u] += Size[v];
            weight += e.w;
            ++cnt;
            if (f) used[i] = 1;
        }
    }

    return cnt+1 == n ? weight : INF;
}

int main(int argc, char ** argv) {
    int t, n, m;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &m);

        edge.clear();
        for (int i=1; i<=m; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            edge.push_back({u,v,w,1});
        }

        sort(edge.begin(), edge.end(), cmp);
        fill(used, used+m+5, 0);

        int fMST = Kruskal(n, m, 1);
        int sMST = INF;

        for (int i=0; i<m; ++i) {
            Edge e = edge[i];
            if (used[i] == 1) {
                edge[i].enable = 0;
                sMST = min(sMST, Kruskal(n, m));
                edge[i].enable = 1;
            }
        }

        printf("%d %d\n", fMST, sMST);
    }

    return 0;
}

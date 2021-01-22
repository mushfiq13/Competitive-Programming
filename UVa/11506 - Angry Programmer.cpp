#include <bits/stdc++.h>
using namespace std;

const int N = 100;

struct Edge {
    int from, to, cap, f;
};

vector<int> g[N];
vector<Edge> edgeTab;
int pred[N], predEdge[N];

void init(int n) {
    edgeTab.clear();
    for (int i=0; i<=100; ++i)
        g[i].clear();
}

void addEdge(int from, int to, int w) {
    Edge ed;

    ed = {from, to, w, 0};
    edgeTab.push_back(ed);
    g[from].push_back(edgeTab.size()-1);

    ed = {to, from, w, w};
    edgeTab.push_back(ed);
    g[to].push_back(edgeTab.size()-1);
}

char bfs(int n, int src, int sink) {
    queue<int> q;

    fill(pred, pred+n+1, -1);
    pred[src] = -2;
    q.push(src);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i : g[v]) {
            int to = edgeTab[i].to;
            if (pred[to] == -1 && edgeTab[i].cap > edgeTab[i].f) {
                pred[to] = v;
                predEdge[to] = i;
                q.push(to);
                if (to == sink) return 1;
            }
        }
    }

    return 0;
}

int maxFlow(int n, int src, int sink) {
    int mf = 0;
    while (bfs(n, src, sink)) {
        int minCap = (int)1e9;
        for (int cur = sink; pred[cur] > -1; cur = pred[cur]) {
            int i = predEdge[cur];
            minCap = min(minCap, edgeTab[i].cap-edgeTab[i].f);
        }

        for (int cur = sink; pred[cur] > -1; cur = pred[cur]) {
            int i = predEdge[cur];
            edgeTab[i].f += minCap;
            edgeTab[i^1].f -= minCap;
        }
        mf += minCap;
    }
    return mf;
}

int main() {
    int t, m, w;
    int u, v, cost;

    while (scanf("%d %d", &m, &w)) {
        if (!m && !w) break;

        init(m+m);

        for (int i=2; i<m; ++i) {
            int machine;
            scanf("%d %d", &machine, &cost);
            addEdge(machine, m+machine-1, cost);
        }

        for (int i=1; i<=w; ++i) {
            scanf("%d %d %d", &u, &v, &cost);
            if (u-1 && u-m) addEdge(u+m-1, v, cost);
            else addEdge(u, v, cost);
            if (v-1 && v-m) addEdge(v+m-1, u, cost);
            else addEdge(v, u, cost);
        }

        printf("%d\n", maxFlow(m+m-2, 1, m));
    }
}

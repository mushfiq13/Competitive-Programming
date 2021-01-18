#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9;
const int N = 100 + 10;

struct Edge {
    int from, to, capacity, flow;
};

vector<int> pred, predEdge;
vector<Edge> edgeTab;
vector<int> g[N];

void init(int n) {
    edgeTab.clear();
    for (int i=0; i<=n; ++i)
        g[i].clear();
}

void addEdge(int from, int to, int weight) {
    Edge ed = {from, to, weight, 0}; // orginal edges
    edgeTab.push_back(ed);
    g[from].push_back(edgeTab.size()-1);

    ed = {to, from, weight, weight}; // residual edges
    edgeTab.push_back(ed);
    g[to].push_back(edgeTab.size()-1);
}

int bfs(int n, int source, int sink) {
    queue<int> q;

    pred.assign(n+1, -1);
    predEdge.assign(n+1, -1);

    pred[source] = -2;
    q.push(source);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i : g[v]) {
            int to = edgeTab[i].to;
            if (pred[to] == -1 && edgeTab[i].capacity - edgeTab[i].flow > 0) {
                pred[to] = v;
                predEdge[to] = i;
                q.push(to);
                if (to == sink) return 1;
            }
        }
    }

    return 0;
}

int getMaxFlow(int n, int source, int sink) {
    int maxFlow = 0;

    while (bfs(n, source, sink)) {
        int minCapacity = INF;
        for (int cur = sink; pred[cur] > -1; cur = pred[cur]) {
            int i = predEdge[cur];
            minCapacity = min(minCapacity, edgeTab[i].capacity - edgeTab[i].flow);
        }

        for (int cur = sink; pred[cur] > -1; cur = pred[cur]) {
            int i = predEdge[cur];
            edgeTab[i].flow += minCapacity;
            edgeTab[i^1].flow -= minCapacity;
        }

        maxFlow += minCapacity;
    }

    return maxFlow;
}

int main() {
    int t, n, m, src, sink;

    scanf("%d", &t);
    for (int cas=1; cas<=t; ++cas) {
        scanf("%d", &n);

        init(n);

        scanf("%d %d %d", &src, &sink, &m);
        for (int i=1; i<=m; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }

        printf("Case %d: %d\n", cas, getMaxFlow(n, src, sink));
    }
}

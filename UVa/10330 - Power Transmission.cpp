#include <bits/stdc++.h>
using namespace std;

const int INF   = 1e9;
const int N     = 400 + 10;

struct Edge {
    int from, to, capacity, flow;
};

vector<int> g[N];
vector<Edge> edgeTab;
int pred[N], predEdge[N];

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

    fill(pred, pred+n+2, -1);
    fill(predEdge, predEdge+n+2, -1);

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
    int n, m, b, d, x;

    while (~scanf("%d", &n)) {
        init(n+n+3);

        for (int i=1; i<=n; ++i) {
            scanf("%d", &x);
            addEdge(i, i+n, x);
        }

        scanf("%d", &m);
        for (int i=1; i<=m; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            addEdge(u+n, v, w);
        }

        scanf("%d %d", &b, &d);
        while (b--) {
            scanf("%d", &x);
            addEdge(0, x, INF);
        }

        while (d--) {
            scanf("%d", &x);
            addEdge(x+n, n+n+1, INF);
        }

        printf("%d\n", getMaxFlow(n+n+1, 0, n+n+1));
    }
}

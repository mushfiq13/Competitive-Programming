#include <bits/stdc++.h>
using namespace std;

const int N = 100;

struct Edge {
    int from, to, cap, f;
};

vector<int> g[N];
vector<Edge> edgeTab;
int pred[N], predEdge[N];

void init() {
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
        ++mf;
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
    }
    return mf;
}

int main() {
    int t, n, m;
    string a, b;

    scanf("%d", &t);
    for (int cas=1; cas<=t; ++cas) {
        scanf("%d %d", &n, &m);
        cin.ignore();

        init();

        map<string, int> mp;
        int q = m;
        for (int i=1; i<=m; ++i) {
            cin >> a >> b;
            if (!mp[a]) mp[a] = ++q;
            if (!mp[b]) mp[b] = ++q;
            addEdge(0, i, 1);
            addEdge(i, mp[a], 1);
            addEdge(i, mp[b], 1);
        }

        for (int i=m+1; i<=q; ++i) {
            addEdge(i, q+1, n/6);
        }

        if (maxFlow(q+1, 0, q+1) == m) puts("YES");
        else puts("NO");
    }
}

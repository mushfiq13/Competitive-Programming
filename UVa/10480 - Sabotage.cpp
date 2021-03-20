#include <bits/stdc++.h>
using namespace std;

const int N = 51;

struct Edge {
    int from, to;
    long long flow, capacity;
};

char used[N][N];
vector<int> g[N];
vector<Edge> edgeTab;
int pred[N], predEdge[N];

void init(int n) {
    edgeTab.clear();
    for (int i=0; i<=n; ++i)
        g[i].clear();
}

void addEdge(int from, int to, long long capacity) {
    Edge ed = {from, to, 0, capacity}; // orginal edges
    edgeTab.push_back(ed);
    g[from].push_back(edgeTab.size()-1);

    ed = {to, from, capacity, capacity}; // backward edges
    edgeTab.push_back(ed);
    g[to].push_back(edgeTab.size()-1);
}

bool bfs(int n, int src, int sink) {
	fill(pred, pred+n+1, -1);
    fill(predEdge, predEdge+n+1, -1);
    queue<int> q;

    pred[src] = -2;    
    q.push(src);
    while (!q.empty()) {
        int v = q.front();
        q.pop();        
        if (v == sink) return 1;
        for (int i : g[v]) {
            int to = edgeTab[i].to;
            if (pred[to] == -1 && edgeTab[i].capacity - edgeTab[i].flow > 0) {
                pred[to] = v;
                predEdge[to] = i;                                
                q.push(to);                
            }
        }
    }

    return 0;
}

void maxFlow(int n, int src, int sink) {    
    while (bfs(n, src, sink)) {
    	long long minCapacity = (long long)2e18;

	    for (int cur = sink; cur != src; cur = pred[cur]) {
	        int i = predEdge[cur];
	        minCapacity = min(minCapacity, edgeTab[i].capacity - edgeTab[i].flow);
	    }

	    for (int cur = sink; cur != src; cur = pred[cur]) {
	        int i = predEdge[cur];
	        edgeTab[i].flow += minCapacity;
	        edgeTab[i^1].flow -= minCapacity;
	    }       
    }
}

void minCut(int n) {
	for (int i=1; i<=n; ++i)
		for (int j=1; j<=n; ++j)
			used[i][j] = 0;

	for (auto e : edgeTab) {
		int u = e.from, v = e.to;
		if (pred[u] != -1 && pred[v] == -1 && !used[u][v]) {
			printf("%d %d\n", u, v);;
			used[u][v] = 1;
		}
	}
}

int main() {
	int n, m;

	while (scanf("%d %d", &n, &m)) {
		if (!n && !m) return 0;

		init(n);

		int u, v;
		long long w;
		for (int i=1; i<=m; ++i) {			
			scanf("%d %d %lld", &u, &v, &w);
			addEdge(u, v, w);
			addEdge(v, u, w);
		}

		maxFlow(n, 1, 2);		
		minCut(n);		

		puts("");
	}

	return 0;
}
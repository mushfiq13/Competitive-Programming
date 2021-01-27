/*
Similar problem: LOJ :: 1262 - Diagonal Sum
Description written on the above problem
*/
#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int from, to, capacity, flow;
};

vector<int> g[42];
vector<Edge> edgeTab;
int rSum[22], cSum[22];
int pred[42], predEdge[42];

void add_edge(int u, int v,  int cap) {
	Edge ed = {u, v, cap, 0};
	edgeTab.push_back(ed);
	g[u].push_back(edgeTab.size()-1);
	ed = {v, u, cap, cap};
	edgeTab.push_back(ed);
	g[v].push_back(edgeTab.size()-1);
}

char bfs(int src, int sink) {
	queue<int> q;

	pred[src] = -2;
	q.push(src);
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

char augmentPath(int n, int src, int sink) {
	fill(pred, pred+n+1, -1);
	fill(predEdge, predEdge+n+1, -1);
	return bfs(src, sink);
}

int increaseFlow(int src, int sink) {
	int minCapacity = (int)1e9;

    for (int cur = sink; pred[cur] > -1; cur = pred[cur]) {
        int i = predEdge[cur];
        minCapacity = min(minCapacity, edgeTab[i].capacity - edgeTab[i].flow);
    }

    for (int cur = sink; pred[cur] > -1; cur = pred[cur]) {
        int i = predEdge[cur];
        edgeTab[i].flow += minCapacity;
        edgeTab[i^1].flow -= minCapacity;
    }

    return minCapacity;
}

int maxFlow(int n, int src, int sink) {
	int mf = 0;
	while (augmentPath(n, src, sink)) {
		mf += increaseFlow(src, sink);
	}
	return mf;
}

int main() {
	int t, n, m;	

	scanf("%d", &t);
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d %d", &n, &m);

		edgeTab.clear();
		for (int i=0; i<=n+m+1; ++i)
			g[i].clear();

		for (int i=1; i<=n; ++i)
			scanf("%d", &rSum[i]);

		for (int i=1; i<=m; ++i)
			scanf("%d", &cSum[i]);

		//construct Graph
		for (int i=1; i<=n; ++i) {
			add_edge(0, i, rSum[i]-rSum[i-1] - m);
			for (int j=1; j<=m; ++j) {
				add_edge(i, n+j, 19);
			}
		}

		for (int i=1; i<=m; ++i) {
			add_edge(i+n, n+m+1, cSum[i]-cSum[i-1] - n);
		}

		maxFlow(n+m+1, 0, n+m+1);
		printf("Matrix %d\n", cas);
		for (int v=1; v<=n; ++v) {
			for (int i=1; i<g[v].size(); ++i) {
				if (i>1) putchar(' ');
				printf("%d", edgeTab[g[v][i]].flow + 1);
			}
			puts("");
		}
		puts("");
	}

	return 0;
}

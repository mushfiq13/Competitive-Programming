#include <bits/stdc++.h>
using namespace std;

const int dx[] = {+0, +0, +1, -1};
const int dy[] = {+1, -1, +0, +0};
const int N = 5000 + 5;
const int INF = (int)1e9;

struct Edge {
    int from, to, flow, capacity;
};

vector<int> g[N];
vector<Edge> edgeTab;
int pred[N], predEdge[N];

void init(int n) {
    edgeTab.clear();
    for (int i=0; i<=n; ++i)
        g[i].clear();
}

void addEdge(int from, int to, int capacity) {
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

int maxFlow(int n, int src, int sink) {
	int mf = 0;
    while (bfs(n, src, sink)) {
    	int minCapacity = (int)1e8;

	    for (int cur = sink; cur != src; cur = pred[cur]) {
	        int i = predEdge[cur];
	        minCapacity = min(minCapacity, edgeTab[i].capacity - edgeTab[i].flow);
	    }

	    for (int cur = sink; cur != src; cur = pred[cur]) {
	        int i = predEdge[cur];
	        edgeTab[i].flow += minCapacity;
	        edgeTab[i^1].flow -= minCapacity;
	    }

	    mf += minCapacity;
    }

    return mf;
}

int main() {
	int t, n, m, k;
	int cell[52][52];

	scanf("%d", &t);
	for (int cas = 1; cas <= t; ++cas) {
		scanf("%d %d %d", &n, &m, &k);
		
		swap(n, m);

		int u, v;
		for (int i=1; i<=k; ++i) {
			scanf("%d %d", &u, &v);
			swap(u, v);
			cell[u][v] = cas;		
		}

		init(n*m*2+1);
		
		for (int i=1; i<=n; ++i) {
			for (int j=1; j<=m; ++j) {
				int curVertex = (i-1) * m + j;
				if (cell[i][j] == cas){
					addEdge(0, curVertex, 1);
				}
				if (i == 1 || j == 1 || i == n || j == m) {
					addEdge(curVertex + n*m, n*m*2+1, 1);
				}
				addEdge(curVertex, curVertex + n*m, 1);
				for (int q=0; q<4; ++q) {
					int tx = dx[q] + i;
					int ty = dy[q] + j;
					int tVertex = (tx-1) * m + ty;
					if (tx > 0 && tx <= n && ty > 0 && ty <= m && cell[tx][ty] - cas) {
						addEdge(curVertex + n*m, tVertex, 1);
					}
				}
			}
		}		

		if (maxFlow(n*m*2+1, 0, n*m*2+1) == k)
			printf("possible\n");
		else
			printf("not possible\n");
	}

	return 0;
}
/*
3
4 4 8 
4 2
4 3
3 2
3 3
3 4
2 1
2 4
1 3

6 6 10
4 1
3 2
4 2
5 2
3 4
4 4
5 4
3 6
4 6
5 6

5 5 5
3 2
2 3
3 3
4 3
3 4

*/
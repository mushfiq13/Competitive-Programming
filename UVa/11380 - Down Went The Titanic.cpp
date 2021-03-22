#include <bits/stdc++.h>
using namespace std;

const int dx[] = {+0, +0, +1, -1};
const int dy[] = {+1, -1, +0, +0};
const int N = 2000;
const int INF = (int)1e9;

struct Edge {
    int from, to;
    long long flow, capacity;
};

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

int maxFlow(int n, int src, int sink) {
	int mf = 0;
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

	    mf += minCapacity;
    }

    return mf;
}

int main() {
	int n, m, k;
	char s[30][31];	

	while (scanf("%d %d %d", &n, &m, &k) == 3) {
		init(n*m*2+10);
		
		int cur = 0;
		for (int i=0; i<n; ++i) {
			scanf("%s", s[i]);
			for (int j=0; j<m; ++j) {
				int curVertex = i * m + j + 1;
				// source to *
				if (s[i][j] == '*') {
					addEdge(0, curVertex, 1);
					addEdge(curVertex, 0, 1);
				}
				// # to sink
				if (s[i][j] == '#') {
					addEdge(curVertex+n*m, n*m*2+1, k);
					addEdge(n*m*2+1, curVertex+n*m, k);
				}

				// Now split every cell/vertex into two vertices

				if (s[i][j] == '#') {
					addEdge(curVertex, curVertex+n*m, INF);
					addEdge(curVertex+n*m, curVertex, INF);
				}
				else if (s[i][j] == '@') {
					addEdge(curVertex, curVertex+n*m, INF);
					addEdge(curVertex+n*m, curVertex, INF);
				}
				else if (s[i][j] == '~') {
					addEdge(curVertex, curVertex+n*m, 0);
					addEdge(curVertex+n*m, curVertex, 0);
				}
				else {
					addEdge(curVertex, curVertex+n*m, 1);
					addEdge(curVertex+n*m, curVertex, 1);
				}
			}
		}

		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				if (s[i][j] == '~') continue;
				int curVertex = i * m + j + 1;
				for (int q=0; q<4; ++q) {
					int tx = dx[q] + i;
					int ty = dy[q] + j;
					if (tx>=0 && tx<n && ty>=0 && ty<m && s[tx][ty] != '~' && s[tx][ty] != '*') {								
						addEdge(curVertex+n*m, tx * m + ty + 1, INF);
					}
				}
			}
		}

		printf("%d\n", maxFlow(n*m*2+1, 0, n*m*2+1));
	}

	return 0;
}
/*

2 4 1
**##
...~
output: 2

*/
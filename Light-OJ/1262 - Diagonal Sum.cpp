/*
Before solve this problem, solve UVa 11082 - Matrix Decompressing
This will be easier to solve this problem.
*/

#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int from, to, capacity, flow;
};

vector<int> g[205];
vector<Edge> edgeTab;
int pred[205], predEdge[205];

int ans[205][205], cnt[205];
int leftSum[105], rightSum[105];	// to take input
int leftV[52][52], rightV[52][52];	// store the desired diagonal to [][].

void init(int n, int m) {
	edgeTab.clear();
	for (int i=0; i<=(n+m-1)*2+1; ++i) {
		g[i].clear();
		cnt[i] = 0;
	}

	int v = 1;
	for (int i=0; i<n; ++i) {
		for (int j=0; j<m; ++j) {
			/* store  diagonal to ech cell fow left side */
			if (i-1>=0 && j+1<m) leftV[i][j] = leftV[i-1][j+1];
			else leftV[i][j] = v++;
		}
	}

	for (int i=0; i<n; ++i) {
		for (int j=m-1; j>=0; --j) {
			/* store  diagonal to ech cell for right side */
			if (i-1>=0 && j-1>=0) rightV[i][j] = rightV[i-1][j-1];
			else rightV[i][j] = v++;
		}
	}	
}

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
		
		init(n, m);

		for (int i=1; i<=n+m-1; ++i)
			scanf("%d", &leftSum[i]);

		for (int i=1; i<=n+m-1; ++i)
			scanf("%d", &rightSum[i]);

		/* sending flow from left side to right side */
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				/*
				assuming flow between (0 to 99), WHY?
				if we set original 100, then if any cell get flow 0, that means flow
				is happening (0 to 100). but there should be (1 to 100). Flow 0 is wrong.
				
				as there are 100 numbers from (1 to 100) can be placed in each cell, assuming there 
				can be flow at any cell 0, then maximum flow for each cell can be only 99. Because
				there can be 100 numbers from minimum flow 0 to 100th maximum flow 99.
				
				This will give us benefit. if cell get flow (0 to 99), then we can increment this flow
				later due to respect of original flow. by this way, 0 will be 1, 99 will be 100, etc,.
				*/
				add_edge(leftV[i][j], rightV[i][j], 99);
			}
		}

		/* save how many edges are connected with (left side -> right side) && (right side -> left side) */
		for (int i=0; i<=(n+m-1)*2; ++i) {
			cnt[i] = g[i].size();			
		}

		int src = 0, sink = (n+m-1) * 2 + 1;
		for (int i=1; i<=n+m-1; ++i) {
			/*
			sending flow source to left side, and reducing this flow by subtracting
			number of edges form (left side -> right side).
			*/
			add_edge(src, i, leftSum[i]-cnt[i]);			
			/*
			sending flow right side to sink, and reducing this flow by subtracting
			number of edges form (right side -> left side).
			*/
			add_edge((n+m-1)+i, sink, rightSum[i]- cnt[(n+m-1)+i]);

			/*
			
			why we are substracting some flow of (src -> left side) and (right side -> sink)?
			we can think without diagonal. Assume, arrow is designed to each Row and each Column.
			Actually, thinking about row & column, it's easier for me to design the graph.
			Then same idea is applied for diagonal base flow.

			Any cell can be 0, and that's why we need to add 1 to that cell, then we have to
			reserved 1 flow for that cell. Then? we can reserved 1 flow for each cell. For this
			we need to substract reserved flows from each row & column. This is shown below:

			flow of (src -> Row[i]): flow - (number of column connected with Row[i].
			flow of (col[i] -> sink): flow - (number of rows connected with col[i].					
			*/
		}

		maxFlow(sink, src, sink);
		for (int i=1; i<=n+m-1; ++i) {
			for (int j : g[i]) {				
				int to = edgeTab[j].to;
				if (to > i)
					ans[i][to] = edgeTab[j].flow;
			}
		}

		printf("Case %d:\n", cas);
		for (int i=0; i<n; ++i) {
			for (int j=0; j<m; ++j) {
				if (j) putchar(' ');
				printf("%d", ans[leftV[i][j]][rightV[i][j]] + 1);
			}
			puts("");
		}
	}

	return 0;
}
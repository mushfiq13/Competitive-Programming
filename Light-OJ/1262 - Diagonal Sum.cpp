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

int ans[52][52];
int leftSum[105], rightSum[105];    // to take input
pair<int, int> intersect[52][52];   // store the (left arrow, right arrow)
pair<int, int> cell[205][205];

void init(int n, int m) {
    edgeTab.clear();
    for (int i=0; i<=(n+m-1)*2+1; ++i) {
        g[i].clear();
    }

    int v = 1;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            /* store left arrows */
            if (i-1>=0 && j+1<m) intersect[i][j].first = intersect[i-1][j+1].first;
            else intersect[i][j].first = v++;
        }
    }

    for (int i=0; i<n; ++i) {
        for (int j=m-1; j>=0; --j) {
            /* store right arrows */
            if (i-1>=0 && j-1>=0) intersect[i][j].second = intersect[i-1][j-1].second;
            else intersect[i][j].second = v++;

            int a = intersect[i][j].first;
            int b = intersect[i][j].second;
            /* a & b intersected in the (i, j) cell */
            cell[a][b] = {i, j};
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

        for (int i=1; i<=n+m-1; ++i)
            scanf("%d", &leftSum[i]);

        for (int i=1; i<=n+m-1; ++i)
            scanf("%d", &rightSum[i]);

        /*
        
        Idea: ______MAX FLOW______
        link source to left side arrows, and right side arrows to sink.
        if in a cell, left & right sided arrow intersect, then link between them.
        
        Now, if we run MAX FLOW Algo., some cell may be get 0 flow. But we know Each cell
        must have at least 1 flow. So, we assume, flow 1, sent initially to each cell.
        Then, each cell contain 1 flow.

        NB: We can add these flow 1 at first time, or later to the ans[][].

        That's why, the capacity of our max flow graph may be changed. This is showed below.
        
        Part 1:
        We will send flow from source to left arrows following:
        flow of (src -> left arrow): flow - (number of right sided arrows connected with this arrow).
        WHY substracting from original flow?

        We need to send flow to left arrow. let's say the flow is X = 10.
        Flow X need to be distributed to number of cells which left arrow & right arrows intersected.
        Assume total cells are Y = 4.
        
        X must be same as sum of Y cells flow.  We already know minimum flow of each cell can be only 1.
        And we already sent 1 flow from X flows to Y cells.        
        And now, we have to send X-Y flows to Y cells. Because, Y cells already have Y flows.
        
        NB: We can do this in another way. As we already pushed Y flows, So, from source to left arrow,
        we can say, capacity is original capacity. And flow is Y. Whatever I solved this problem by above
        way.

        Part 2:
        what will be capacity of each cell. capacity of (left arrow -> right arrow)?
        We already get the minimum flow to each cell. And we know flow can be (1 to 100) to each cell.
        As we added 1, then we can add maximum 99 flows and minimum 0 flow.
        By this way, ans[][] will be between (1 to 100). i.e. (1+0, 1+1, .., 1+99).
        So, capacity will be 99.
        
        Part 3:
        We will send flow from right arrows to sink following:
        flow of (right arrow -> sink): flow - (number of left sided arrows connected with this arrow).
        WHY substracting from original flow?
        Similar of Part 1....
        */

        init(n, m);

        /* sending flow from left arrow to right arrow */
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {               
                add_edge(intersect[i][j].first, intersect[i][j].second, 99);
            }
        }

        int src = 0, sink = (n+m-1) * 2 + 1;
        for (int i=1; i<=n+m-1; ++i) {
            /*
            sending flow source to left side, and reducing this flow by subtracting
            number of edges form (i -> right sided arrows).
            */
            add_edge(src, i, leftSum[i]-g[i].size());           
            /*
            sending flow right side to sink, and reducing this flow by subtracting
            number of edges form (n+m-1+i -> left sided arrows).
            */
            add_edge((n+m-1)+i, sink, rightSum[i]- g[n+m-1+i].size());
        }

        maxFlow(sink, src, sink);
        
        for (int i=1; i<=n+m-1; ++i) {
            for (int j : g[i]) {                
                int to = edgeTab[j].to;
                if (to > i) {
                    /* flow of (i -> to)  set in the (x, y) position*/
                    int x = cell[i][to].first;
                    int y = cell[i][to].second;
                    ans[x][y] = edgeTab[j].flow;
                }
            }
        }

        printf("Case %d:\n", cas);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (j) putchar(' ');
                printf("%d", ans[i][j] + 1);
            }
            puts("");
        }
    }

    return 0;
}

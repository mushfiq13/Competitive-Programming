#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const int fx[] = {+0, +0, +1, -1};
const int fy[] = {+1, -1, +0, +0};

struct Edge {
    int from, to, cap, f;
};

int mat[N][N];
vector<int> g[N*N*2+10];
vector<Edge> edgeTab;
int pred[N*N*2+10], predEdge[N*N*2+10];

void init(int n, int m) {    
    int cur = 0;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            mat[i][j] = ++cur; // mark each cell to a integer.
        }
    }

    edgeTab.clear();
    for (int i=0; i<=n*m*2 + 5; ++i)
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
    fill(predEdge, predEdge+n+1, -1);
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

char maxFlow(int n, int src, int sink) {
    int mf = 0;
    while (bfs(n, src, sink)) {
        for (int cur = sink; pred[cur] > -1; cur = pred[cur]) {
            int i = predEdge[cur];
            edgeTab[i].f += 1;
            edgeTab[i^1].f -= 1;
        }
        mf += 1;
    }

    return mf == g[0].size();
}

int main() {
    int t, n, m;
    char s[105][105];

    scanf("%d", &t);
    for (int cas=1; cas<=t; ++cas) {
        scanf("%d %d", &n, &m);

        /*
        * compressing 2D matrix to 1D.
        * if a cell contain *, we can not go there, otherwise we can.        
        */

        init(n, m);

        for (int i=0; i<n; ++i)
            scanf(" %s", s[i]);

        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                // each cell capacity is 1
                addEdge(mat[i][j], mat[i][j] + n*m, 1);
            }
        }

        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (s[i][j] == '*')
                    addEdge(0, mat[i][j], 1); // (source -> mat[i][j])

                // this is boundary. so from this cell we can go to sink.
                if (i == 0 || j == 0 || i == n-1 || j == m-1)
                    addEdge(mat[i][j] + n*m, n*m*2+1, 1);
                for (int k=0; k<4; ++k) {
                    int x = i+fx[k];
                    int y = j+fy[k];
                    if (x>=0 && x<n && y<m && y>=0 && s[x][y] == '.') {
                        // if (s[x][y] == '.'), we can go from present cell to (x, y).                        
                        addEdge(mat[i][j] + n*m, mat[x][y], 1);
                    }
                }
            }
        }

        printf("Case %d: ", cas);
        if (maxFlow(n*m*2+5, 0, n*m*2+1)) puts("yes");
        else puts("no");
    }
}
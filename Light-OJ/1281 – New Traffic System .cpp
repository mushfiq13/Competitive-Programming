#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e4 + 10;
const int INF = 1e9;

struct Node {
    int w, v, d;
};

vector<Node> adj[MAX];

int bfs (int n, int d) {
    queue<Node> q;
    vector<vector<int>> dist (n, vector<int> (d+1, INF));

    dist[0][0] = 0;
    q.push ({0, 0, 0});
    while (!q.empty()) {
        int v = q.front().v, cur_w = q.front().w, used_d = q.front().d;
        q.pop();
        for (auto e : adj[v]) {
            int to = e.v, len = e.w, new_d = used_d + e.d;
            if (new_d <= d && dist[to][new_d] > dist[v][used_d]+len) {
                dist[to][new_d] = dist[v][used_d]+len;
                q.push ({dist[to][new_d], to, new_d});
            }
        }
    }
    int ans = INF;
    for (int i=0; i<=d; ++i)
        ans = min(ans, dist[n-1][i]);
    return ans;
}

int main() {
    int test, n, m, k, d;

    scanf("%d", &test);
    for (int Case=1; Case<=test; ++Case) {
        scanf("%d %d %d %d", &n, &m, &k, &d);

        for (int i=0; i<n; ++i)
            adj[i].clear();

        for (int i=0; i<m+k; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            if (i < m) adj[u].push_back ({w, v, 0});
            else adj[u].push_back ({w, v, 1});
        }

        printf ("Case %d: ", Case);
        int ans = bfs (n, d);
        if (ans == INF) puts("Impossible");
        else printf ("%d\n", ans);
    }

    return 0;
}

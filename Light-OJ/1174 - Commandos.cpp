#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 10;
const int N = 100 + 10;

vector<vector<int>> g;

void bfs(int src, vector<int>& dist) {
    queue<int> q;

    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (dist[to] > dist[v] + 1) {
                dist[to] = dist[v] + 1;
                q.push(to);
            }
        }
    }
}

int main() {
    int t, n, r, s, d;

    scanf("%d", &t);
    for (int Case=1; Case<=t; ++Case) {
        scanf("%d %d", &n, &r);

        g = vector<vector<int>> (n+1, vector<int>());
        for (int i=1; i<=r; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        scanf("%d %d", &s, &d);

        vector<int> ds (n+1, INF), dd(n+1, INF);
        bfs(s, ds);
        bfs(d, dd);

        int ans = 0;
        for (int i=0; i<n; ++i)
            ans = max(ans, ds[i]+dd[i]);

        printf("Case %d: %d\n", Case, ans);
    }
}

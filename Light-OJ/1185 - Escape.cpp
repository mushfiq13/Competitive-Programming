#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 100 + 10;
const int INF = 1e9;

vector<int> adj[MAX];

int bfs (const int n, int s) {
    int Count = 0;
    queue<pair<int,int>> q;
    vector<vector<bool>> used (n+1, vector<bool>(2));

    q.push({s, 1});
    while (!q.empty()) {
        int v = q.front().first, c = q.front().second;
        q.pop();
        for (int to : adj[v]) {
            if (!used[to][c^1]) {
                q.push({to, c^1});
                Count += c^1;
                used[to][c^1] = 1;
            }
        }
    }

    return Count;
}

int main() {
    static int test, n, m, u, v;

    scanf("%d", &test);
    for (int Case=1; Case<=test; ++Case) {
        scanf("%d %d", &n, &m);
        for (int i=1; i<=n; ++i)
            adj[i].clear();

        for (int i=1; i<=m; ++i) {
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        printf("Case %d: %d\n", Case, bfs(n, 1));
    }

    return 0;
}

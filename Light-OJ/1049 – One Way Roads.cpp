#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 10;

struct Node {
    int v, w, r;
    Node() {}
    Node(int v, int w, int r)
        : v(v), w(w), r(r) {}
};

vector<Node> adj[MAX];

int dfs (int v, int par) {
    if (v == 1) return 0;
    for (auto e : adj[v]) {
        int to = e.v, cost = e.r == 1 ? e.w : 0;
        if (to != par)
            return cost + dfs (to, v);
    }
}

int main() {
    int test, n;

    scanf("%d", &test);
    for (int Case=1; Case<=test; ++Case) {
        scanf("%d", &n);
        for (int i=1; i<=n; ++i)
            adj[i].clear();

        for (int i=1; i<=n; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            adj[u].push_back ({v, w, 0});
            adj[v].push_back ({u, w, 1}); // reverted edge
        }

        int ans = 1e9;
        for (auto e : adj[1]) {
            int to = e.v, cost = e.r == 1 ? e.w : 0;
            ans = min (ans, cost + dfs (to, 1));
        }
        printf("Case %d: %d\n", Case, ans);
    }

    return 0;
}

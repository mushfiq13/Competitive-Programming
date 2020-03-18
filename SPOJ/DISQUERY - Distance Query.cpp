#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 99;
const int K = ceil(log2(N));

struct data {
    int par, Max, Min;
};

int h[N];
data L[N][K+1];
vector<vector<pair<int, int>>> adj;

void dfs(int v, int p, int w = -1) {
    h[v] = h[p] + 1;
    L[v][0].par = p;
    if (w+1)
        L[v][0].Max = L[v][0].Min = w;
    for (int i=1; i<=K; ++i) {
        L[v][i].par = L[L[v][i-1].par][i-1].par;
        L[v][i].Min = min(L[L[v][i-1].par][i-1].Min, L[v][i-1].Min);
        L[v][i].Max = max(L[L[v][i-1].par][i-1].Max, L[v][i-1].Max);
    }
    for (auto e: adj[v])
        if (p - e.first) dfs(e.first, v, e.second);
}

pair<int, int> LCA(int u, int v) {
    if (u == v) return {0, 0};
    if (h[u] < h[v])
        swap(u, v);

    int Max = INT_MIN, Min = INT_MAX;
    for (int i=K; i>=0; --i) {
        if (h[L[u][i].par] >= h[v]) {
            Max = max(L[u][i].Max, Max);
            Min = min(L[u][i].Min, Min);
            u = L[u][i].par;
        }
    }
    if (u == v) return {Min, Max};
    for (int i=K; i>=0; --i)
        if (L[u][i].par - L[v][i].par) {
            Max = max (max (L[u][i].Max, Max), L[v][i].Max);
            Min = min (min (L[u][i].Min, Min), L[v][i].Min);
            u = L[u][i].par, v = L[v][i].par;
        }

    Max = max (max (L[u][0].Max, Max), L[v][0].Max);
    Min = min (min (L[u][0].Min, Min), L[v][0].Min);
    return {Min, Max};
}

int main() {
    int n, q;

    cin >> n;

    adj = vector<vector<pair<int, int>>> (n+1, vector<pair<int, int>> ());
    for (int i=1; i<n; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    h[1] = -1;
    L[1][0].Min = INT_MAX;
    L[1][0].Max = INT_MIN;
    dfs(1, 1);

    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        auto ans = LCA(a, b);
        cout << ans.first << " " << ans.second << endl;
    }

    return 0;
}

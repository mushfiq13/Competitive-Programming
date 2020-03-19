#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 99;
const int K = ceil(log2(N));

int timer;
int par[N][K+1];
vector<int> h, tin, tout;
vector<long long> dist;
vector<vector<pair<int, int>>> adj;

void dfs(int v, int p, int w) {
    tin[v] = ++timer;
    h[v] = h[p] + 1;
    dist[v] = dist[p] + w;
    par[v][0] = p;

    for (int i=1; i<=K; ++i)
        par[v][i] = par[par[v][i-1]][i-1];

    for (auto e: adj[v])
        if (p - e.first) dfs(e.first, v, e.second);

    tout[v] = ++timer;
}

bool isAnc(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int DIST(int a, int b) {
    int u = a, v = b;
    if (!isAnc(u, v)) {
        for (int i=K; i>=0; --i)
            if (!isAnc(par[u][i], v))
                u = par[u][i];
        u = par[u][0];
    }
    return dist[a] - dist[u] + dist[b] - dist[u];
}

int kth(int a, int b, int k) {
    int u = a, v = b;

    if (!isAnc(u, v)) {
        for (int i=K; i>=0; --i)
            if (!isAnc(par[u][i], v) && h[a]-h[par[u][i]]+1 <= k)
                u = par[u][i];
        k -= h[a] - h[u];
        if (k == 1) return u;
        if (k == 2) return par[u][0];

        --k;
        u = par[u][0];
    }

    k = h[b] - h[u] + 1 - k + 1;
    if (!isAnc(v, u)) {
        for (int i=K; i>=0; --i)
            if (!isAnc(par[v][i], u) && h[b]-h[par[v][i]]+1 <= k)
                v = par[v][i];
    }

    k -= h[b] - h[v];
    if (k == 1) return v;
    return par[v][0];
}

void preProcess(int n) {
    h.assign(n+1, 0);
    tin.assign(n+1, 0);
    tout.assign(n+1, 0);
    dist.assign(n+1, 0);
    h[1] = -1;
    timer = 0;
    dfs(1, 1, 0);
}

int main() {
    int t, n, a, b;
    string s;

    cin >> t;
    while (t--) {
        cin >> n;

        adj = vector<vector<pair<int, int>>> (n+1, vector<pair<int, int>> ());
        for (int i=1; i<n; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        preProcess(n);

        while (true) {
            cin >> s;
            if (s == "DONE") break;
            int ans;
            if (s == "DIST") {
                cin >> a >> b;
                ans = DIST(a, b);
            } else {
                int k;
                cin >> a >> b >> k;
                ans = kth(a, b, k);
            }
            cout << ans << endl;
        }
    }

    return 0;
}

/*
1

11
1 11 1
1 2 2
2 3 1
3 4 3
3 6 1
2 5 4
1 7 5
1 8 2
8 9 3
8 10 2

KTH 4 10 1
KTH 4 10 2
KTH 4 10 3
KTH 4 10 4
KTH 4 10 5

KTH 1 2 2
KTH 2 1 2

KTH 1 2 1

DONE

*/

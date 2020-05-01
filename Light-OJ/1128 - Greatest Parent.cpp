#include <bits/stdc++.h>
using namespace std;

const int N = (int)1e5 + 99;
const int K = 17;

int par[K+1][N], val[N];
vector<vector<int>> g;

void dfs(int v, int p, int w = 1) {
    par[0][v] = p;
    for (int i=1; i<=K; ++i)
        par[i][v] = par[i-1][par[i-1][v]];

    for (auto to : g[v])
        if (to - p) dfs(to, v);
}

int query(int k, int v) {
    for (int i=K; i>=0; --i)
        if (val[par[i][k]] >= v)
            k = par[i][k];
    return k;
}

int main() {
    int t, n, q;

    scanf("%d", &t);
    for (int Case=1; Case<=t; ++Case) {
        scanf("%d %d", &n, &q);

        g = vector<vector<int>> (n+1, vector<int> ());

        for (int i=1; i<n; ++i) {
            int p;
            scanf("%d %d", &p, &val[i]);
            g[i].push_back(p);
            g[p].push_back(i);
        }

        val[0] = 1;
        dfs(0, 0);

        printf("Case %d:\n", Case);
        while (q--) {
            int k, v;
            scanf("%d %d", &k, &v);
            printf("%d\n", query(k, v));
        }
    }
}

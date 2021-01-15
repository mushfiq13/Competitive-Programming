#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
const int N = 10000 + 5;

int timer;
int bridge[20000];
int dp[N], bccName[N];
int tin[N], low[N], used[N];

vector<pii> g[N];

void init(int n, int m) {
    timer = 0;
    for (int i=0; i<=n; ++i) {
        g[i].clear();
        dp[i] = 0, bccName[i] = 0;
        tin[i] = low[i] = 0, used[i] = 0;
    }

    for (int i=0; i<=m; ++i) {
    	bridge[i] = 0;
    }
}

void findBridges(int v, int p) {
    used[v] = 1;
    low[v] = tin[v] = ++timer;

    for (auto e : g[v]) {
        int to = e.first;
        int h = e.second; // position of (v, to)
        if (p == to) continue;
        if (used[to])
            low[v] = min(low[v], tin[to]);
        else {
            findBridges(to, v);
            low[v] = min(low[v], low[to]);
            if (tin[v] < low[to]) bridge[h] = 1;
        }
    }
}

// set each vertex to BCC.
void BCC(int v, int p, int& cur_bcc) {
    used[v] = 1;        
    for (auto e : g[v]) {
        int to = e.first;
        int h = e.second;
        if (p - to && !used[to]) {
        	// set BCC name for each vertex
        	if (bridge[h]) bccName[to] = ++cur_bcc;
        	else bccName[to] = bccName[v];

        	// each BCC forms a vertex in Bridge tree.
        	// if (v, to) is a bridge, then surely it will be in bridge tree.
        	// count (v, to) if it's a bridge, for vertex v.
        	dp[bccName[v]] += bridge[h];
        	// count (to, v) if it's a bridge, for vertex "to".
        	dp[bccName[to]] += bridge[h];
            BCC(to, v, cur_bcc);
        }        
    }
}

int solve(int n) {
    findBridges(0, -1);

    fill(used, used+n+1, 0);

    // after formig a Bridge tree, we have to find out number of leaves.    
    // There can be only one connected edge with a leaf.
    int cur_bcc = 1;
    bccName[0] = cur_bcc;
    BCC(0, 0, cur_bcc);

    // if dp[i] == 1, then i is a leaf.
    return (count(dp, dp+n+1, 1) + 1) / 2;
}

int main() {
    int t, n, m, u, v;

    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas) {
        scanf("%d %d", &n, &m);
        
        init(n, m);
        for (int i=0; i<m; ++i) {
            scanf("%d %d", &u, &v);
            // stores (destination, edge position)
            g[u].push_back({v, i});
            g[v].push_back({u, i});
        }
 
        printf("Case %d: %d\n", cas, solve(n));
    }

    return 0;
}

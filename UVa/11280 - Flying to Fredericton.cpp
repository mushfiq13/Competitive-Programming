#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 99;

vector<pair<int, int>> g[110];
vector<vector<int>> d;

void spfa(int n) {
    queue<pair<int, int>> q;
    vector<vector<bool>> inqueue (n+1, vector<bool> (n+1, false));
    d = vector<vector<int>> (n+1, vector<int> (n+1, INF));

    d[1][0] = 0;
    q.push({1, 0});
    inqueue[1][0] = 1;
    while (!q.empty()) {
        int v = q.front().first;
        int c = q.front().second;
        q.pop();
        //printf("From %d, c: %d:\n", v, c);
        inqueue[v][c] = false;
        for (auto e: g[v]) {
            int to = e.first, len = e.second;
            if (c+1 <= n && d[to][c+1] > d[v][c] + len) {
                d[to][c+1] = d[v][c] + len;
                //printf("-- %d %d: %d\n", to, c+1, d[to][c+1]);
                if (!inqueue[to][c+1]) {
                    inqueue[to][c+1] = true;
                    q.push({to, c+1});
                }
            }
        }
    }
}

int main() {
    int t, n, m, q;
    string s;
    map<string, int> pp;

    cin >> t;
    for (int Case=1; Case<=t; ++Case) {
        cin >> n;
        pp.clear();
        for (int i=1; i<=n; ++i) {
            cin >> s;
            pp[s] = i;
            g[i].clear();
        }

        cin >> m;
        while (m--) {
            string a, b;
            int w;
            cin >> a >> b >> w;
            g[pp[a]].push_back({pp[b], w});
        }

        spfa(n);

        printf("Scenario #%d\n", Case);
        cin >> q;
        while (q--) {
            int cc;
            cin >> cc;
            int ans = INF;
            cc = min(cc+1, n);
            for (int i=0; i<=cc; ++i)
                ans = min(ans, d[n][i]);
            if (ans == INF) puts("No satisfactory flights");
            else printf("Total cost of flight(s) is $%d\n", ans);
        }
        if (Case<t) puts("");
    }
}

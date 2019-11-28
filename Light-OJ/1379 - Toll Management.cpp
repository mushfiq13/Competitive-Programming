#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e4 + 10;
const int INF = 1e9;

vector<pii> g1[MAX], g2[MAX];

void dijkstra (const int &n, const int &s, const vector<pii> *g, vector<int> &d) {
    priority_queue<pii> pq;

    d[s] = 0;
    pq.push ({0, s});
    while (!pq.empty()) {
        int v = pq.top().second, cur_d = -pq.top().first;
        pq.pop();
        if (cur_d > d[v]) continue;
        for (pii e : g[v]) {
            int to = e.second, len = e.first;
            if (d[to] > d[v] + len) {
                d[to] = d[v] + len;
                pq.push ({-d[to], to});
            }
        }
    }
}

int main() {
    static int test, n, m, s, t, p;

    scanf("%d", &test);
    for (int Case=1; Case<=test; ++Case) {
        scanf("%d %d %d %d %d", &n, &m, &s, &t, &p);

        for (int i=1; i<=n; ++i)
            g1[i].clear(), g2[i].clear();

        for (int i=1; i<=m; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            g1[u].push_back ({w, v});
            g2[v].push_back ({w, u});
        }

        vector<int> ds (n+1, INF), dt (n+1, INF);
        dijkstra (n, s, g1, ds);
        dijkstra (n, t, g2, dt);

        int ans = -1;
        for (int v=1; v<=n; ++v) {
            for (pii e : g1[v]) {
                int to = e.second, len = e.first;
                if (ds[v] + len + dt[to] <= p)
                    ans = max (ans, len);
            }
        }

        printf("Case %d: %d\n", Case, ans);
    }

    return 0;
}

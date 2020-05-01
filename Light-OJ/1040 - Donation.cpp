#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 50 + 99;
const int INF = (int)1e9 + 99;

vector<vector<pii>> g;

int Prim(int n, const int tot) {
    int cnt = 0, cost = 0;
    priority_queue<pii> pq;
    vector<int> d(n+1, INF);
    vector<bool> used (n+1, false);

    d[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();

        if (used[v]) continue;

        ++cnt;
        cost += d[v];
        used[v] = true;
        for (pii e : g[v]) {
            if (e.second < d[e.first]) {
                d[e.first] = e.second;
                pq.push({-d[e.first], e.first});
            }
        }
    }

    return cnt < n ? -1 : tot-cost;
}

int main() {
    int t, n;

    scanf("%d", &t);
    for (int Case=1; Case<=t; ++Case) {
        scanf("%d", &n);

        g = vector<vector<pii>> (n+1, vector<pii> ());
        int tot = 0;
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n; ++j) {
                int w;
                cin >> w;
                tot += w;
                if (w) {
                    g[i].push_back({j,w});
                    g[j].push_back({i,w});
                }
            }
        }

        int ans = Prim(n, tot);

        printf("Case %d: %d\n", Case, ans);
    }

    return 0;
}


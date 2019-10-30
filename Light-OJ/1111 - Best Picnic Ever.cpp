#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 1000 + 10;

int city[105], f[MAX];
vector<int> g[MAX];

void bfs (int s, int n) {
    pii node = {0,0};
    queue<int> q;
    vector<bool> used(n+1);

    q.push(s);
    used[s] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (!used[to]) {
                f[to] = f[v] = 0;
                used[to] = 1;
                q.push(to);
            }
        }
    }
}

int main() {
    int test, n, m, k;

    scanf("%d", &test);
    for (int Case=1; Case<=test; ++Case) {
        scanf("%d %d %d", &k, &n, &m);
        for (int i=1; i<=n; ++i) {
            g[i].clear();
            f[i] = 0;
        }

        for (int i=1; i<=k; ++i)
            scanf("%d", &city[i]);

        for (int i=1; i<=m; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            g[v].push_back(u);
        }

        int ans = 0;
        for (int i=1; i<=n; ++i) {
            int j;
            for (j=1; j<=k; ++j)
                f[city[j]] = 1;
            bfs (i, n);
            for (j=1; j<=k; ++j)
                if (f[city[j]]) break;
            if (j > k) ++ans;
        }

        printf("Case %d: %d\n", Case, ans);
    }

    return 0;
}

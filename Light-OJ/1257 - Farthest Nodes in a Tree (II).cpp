#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAX = 30000 + 10;

vector<pii> g[MAX];
vector<int> d(MAX);

pii bfs (int s, int n) {
    pii node = {0,0};
    queue<int> q;
    vector<bool> used(n);

    for (int i=0; i<n; ++i) d[i] = 0;
    q.push(s);
    used[s] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (pii e : g[v]) {
            int to = e.second, len = e.first;
            if (!used[to]) {
                used[to] = 1;
                q.push(to);
                d[to] = d[v] + len;
                if (d[to] > node.first)
                    node = {d[to], to};
            }
        }
    }

    return node;
}

int main() {
    //freopen("out.txt", "w", stdout);
    int test, n;

    scanf("%d", &test);
    for (int Case=1; Case<=test; ++Case) {
        scanf("%d", &n);
        for (int i=0; i<n; ++i)
            g[i].clear();
        for (int i=0; i<n-1; ++i) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            g[u].push_back(make_pair(w, v));
            g[v].push_back(make_pair(w, u));
        }

        pii node = bfs (0, n);

        int a = node.second;
        node = bfs (a, n);
        d[a] = node.first;
        int b = node.second;

        vector<int> d2(d);
        d[b] = bfs (b, n).first;

        printf("Case %d:\n", Case);
        for (int i=0; i<n; ++i)
            printf("%d\n", max(d[i], d2[i]));
    }

    return 0;
}

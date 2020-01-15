#include <bits/stdc++.h>
using namespace std;

const int MAX = 100 + 10;

vector<int> adj[MAX];

vector<int>& topSort(int n) {
    queue<int> q;
    static vector<int> ans;
    vector<int> indegree (n+1);

    for (int i=1; i<=n; ++i)
        for (int to: adj[i])
            ++indegree[to];

    for (int i=1; i<=n; ++i)
        if (!indegree[i])
            q.push(i);

    ans.clear();
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        ans.push_back(v);
        for (int to: adj[v]) {
            --indegree[to];
            if (!indegree[to])
                q.push(to);
        }
    }

    return ans;
}

int main() {
    int n, m;

    while (true) {
        scanf("%d %d", &n, &m);
        if (!n && !m) break;
        for (int i=1; i<=n; ++i)
            adj[i].clear();
        for (int i=1; i<=m; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u].push_back(v);
        }
        vector<int> ans = topSort(n);
        for (int i=0; i<n; ++i) {
            if (i) putchar(' ');
            printf("%d", ans[i]);
        }
        puts("");
    }

    return 0;
}

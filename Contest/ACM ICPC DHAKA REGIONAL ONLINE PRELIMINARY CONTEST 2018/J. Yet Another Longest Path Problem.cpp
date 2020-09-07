#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<pair<int, int>> edge;

void sol(int n) {
    queue<pair<int, char>> q;
    vector<char> used(n+1, 0);

    q.push({1, 1});
    used[1] = 1;
    while (!q.empty()) {
        int v = q.front().first;
        int arrow = q.front().second;
        q.pop();
        for (int to : g[v]) {
            if (used[to]) continue;
            used[to] = 1;
            if (arrow) {
                edge.push_back({v, to});
                q.push({to, 0});
            } else {
                edge.push_back({to, v});
                q.push({to, 1});
            }
        }
    }
}

int main() {
    int t, n, u, v;

    scanf("%d", &t);
    for(int casei = 1; casei <= t; casei++) {
        scanf("%d", &n);

        g = vector<vector<int>> (n+1, vector<int>());
        edge.clear();
        for (int i=1; i<n; ++i) {
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        sol(n);

        printf("Case %d:\n", casei);
        for (auto p : edge)
            printf("%d %d\n", p.first, p.second);
    }
}

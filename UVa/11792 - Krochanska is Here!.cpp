#include <bits/stdc++.h>
using namespace std;

vector<int> important;
vector<vector<int>> g;

int bfs(int src, int n) {
    int sum = 0;
    queue<int> q;
    vector<int> d (n+1, INT_MAX);

    q.push(src);
    d[src] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (important[v] > 1) sum += d[v];
        for (int to : g[v])
            if (d[to] > d[v] + 1)
                d[to] = d[v] + 1, q.push(to);
    }

    return sum;
}

int main() {
    int t, n, s;

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &s);

        g = vector<vector<int>> (n+1, vector<int>());
        important.assign(n+1, 0);
        for (int i=1; i<=s; ++i) {
            vector<int> line;
            while (true) {
                int x;
                scanf("%d", &x);
                if (x == 0) break;
                line.push_back(x);
                ++important[x];
            }
            for (int i=0; i<line.size()-1; ++i) {
                g[line[i]].push_back(line[i+1]);
                g[line[i+1]].push_back(line[i]);
            }
        }

        int Max = INT_MAX, loc;
        for (int i=1; i<=n; ++i) {
            if (important[i] > 1) {
                int sum = bfs(i, n);
                if (Max > sum) Max = sum, loc = i;
            }
        }

        printf("Krochanska is in: %d\n", loc);
    }
}

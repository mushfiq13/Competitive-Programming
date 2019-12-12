#include <bits/stdc++.h>
using namespace std;

const int MAX = 5e4 + 10;
const int INF = 1e9;;

int ar[MAX], d[MAX], p[MAX];
vector<int> adj[MAX];

int bfs (const int s, const int t) {
    queue<int> q;

    q.push(s);
    d[s] = 0;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : adj[v]) {
            if (d[to] > d[v] + 1) {
                q.push(to);
                d[to] = d[v] + 1;
                p[to] = v;
            } else if (d[to] == d[v] + 1)
                p[to] = min(p[to], v);
        }
    }
}

int main(int argc, char ** argv) {
    static int test, n;

    scanf("%d", &test);
    for (int Case=1; Case<=test; ++Case) {
        scanf("%d", &n);

        for (int i=1; i<=n; ++i) {
            scanf("%d", &ar[i]);
            d[ar[i]] = INF;
            p[ar[i]] = -1;
            adj[ar[i]].clear();
        }

        for (int i=2; i<=n; ++i) {
            adj[ar[i-1]].push_back(ar[i]);
            adj[ar[i]].push_back(ar[i-1]);
        }

        bfs(ar[n], ar[1]);

        printf("Case %d:\n", Case);
        for (int v=ar[1]; v!=-1; v=p[v]) {
            if (v != ar[1]) putchar(' ');
            printf("%d", v);
        }
        puts("");
    }

    return 0;
}

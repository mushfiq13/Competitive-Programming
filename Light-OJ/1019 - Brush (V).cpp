#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int v, w, cost;
    Edge(int _v, int _w) {
        v = _v;
        w = _w;
    }
};

bool operator<(Edge A, Edge B)
{
    return A.w > B.w;
}

vector <Edge> adj[101];

int dijkstra(int n)
{
    priority_queue <Edge> pq;
    int taken[n+1]={};
    int dist[n+1];

    for (int i=1; i<=n; ++i)
        dist[i] = 1000000;

    pq.push(Edge(1,0));
    dist[1] = 0;

    while(!pq.empty()) {
        Edge p = pq.top();
        pq.pop();

        if (taken[p.v]) continue;
        taken[p.v] = 1;

        for (int i=0, sz=adj[p.v].size(); i<sz; ++i) {
            Edge u = adj[p.v][i];
            if (dist[u.v] > dist[p.v]+u.w) {
                dist[u.v] = dist[p.v]+u.w;
                pq.push(Edge(u.v,dist[u.v]));
            }
        }
    }

    return dist[n];
}

int main()
{
    int t, n, m, cs=0;

    scanf("%d", &t);

    while(t--) {
        scanf("%d%d", &n, &m);
        for (int i=1; i<=n; ++i)
            adj[i].clear();

        while (m--) {
            int u, v, w;
            scanf("%d%d%d", &u,&v,&w);
            adj[u].push_back(Edge(v,w));
            adj[v].push_back(Edge(u,w));
        }

        int cost = dijkstra(n);
        if (cost < 1000000)
            printf("Case %d: %d\n", ++cs, cost);
        else
            printf("Case %d: Impossible\n", ++cs);
    }
}

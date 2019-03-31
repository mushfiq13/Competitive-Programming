#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
    int w, v, mx;
    Edge(int _w, int _v, int _mx) {
        w = _w;
        v = _v;
        mx = _mx;
    }
};

bool operator<(Edge A, Edge B)
{
    return A.w > B.w;
}

int res[500];
vector <Edge> adj[500];

int prim( int s, int n )
{
    for (int i=0; i<n; ++i)
        res[i] = -1;

    priority_queue <Edge> pq;
    int taken[n] = {};

    pq.push(Edge(0,s,0));

    while(!pq.empty()) {
        Edge u = pq.top();
        pq.pop();

        if(taken[u.v]) continue;
        taken[u.v] = 1;
        res[u.v] = u.mx;

        for (int i=0, sz=adj[u.v].size(); i<sz; ++i) {
            Edge p = adj[u.v][i];
            if (!taken[p.v]) {
                if (u.mx > p.mx)
                    p.mx = u.mx;
                pq.push(p);
            }
        }
    }
}

int main()
{
    int t, n, m, cs=0;

    scanf("%d", &t);

    while(t--) {
        scanf("%d%d", &n, &m);

        for (int i=0; i<n; ++i)
            adj[i].clear();

        while(m--) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            adj[u].push_back(Edge(w,v,w));
            adj[v].push_back(Edge(w,u,w));
        }

        int d;
        scanf("%d", &d);

        prim(d,n);

        printf("Case %d:\n", ++cs);

        for (int i=0; i<n; ++i) {
            if (res[i] > -1)
                printf("%d\n", res[i]);
            else
                puts("Impossible");
        }
    }

    return 0;
}

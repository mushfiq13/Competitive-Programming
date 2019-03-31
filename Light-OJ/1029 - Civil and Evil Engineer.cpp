#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int v, w;
    Edge(int _v, int _w) {
        v = _v;
        w = _w;
    }
};

vector <Edge> adj[101];
int flag;

bool operator<(Edge A, Edge B)
{
    if (!flag)
        return A.w > B.w;
    else
        return A.w < B.w;
}

int prim(int n)
{
    priority_queue <Edge> pq;
    int taken[n+1] = {};
    int cost = 0;

    pq.push(Edge(0,0));

    while(!pq.empty()) {
        Edge p = pq.top();
        pq.pop();

        if (taken[p.v]) continue;
        taken[p.v] = 1;
        cost += p.w;

        for (int i=0, sz=adj[p.v].size(); i<sz; ++i) {
            Edge u = adj[p.v][i];
            if (!taken[u.v])
                pq.push(u);
        }
    }

    return cost;
}

int main()
{
    int t, n, cs=0;

    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        for (int i=0; i<=n; ++i)
            adj[i].clear();

        int x, y, cost;
        while (scanf("%d%d%d", &x, &y, &cost)) {
            if (!x && !y && !cost) break;
            adj[x].push_back(Edge(y,cost));
            adj[y].push_back(Edge(x,cost));
        }

        flag = 0;
        int a = prim(n);

        flag = 1;
        int b = prim(n);

        if ((a+b)%2 == 0)
            printf("Case %d: %d\n", ++cs, (a+b)/2);
        else
            printf("Case %d: %d/2\n", ++cs, a+b);
    }
}

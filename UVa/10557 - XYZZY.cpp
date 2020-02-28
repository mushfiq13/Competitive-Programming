#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e7;

struct Edge {
    int a, b;
};

vector<Edge> edge;
vector<int> d, energy;

void bellmanFord(int n) {
    for (int i=1; i<n; ++i) {
        for (Edge e: edge)
            if (d[e.a]>0 && d[e.a]+energy[e.b] > d[e.b])
                d[e.b] = d[e.a] + energy[e.b];
    }
}

bool solve(int n) {
    d.assign(n+1, -INF);

    d[1] = 100;
    bellmanFord(n);
    if (d[n] > 0) return true;

    for (Edge e: edge)
        if (d[e.a]>0 && d[e.a]+energy[e.b] > d[e.b])
            d[e.b] = INF;

    bellmanFord(n);
    if (d[n] > 0) return true;
    return false;
}

int main() {
    int n, r, v;

    while (cin >> n, n>-1) {
        edge.clear();
        energy.resize(n+1);

        for (int i=1; i<=n; ++i) {
            cin >> energy[i] >> r;
            while (r--) {
                cin >> v;
                edge.push_back({i, v});
            }
        }

        if (solve(n)) puts("winnable");
        else puts("hopeless");
    }

    return 0;
}

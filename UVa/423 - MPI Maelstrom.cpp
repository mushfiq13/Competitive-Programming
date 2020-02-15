#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

const int INF = (int)1e9;
vector<Edge> edge;

int bellmanFord(int n) {
    vector<int> d (n+1, INF);

    d[1] = 0;
    for (int i=1; i<n-1; ++i) {
        for (Edge e: edge) {
            if (e.w < INF && d[e.v] > d[e.u]+e.w)
                d[e.v] = d[e.u] + e.w;
        }
    }

    int ans = 0;
    for (int i=1; i<=n; ++i) {
        if (d[i] < INF)
            ans = max(ans, d[i]);
    }

    return ans;
}

int main() {
    int n;

    cin >> n;
    for (int i=2; i<=n; ++i) {
        for (int j=1; j<i; ++j) {
            string s;
            cin >> s;
            if (s == "x") continue;
            int v = stoi(s);
            edge.push_back({i,j,v});
            edge.push_back({j,i,v});
        }
    }

    cout << bellmanFord(n) << endl;

    return 0;
}

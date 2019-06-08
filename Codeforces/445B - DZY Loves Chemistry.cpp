#include <bits/stdc++.h>
using namespace std;

const int MAX = 51;

int par[MAX], Size[MAX];

int find_set (int v) {
    return par[v] = par[v] == v ? v : find_set (par[v]);
}

int main() {
    int n, m;

    cin >> n >> m;
    for (int i=1; i<=n; ++i)
        par[i] = i, Size[i] = 1;

    while (m--) {
        int x, y;
        cin >> x >> y;
        int u = find_set (x);
        int v = find_set (y);
        if (u != v) {
            if (Size[u] < Size[v])
                swap(u, v);
            par[v] = u;
            Size[u] += Size[v];
        }
    }

    long long danger = 1;
    for (int i=1; i<=n; ++i) {
        int p = find_set (i);
        while (Size[p]-- > 1)
            danger *= 2;
    }

    cout << danger << endl;

    return 0;
}

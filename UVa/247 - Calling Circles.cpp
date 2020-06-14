#include <bits/stdc++.h>
using namespace std;

map<string, int> si;
map<int, string> is;

vector<int> order, component;
vector<bool> used;
vector<vector<int>> g, gr;

void dfs(int v, int f) {
    used[v] = true;

    vector<int> grap;
    grap = (f == 1) ? g[v] : gr[v];
    if (f == 2) component.push_back(v);

    for (int to : grap)
        if (!used[to]) dfs(to, f);
    order.push_back(v);
}

void SCC(int n) {
    order.clear();
    used.assign(n+1, false);
    for (int i=1; i<=n; ++i)
        if (!used[i])
            dfs(i, 1);

    used.assign(n+1, false);
    for (int i=n-1; i>=0; --i) {
        if (!used[order[i]]) {
            component.clear();
            dfs(order[i], 2);
            cout << is[component[0]];
            for (int i=1; i<component.size(); ++i)
                cout << ", " << is[component[i]];
            puts("");
        }
    }
}

int main() {
    int n, m;

    for (int Case=1; scanf("%d %d", &n, &m); ++Case) {
        if (!n && !m) return 0;

        si.clear();
        is.clear();
        g = vector<vector<int>> (n+1);
        gr = vector<vector<int>> (n+1);

        int i = 1;
        while (m--) {
            string a, b;
            cin >> a >> b;
            if (!si[a]) si[a] = i++;
            if (!si[b]) si[b] = i++;
            g[si[a]].push_back(si[b]);
            gr[si[b]].push_back(si[a]);
            is[si[a]] = a;
            is[si[b]] = b;
        }

        if (Case > 1) puts("");
        printf("Calling circles for data set %d:\n", Case);
        SCC(n);
    }
}

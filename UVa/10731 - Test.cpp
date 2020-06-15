#include <bits/stdc++.h>
using namespace std;

vector<int> order, comp;
vector<bool> used, pp;
vector<int> ans[26];
vector<int> g[26], gr[26];

void dfs(int v, int f) {
    used[v] = 1;

    vector<int> grap;
    grap = (f == 1) ? g[v] : gr[v];
    if (f == 2) comp.push_back(v);

    for (int to : grap)
        if (!used[to]) dfs(to, f);
    order.push_back(v);
}

void SCC() {
    order.clear();
    used.assign(26, false);
    for (int i=0; i<26; ++i)
        if (pp[i] && !used[i]) dfs(i, 1);

    used.assign(26, false);
    for (int i=order.size()-1; i>=0; --i) {
        if (!used[order[i]]) {
            comp.clear();
            dfs(order[i], 2);
            sort(comp.begin(), comp.end());
            ans[comp[0]] = comp;
        }
    }
}

int main() {
    int n;

    for (int cs=1; cin >> n, n; ++cs) {
        for (int i=0; i<26; ++i)
            g[i].clear(), gr[i].clear(), ans[i].clear();

        pp.assign(26, false);
        for (int i=1; i<=n; ++i) {
            char a[5], v;
            cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> v;
            for (int i=0; i<5; ++i) {
                pp[a[i]-'A'] = 1;
                g[v-'A'].push_back(a[i]-'A');
                gr[a[i]-'A'].push_back(v-'A');
            }
            pp[v-'A'] = 1;
        }

        SCC();

        if (cs > 1) puts("");
        for (int i=0; i<26; ++i) {
            if (ans[i].size() == 0) continue;
            for (int j=0; j<ans[i].size(); ++j) {
                if (j) putchar(' ');
                char c = ans[i][j] + 'A';
                cout << c;
            }
            puts("");
        }
    }
}

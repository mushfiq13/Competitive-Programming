#include <bits/stdc++.h>
using namespace std;

bool let[27];
bool vis[27];
string ans;
vector<int> adj[27];

void dfs(int v) {
    vis[v] = 1;
    for (int to: adj[v])
        if (!vis[to])
            dfs(to);
    ans += v + 'A';
}

void topSort() {
    for (int i=0; i<27; ++i) {
        if (let[i] && !vis[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
}

int main() {
    int n = 0;
    string s[10000];

    while (cin >> s[n], s[n] != "#") {
        for (char c: s[n]) let[c-'A'] = 1;
        ++n;
    }

    if (n == 1) {
        cout << s[0] << endl;
        return 0;
    }

    for (int i=1; i<n; ++i) {
        int r1 = s[i-1].length();
        int r2 = s[i].length();
        for (int j=0; j<r1 && j<r2; ++j) {
            int u = s[i-1][j] - 'A';
            int v = s[i][j] - 'A';
            if (u != v) {
                adj[u].push_back(v);
                break;
            }
        }
    }

    topSort();
    cout << ans << endl;

    return 0;
}

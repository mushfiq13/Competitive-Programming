#include <bits/stdc++.h>
using namespace std;

const int MAX = 101;

int par[MAX];
vector<int> lang[MAX];

int find_set (int v) {
    return par[v] = par[v] == v ? v : find_set (par[v]);
}

int main() {
    int n, m;

    scanf("%d %d", &n, &m);

    for (int i=1; i<=n; ++i) {
        int k;
        scanf("%d", &k);
        if (k) par[i] = i;
        else par[i] = -1;
        while (k--) {
            int l;
            scanf("%d", &l);
            lang[l].push_back(i);
        }
    }

    for (int i=1; i<=m; ++i) {
        for (int j=1, sz=lang[i].size(); j<sz; ++j) {
            int u = find_set(lang[i][j-1]);
            int v = find_set(lang[i][j]);
            if (u != v)
                par[v] = u;
        }
    }

    int ans = 0;
    bool flag = false;
    for (int i=1; i<=n; ++i) {
        if (par[i] == -1)
            ++ans ;
        else if (find_set(i) == i)
            ++ans, flag = true ;
    }

    printf("%d\n", flag ? ans-1 : ans);

    return 0;
}

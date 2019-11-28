#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<int> ans[71];
vector<pii> team, table;

bool cmp (pii a, pii b) {
    return a.first > b.first;
}

bool solve (int m, int n) {
    sort (team.begin(), team.end(), cmp);
    sort (table.begin(), table.end(), cmp);

    int sz = table.size();
    for (pii tm : team) {
        for (int i=0; i<sz; ++i) {
            if (tm.first == 0) break;
            if (table[i].first) {
                --table[i].first, --tm.first;
                ans[tm.second].push_back (table[i].second);
            }
        }
        if (tm.first) return 0;
    }

    return 1;
}

int main () {
    static int m, n, x;

    while (scanf("%d %d", &m, &n), m, n) {
        team.clear();
        table.clear();

        for (int i=1; i<=m; ++i) {
            scanf("%d", &x);
            team.push_back ({x, i});
            ans[i].clear();
        }
        for (int i=1; i<=n; ++i) {
            scanf("%d", &x);
            table.push_back ({x, i});
        }

        if (solve(m, n) == 0) puts("0");
        else {
            puts("1");
            for (int i=1; i<=m; ++i) {
                bool space = false;
                for (int seat : ans[i]) {
                    if (space) putchar(' ');
                    space = true;
                    printf("%d", seat);
                }
                puts("");
            }
        }
    }

    return 0;
}

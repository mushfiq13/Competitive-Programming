#include <bits/stdc++.h>
using namespace std;

const int Max = 2e5 + 5;

int par[Max], ans[Max];
int query[Max][3];

int find_set (int v)
{
    if (par[v] == v) return v;
    return par[v] = find_set (par[v]);
}

int main()
{
    int n, q, c;

    scanf("%d %d", &n, &q);

    for (int i=1; i<=n+1; ++i)
        par[i] = i;

    for (int i=1; i<=q; ++i)
        scanf("%d %d %d", &query[i][0], &query[i][1], &query[i][2]);

    for (int i=q; i>=1; --i) {
        int l = query[i][0];
        int r = query[i][1];
        int c = query[i][2];
        for (int j = find_set(l); j <= r; j = find_set (j+1)) {
            ans[j] = c;
            par[j] = j+1;
        }
    }

    for (int i=1; i<=n; ++i)
        printf("%d\n", ans[i]);

    return 0;
}

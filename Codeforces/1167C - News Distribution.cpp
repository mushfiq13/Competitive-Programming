#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;

int par[MAXN], Size[MAXN];

int find_set (int v)
{
    return par[v] = par[v] == v ? v : find_set(par[v]);
}

int main()
{
    int n, m, k;

    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; ++i) {
        par[i] = i;
        Size[i] = 1;
    }
    while (m--) {
        scanf("%d", &k);
        int p;
        if (k) scanf("%d", &p);
        for (int i=1; i<k; ++i) {
            int c;
            scanf("%d", &c);
            int u = find_set(par[p]);
            int v = find_set(par[c]);
            if (u != v) {
                if (Size[u] < Size[v])
                    swap(u, v);
                par[v] = u;
                Size[u] += Size[v];
                p = u;
            }
        }
    }
    for (int i=1; i<=n; ++i) {
        if (i > 1) putchar(' ');
        printf("%d", Size[find_set(i)]);
    }
    puts("");

    return 0;
}

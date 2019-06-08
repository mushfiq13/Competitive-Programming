#include <bits/stdc++.h>
using namespace  std;

const int MAX = 3e5 + 10;

int par[MAX], ans[MAX];

int find_set (int v) {
    return par[v] = par[v] == v ? v : find_set(par[v]);
}

int main() {
    int n, m, l, r, x;

    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; ++i)
        par[i] = i;
    par[n+1] = n+1;

    while (m--) {
        scanf("%d %d %d", &l, &r, &x);
        for (int i=find_set(l); i<=r; i = find_set(i+1)) {
            if (i != x)
                par[i] = i+1, ans[i] = x;
        }
    }

    for (int i=1; i<=n; ++i) {
        if (i > 1) putchar(' ');
        printf("%d", ans[i]);
    }
    puts("");

    return 0;
}

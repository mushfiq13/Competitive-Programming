#include <bits/stdc++.h>
using namespace std;

const int Max = 2e5 + 5;

int a[Max], par[Max], query[Max][2];

int find_set (int v)
{
    return par[v] = par[v] == v ? v : find_set (par[v]);
}

int main()
{
    int t, n, cs=0;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        for (int i=1; i<=n+n+1; ++i)
            par[i] = i;
        for (int i=1; i<=n; ++i)
            scanf("%d %d", &query[i][0], &query[i][1]);
        int ans = 0;
        for (int i=n; i>=1; --i) {
            int l = query[i][0];
            int r = query[i][1];
            bool flag = true;
            for (int j = find_set(l); j <= r; j = find_set(j+1)) {
                par[j] = j+1;
                if (flag)
                    flag = false, ++ans ;
            }
        }
        printf("Case %d: %d\n", ++cs, ans);
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 7;

int main() {
    int t, n, q;

    scanf("%d", &t);
    for (int Case=1; Case<=t; ++Case) {
        scanf("%d %d", &n, &q);

        int a[n+1];
        for (int i=1; i<=n; ++i)
            scanf("%d", &a[i]);

        vector<int> L(n+1, -INF), dp (n+1, 1);

        L[0] = INF;
        for (int i=n; i>0; --i) {
            int j, l=0, r=n;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (a[i] >= L[mid])
                    j=mid, r = mid-1;
                else l = mid+1;
            }
            if (a[i] < L[j-1] && a[i] >= L[j])
                L[j] = a[i];
            dp[i] = j;
        }

        printf("Case %d:\n", Case);
        while (q--) {
            int len;
            scanf("%d", &len);
            vector<int> ans;
            int last = -INF;
            for (int i=1; len && i<=n; ++i) {
                if (dp[i] >= len && a[i] > last)
                    ans.push_back(a[i]), --len, last=a[i];
            }
            if (len) puts("Impossible");
            else {
                for (int i=0; i<ans.size(); ++i) {
                    if (i) putchar(' ');
                    printf("%d", ans[i]);
                }
                puts("");
            }
        }
    }
}

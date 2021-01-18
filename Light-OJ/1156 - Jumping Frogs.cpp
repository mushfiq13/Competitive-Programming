#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, d;
    int ar[105], s[105];

    scanf("%d", &t);
    for (int cas=1; cas<=t; ++cas) {
        scanf("%d %d", &n, &d);

        for (int i=1; i<=n; ++i) {                        
            char c;
            scanf(" %c-%d", &c, &ar[i]);
            s[i] = (c != 'B');
        }

        ar[0] = 0; ar[n+1] = d;
        s[0] = s[n+1] = 0;

        int ans = 0;
        for (int i=1; i<=n; ++i) {
            if (!s[i] && !s[i+1])
                ans = max(ans, ar[i+1] - ar[i]);
            if (!s[i] && !s[i-1])
                ans = max(ans, ar[i] - ar[i -1]);
            if (s[i])
                ans = max(ans, ar[i+1] - ar[i-1]);
        }

        printf("Case %d: %d\n", cas, ans);
    }

    return 0;
}

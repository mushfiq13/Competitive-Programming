#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    int a[155];

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i=1; i<=n; ++i)
            scanf("%d", &a[i]);

        int mx = 0, b;
        for (int i=1; i<=n; ++i) {
            scanf("%d", &b);
            mx = max (mx, a[i]*20 - b*10);
        }

        printf("%d\n", mx);
    }

    return 0;
}

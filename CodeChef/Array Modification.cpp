#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e4 + 10;

int a[MAX], ans[MAX];

int main() {
    int t, n;
    ll k;

    scanf("%d", &t);
    while (t--) {
        scanf("%d %lld", &n, &k);
        for (int i=0; i<n; ++i)
            scanf("%d", &a[i]);

        int x, y, z, m;
        for (int i=0; i < n; ++i) {
            if (i < k) {
                if (i == n-i-1) ans[i] = 0;
                else if (i < n-i-1) {
                    x = a[i], y = a[n-i-1], z = a[i]^a[n-i-1];
                    m = (k-i)/n; if ((k-i) % n) ++m;
                    if (m%3 == 1) ans[i] = z;
                    else if (m%3 == 2) ans[i] = y;
                    else ans[i] = x;
                }
                else {
                    x = a[n-i-1], y = a[i], z = a[i]^a[n-i-1];
                    m = (k-i)/n; if ((k-i) % n) ++m;
                    if (m%3 == 1) ans[i] = x;
                    else if (m%3 == 2) ans[i] = z;
                    else ans[i] = y;
                }
            }
            else ans[i] = a[i];
        }

        for (int i=0; i<n; ++i) {
            if (i) putchar(' ');
            printf("%d", ans[i]);
        }
        puts("");
    }

    return 0;
}

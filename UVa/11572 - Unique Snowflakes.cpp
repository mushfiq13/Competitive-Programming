#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, x;
    map<int, int> f;

    scanf("%d", &t);
    while (t--) {
        f.clear();
        int ans = 0, c = 0, id = 0;

        scanf("%d", &n);
        for (int i=1; i<=n; ++i) {
            scanf("%d", &x);
            if (f[x]) {
                id = max(id, f[x]);
                c = i-id-1;
            }
            ++c;
            f[x] = i;
            ans = max(ans, c);
        }

        printf("%d\n", ans);
    }

    return 0;
}

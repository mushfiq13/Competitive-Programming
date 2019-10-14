#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 10;

int main() {
    int t, n, x;

    cin >> t;
    while (t--) {
        scanf("%d", &n);
        int ans = 0;
        map<int, int> f;
        while (n--) {
            scanf("%d", &x);
            ans = max (ans, f[x]);
            for (int i=1; i*i <= x; ++i) {
                if (x%i == 0) {
                    ++f[i];
                    if (i*i != x) ++f[x/i];
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

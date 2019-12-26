#include <bits/stdc++.h>
using namespace std;

int main() {
    static int test, n, d;

    scanf("%d", &test);
    for (int Case=1; Case<=test; ++Case) {
        scanf("%d %d", &n, &d);
        int cnt = 0, m = d;
        while (++cnt) {
            if (m%n == 0) break;
            m = (m*10 + d) % n;
        }
        printf("Case %d: %d\n", Case, cnt);
    }

    return 0;
}

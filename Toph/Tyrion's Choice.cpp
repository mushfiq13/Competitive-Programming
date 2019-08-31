#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5 + 10;

int a[MAX], b[MAX], c[MAX];

int main() {
    int x, y, z;

    scanf("%d %d %d", &x, &y, &z);
    for (int i=1; i<=x; ++i)
        scanf("%d", &a[i]);

    for (int i=1; i<=y; ++i)
        scanf("%d", &b[i]);

    for (int i=1; i<=z; ++i)
        scanf("%d", &c[i]);

    sort (b+1, b+y+1);
    sort (c+1, c+z+1);

    int ans = 0;
    for (int i=1; i<=x; ++i) {
        int cnt = lower_bound(b+1, b+y+1, a[i]) - b-1;
        cnt += c+z+1 - upper_bound(c+1, c+z+1, a[i]);
        ans = max (ans, cnt+1);
    }

    printf("%d\n", ans);

    return 0;
}

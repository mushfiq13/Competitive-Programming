#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int cum[MAX];

int main() {
    int n, q, l, r;

    scanf("%d", &n);
    for (int i=1; i<=n; ++i) {
        int x;
        scanf("%d", &x);
        cum[i] = cum[i-1] + x;
    }

    scanf("%d", &q);
    while (q--) {
        scanf("%d %d", &l, &r);
        printf("%d\n", (cum[r]-cum[l-1]) / 10);
    }

    return 0;
}

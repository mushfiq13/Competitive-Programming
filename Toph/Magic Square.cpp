#include <stdio.h>

int main() {
    int t, n;

    scanf("%d", &t);
    for (int cs = 1; cs <= t; ++cs) {
        scanf("%d", &n);
        printf("Case %d: %d\n", cs, n * (1+n*n) >> 1);
    }

    return 0;
}

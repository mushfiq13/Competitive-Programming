#include <bits/stdc++.h>
using namespace std;

int main() {
    int test, n, c;

    scanf("%d", &test);
    for (int Case=1; Case<=test; ++Case) {
        scanf("%d %d", &n, &c);
        int ans = 0;
        if (n) {
            ans = (c/n + bool(c%n)) / 2;
        }
        printf("Case %d: %d\n", Case, ans);
    }

    return 0;
}

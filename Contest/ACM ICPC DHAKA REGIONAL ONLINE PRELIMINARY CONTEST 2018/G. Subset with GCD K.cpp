#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, k;

    scanf("%d", &n);

    int a[n];
    for (int& x : a) scanf("%d", &x);

    scanf("%d", &q);
    while (q--) {
        scanf("%d", &k);
        int g = 0;
        for (int x : a) {
            if (x % k == 0)
                g = (!g) ? x : __gcd(g, x);
        }
        if (g - k) puts("N");
        else puts("Y");
    }
}

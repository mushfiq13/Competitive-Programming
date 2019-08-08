#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    ll n, k;

    scanf("%d", &t);
    while (t--) {
        scanf("%lld %lld", &n, &k);
        if (n / k % k == 0)
            puts("NO");
        else
            puts("YES");
    }

    return 0;
}

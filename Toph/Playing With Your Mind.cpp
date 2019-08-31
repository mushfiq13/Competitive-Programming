#include <stdio.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    ll n;

    scanf("%d", &t);
    for (int cs = 1; cs <= t; ++cs) {
        scanf("%lld", &n);

        while (n) {
            if (n&1) break;
            n = n >> 1;
        }

        printf("Case %d: %lld\n", cs, n);
    }

    return 0;
}

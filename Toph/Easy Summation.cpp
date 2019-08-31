#include <stdio.h>
//using namespace std;

typedef long long ll;

int main() {
    int t;
    ll n;

    scanf("%d", &t);
    for (int cs = 1; cs <= t; ++cs) {
        scanf("%lld", &n);
        n = n*2 - 1;
        printf("Case %d: %lld\n", cs, (n/2+n%2) * (1+n) / 2);
    }

    return 0;
}

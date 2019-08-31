#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, y;
    while (~scanf("%lld %lld", &x, &y)) {
        if (x > y) swap(x, y);
        printf("Sum of %lld to %lld is -> %lld;\n", x, y, (y-x+1)*(x+y) / 2);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long a, b, d;
    cin >> a >> b;

    while (a && b) {
        d = a / b;
        if (d%2)
            d--;
        if (d > 0)
            a -= d*b;

        if (a > 0)
            d = b / a;
        if (d%2) d--;
        if (d > 0)
            b -= d*a;

        if (a < 2*b && b < 2*a)
            break;
    }

    printf("%lld %lld\n", a, b);

    return 0;
}

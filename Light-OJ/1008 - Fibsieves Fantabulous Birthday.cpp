#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int t, r, c, cs=0;
    long long n, m, sq;

    scanf("%d", &t);

    while(t--) {
        scanf("%lld", &n);

        sq = ceil(sqrt(n));
        m = sq*sq;

        if (m-n+1 <= sq)
            c = m-n+1;
        else
            c = sq;

        if (m-n < sq)
            r = sq;
        else
            r = sq-(m-sq+1-n);

        if (sq%2)
            printf("Case %d: %d %d\n", ++cs, c, r);
        else
            printf("Case %d: %d %d\n", ++cs, r, c);
    }

    return 0;
}

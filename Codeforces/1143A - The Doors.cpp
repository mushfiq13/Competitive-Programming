#include <cstdio>
using namespace std;

int main()
{
    int n, x, zero, one;

    scanf("%d", &n);

    for (int i=1; i<=n; ++i) {
            scanf("%d", &x);
            if (x)
                    one = i;
            else
                    zero = i;
    }

    if (one > zero)
            printf("%d\n", zero);
    else
            printf("%d\n", one);

    return 0;
}

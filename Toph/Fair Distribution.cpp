#include <cstdio>
using namespace std;

int main()
{
    int x, y;

    scanf ("%d %d", &x, &y);

    if (y%x)
        y = x - (y - y/x*x);

    printf("%d\n", y);

    return 0;
}

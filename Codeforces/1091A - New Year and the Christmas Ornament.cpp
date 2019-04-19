#include <cstdio>
using namespace std;

int main()
{
    int y, b, r;

    scanf("%d %d %d", &y, &b, &r);

    while (1) {
            if (y+1 <= b && y+2 <= r)
                    break;
            --y;
    }

    printf("%d\n", y*3+3);

    return 0;
}

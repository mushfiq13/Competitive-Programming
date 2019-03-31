#include <cstdio>
using namespace std;

int main ()
{
    int t, n, sub;

    scanf("%d", &t);

    while (t--){
            scanf("%d", &n);

            if (n > 10){
                sub = n-10;
                printf ("%d %d\n", sub, n-sub);
            }
            else
                printf ("0 %d\n", n);
    }

    return 0;
}

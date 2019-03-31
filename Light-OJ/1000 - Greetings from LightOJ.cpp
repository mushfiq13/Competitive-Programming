#include <cstdio>
using namespace std;

int main ()
{
    int t, a, b, cs=0;

    scanf("%d", &t);

    while (t--){
            scanf("%d %d", &a, &b);
            printf ("Case %d: %d\n", ++cs, a+b);
    }

    return 0;
}

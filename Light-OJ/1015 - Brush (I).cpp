#include <cstdio>
using namespace std;

int main ()
{
    int t, n, dust, sum, cs=0;

    scanf("%d", &t);

    while (t--){
            scanf("%d", &n);

            sum = 0;
            while (n--){
                    scanf("%d", &dust);
                    if (dust > 0)
                        sum += dust;
            }
            printf ("Case %d: %d\n", ++cs, sum);
    }

    return 0;
}

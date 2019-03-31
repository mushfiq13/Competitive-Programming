#include <cstdio>
#include <cmath>
using namespace std;

#define PI 2*acos(0.0)

int main ()
{
    int t, cs=0;
    double r, ans;

    scanf("%d", &t);

    while (t--){
            scanf("%lf", &r);
            ans = (r+r)*(r+r) - (PI * r * r);
            printf ("Case %d: %.2lf\n", ++cs, ans);
    }

    return 0;
}

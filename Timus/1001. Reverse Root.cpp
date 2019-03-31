#include <cstdio>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    long long n;
    vector <long long> ar;

    while (scanf("%lld",&n) != EOF)
        ar.push_back(n);

    for (n=ar.size()-1; n>=0; --n)
        printf("%.4lf\n", sqrt(ar[n]));

    return 0;
}

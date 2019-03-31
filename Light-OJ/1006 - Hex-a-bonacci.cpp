#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;

#define MOD 10000007

LL dp[10001];
int a, b, c, d, e, f;

LL fn (int n)
{
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = ( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6)) % MOD;
    return dp[n];
}

int main()
{
    freopen("out.txt","w", stdout);
    int cs = 0, tc;
    LL n;

    scanf("%d", &tc);

    while(tc-- ) {
        for (int i = 1; i <= 10000; i++)
            dp[i] = -1;

        cin >> a >> b >> c >> d >> e >> f >> n;
        printf("Case %d: %lld\n", ++cs, fn(n) % MOD);
    }
    return 0;
}

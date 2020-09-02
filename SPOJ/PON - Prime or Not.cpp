#include <bits/stdc++.h>
using namespace std;

long long mulMod(long long a, long long b, long long mod) {
    long long res = 0;
    while (b) {
        if(b & 1)
            res = (res + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return res;
}

long long powerMod(long long a, long long b, long long mod) {
    long long res = 1;
    while (b) {
        if (b & 1)
            res = mulMod(res, a, mod);  // res = res * a % mod
        a = mulMod(a, a, mod);          // a = a * a % mod
        b >>= 1;
    }
    return res;
}

bool checkComposite(long long n, long long a, long long d, int r) {
    long long x = powerMod(a, d, n);
    if (x == 1 || x == n-1) return false;

    for (int i=1; i<r; ++i) {
        x = mulMod(x, x, n);
        if (x == n-1) return false;
    }
    return true;
}

bool millerRabin(long long n) {
    if (n < 2)    return false;

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 83, 89, 97}) {
        if (n == a)      return true;
        if (n % a == 0)  return false;
    }

    int r = 0;
    long long d = n-1;
    while ((d & 1) == 0) {
        d >>= 1;
        ++r;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (checkComposite(n, a, d, r))
            return false;
    }

    return true;
}

int main() {
    int t;
    long long n;

    scanf("%d", &t);
    for (int i=1; i<=t; ++i) {
        scanf("%lld", &n);
        //cout << i << ":  ";
        if (millerRabin(n)) puts("YES");
        else                puts("NO");
    }

    return 0;
}

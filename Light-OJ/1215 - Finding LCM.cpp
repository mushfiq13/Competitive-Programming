#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;

typedef long long ll;

int r;
ll pm[78500];
bool mark[MAX>>1];

void siv ()
{
    pm[r++] = 2;
    for (ll i=3; i<MAX; i+=2) {
        if (mark[i>>1] == true) continue;
        pm[r++] = i;
        if (i*i <= MAX)
            for (int j=i*i; j < MAX; j += i+i)
                mark[j>>1] = true;
    }
}

int Count (ll n, ll p) {
    int cnt = 0;
    while (n % p == 0)
        n /= p, ++cnt ;
    return cnt;
}

int main()
{
    siv();
    int t;
    ll a, b, L;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; ++cs) {
        scanf("%lld %lld %lld", &a, &b, &L);

        if (L % (a / __gcd(a,b) * b)) {
            printf("Case %d: impossible\n", cs);
            continue;
        }

        ll c = 1;
        for (ll i=0; pm[i]*pm[i] <= L; ++i) {
            if (L % pm[i] == 0) {
                ll v = 1;
                int cnt = 0;
                while (L % pm[i] == 0)
                    L /= pm[i], v *= pm[i], ++cnt ;
                if (cnt != Count (a, pm[i]) && cnt != Count (b, pm[i]))
                    c *= v;
            }
        }
        if (L>1 && a%L && b%L) {
            c *= L;
        }
        printf("Case %d: %lld\n", cs, c);
    }

    return 0;
}

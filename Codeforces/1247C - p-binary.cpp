#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int number_of_one_bit (ll n, int need) {
    if (n < 0) return 0;

    int cnt = 0, cnt2 = 0;
    ll p = 1;
    while (n) {
        if (n & 1)
            ++cnt, cnt2 += p >> 1;
        n >>= 1;
        p <<= 1;
    }

    if (cnt<need && cnt2>=need)
        return need;
    return cnt;
}

int main() {
    ll n, p;

    cin >> n >> p;

    if (n > p)
    for (ll i=1; i <= 50; ++i)
        if (number_of_one_bit(n-(i*p), i) == i) {
            cout << i << endl;
            return 0;
        }

    puts("-1");
    return 0;
}

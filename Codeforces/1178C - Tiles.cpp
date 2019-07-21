#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;

int main ()
{
    ll w, h, ans = 1;

    cin >> w >> h;
    for (int i=1; i <= w+h; ++i)
        ans = (ans * 2) % MOD;

    cout << ans << endl;

    return 0;
}

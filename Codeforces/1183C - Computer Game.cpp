#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int q;
    ll k, n, a, b;

    cin >> q;
    while (q--) {
        cin >> k >> n >> a >> b;
        if (n*b >= k)
            puts("-1");
        else {
            ll l = 0, h = n, mx;
            while (l <= h) {
                ll mid = (l + h) / 2;
                if (mid*a + (n-mid)*b < k) {
                    mx = mid;
                    l = mid + 1;
                } else h = mid - 1;
            }
            cout << mx << endl;
        }
    }

    return 0;
}

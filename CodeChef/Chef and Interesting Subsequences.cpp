#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 50 + 10;

int n, k;
int a[MAX];

int main() {
    int t;

    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i=0; i<n; ++i)
            cin >> a[i];

        sort (a, a+n);

        int cnt1 = 0, cnt2 = 0;
        for (int i=0; i<n; ++i) {
            if (a[i] == a[k-1])
                ++cnt1;
            if (i<k)
                cnt2 = cnt1;
        }

        ll m = 1;
        int f[MAX] = {};
        for (ll i=cnt1-cnt2+1; i<=cnt1; ++i) {
            m *= i;
            for (int j=2; j <= cnt2; ++j) {
                if (f[j] == 0 && m%j == 0) {
                    m /= j;
                    f[j] = 1;
                    break;
                }
            }
        }

        cout << m << endl;
    }

    return 0;
}

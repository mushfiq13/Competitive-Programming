#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n;
        ll sum = 0;
        for (int i=0; i<n; ++i) {
            cin >> x;
            sum += x;
        }
        cout << sum/n + (bool) (sum%n) << endl;
    }
    return 0;
}

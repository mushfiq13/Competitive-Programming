#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int a[MAX];

int main() {
    int t, n;

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=0; i<n; ++i) {
            cin >> a[i];
        }

        sort (a, a+n);

        int m = min (a[n-1], a[n-2]) - 1;
        cout << min (m, n-2) << endl;
    }

    return 0;
}

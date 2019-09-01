#include <bits/stdc++.h>
using namespace std;

const int MAX = 150000 + 10;

int a[MAX];

int main() {
    int t, n;

    cin >> t;
    while (t--) {
        cin >> n;
        for (int i=1; i<=n; ++i)
            cin >> a[i];

        int smaller = 1e6, day = 0;
        for (int i=n; i; --i) {
            if (a[i] > smaller)
                ++day;
            smaller = min (a[i], smaller);
        }

        cout << day << endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[105];

int main() {
    int q, n;

    cin >> q;
    while (q--) {
        cin >> n;
        for (int i=0; i<n; ++i) {
            cin >> a[i];
            if (a[i] > 2048) a[i] = -1;
        }
        bool yes = false;
        for (int i=0; i<n && !yes; ++i) {
            if (a[i] == 2048) yes = true;
            if (a[i] != -1) {
                sort (a, a+n);
                for (int j=i+1; j<n && !yes; ++j) {
                    if (a[j] == 2048) yes = true;
                    if (a[i] == a[j]) {
                        a[j] += a[i];
                        a[i] = -1;
                        if (a[j] == 2048) yes = true;
                        break;
                    }
                }
            }
        }
        if (yes) puts ("YES");
        else puts ("NO");
    }

    return 0;
}

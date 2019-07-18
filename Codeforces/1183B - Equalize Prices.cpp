#include <bits/stdc++.h>
using namespace std;

int main() {
    int q, n, k;

    cin >> q;
    while (q--) {
        cin >> n >> k;
        int l = 1e8 + 10, h = 0;
        while (n--) {
            int x;
            cin >> x;
            l = min (l, x);
            h = max (h, x);
        }
        if (l+k < h-k)
            puts("-1");
        else
            cout << l+k << endl;
    }

    return 0;
}

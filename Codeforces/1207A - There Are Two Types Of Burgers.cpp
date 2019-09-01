#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, b, p, f, h, c;

    cin >> t;
    while (t--) {
        cin >> b >> p >> f >> h >> c;
        if (b%2) --b;
        int res = 0;
        if (h > c) {
            res = min(b/2, p)*h;
            b = b/2 - min(b/2, p);
            if (b > 0)
                res += min(b, f) * c;
        }
        else {
            res = min(b/2, f)*c;
            b = b/2 - min(b/2, f);
            //cout << b << endl;
            if (b > 0)
                res += min(b, p) * h;
        }

        cout << res << endl;
    }

    return 0;
}

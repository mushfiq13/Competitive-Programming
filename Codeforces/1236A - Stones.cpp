#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b, c;

    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        int ans = 0;
        ans = min(b/2, a) + min(b/2, a) * 2;
        ans += min ((b - min(b/2, a) * 2), c/2) + min ((b - min(b/2, a) * 2), c/2) * 2;
        int ans2 = 0;
        ans2 = min(c/2, b) + min(c/2, b) * 2;
        ans2 += min (a, (b - min(c/2, b)) / 2) + min (a, (b - min(c/2, b)) / 2) * 2;
        cout << max (ans, ans2) << endl;
    }

    return 0;
}

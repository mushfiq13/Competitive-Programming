#include <bits/stdc++.h>
using namespace std;

int BS (int a, int b, int c) {
    int l = min (a, min(b, c));
    int h = max (a, max(b, c));
    int ans = 1e9;
    while (l <= h) {
        int m = (l + h) >> 1;
        int s1 = a, s2 = b, s3 = c;
        if (s1 < m && s2) {
            int t = min (m-s1, s2);
            s1 += t;
            s2 -= t;
        }
        if (s3 < m && s2) {
            int t = min (m-s3, s2);
            s3 += t;
            s2 -= t;
        }
        bool can = true;
        if (s1 > m) {
            can = false;
            s2 += s1-m;
            s1 -= m;
        } else if (s3 > m && can) {
            s2 += s3-m;
            s3 -= m;
        }
        if (s1 <= m && s2 <= m && s3 <= m) {
            ans = min (ans, m);
            h = m-1;
        } else if (s1 > m || s2 > m || s3 > m)
            l = m+1;
        else h = m-1;
    }
    return ans;
}

int main() {
    int t, a, b, c;

    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        cout << BS (a, b, c) << endl;
    }

    return 0;
}

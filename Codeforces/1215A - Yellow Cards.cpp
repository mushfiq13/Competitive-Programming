#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

int count (int v, int n, int k) {
    int cnt = 0;
    for (int i=1; i<=v && n>0; ++i)
        if (k <= n) {
            ++cnt;
            n -= k;
        }
    return cnt;
}

int main() {
    int a, b, k1, k2, n;
    cin >> a >> b >> k1 >> k2 >> n;

    cout << max (0, n - (a*(k1-1)+b*(k2-1))) << " ";

    int cnt = count (a, n, k1);
    int mx = cnt + count (b, n-cnt*k1, k2);
    cnt = count (b, n, k2);
    mx = max (mx, cnt + count (a, n-cnt*k2, k1));

    cout << mx << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, h, m;
    int ar[51];

    cin >> n >> h >> m;
    for (int i=1; i<=n; ++i)
        ar[i] = -1;

    for (int i=0; i<m; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        for (int j=l; j<=r; ++j)
            if (ar[j]>-1 && ar[j] > x)
                ar[j] = x;
            else if (ar[j] == -1)
                ar[j] = x;
    }

    int ans = 0;
    for (int i=1; i<=n; ++i) {
        if (ar[i] == -1) ans += h * h;
        else ans += ar[i] * ar[i];
    }
    cout << ans << endl;

    return 0;
}

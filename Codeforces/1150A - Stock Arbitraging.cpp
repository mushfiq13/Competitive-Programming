#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, r, x;
    int mx = 0, mn = 1001;

    cin >> n >> m >> r;
    for (int i=1; i<=n; ++i) {
        cin >> x;
        mn = min (x, mn);
    }
    for (int i=1; i<=m; ++i) {
        cin >> x;
        mx = max (x, mx);
    }

    if (mn > mx)
        cout << r << endl;
    else
        cout << mx*(r/mn) + r%mn << endl;

    return 0;
}

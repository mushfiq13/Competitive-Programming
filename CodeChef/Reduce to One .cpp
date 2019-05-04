#include <bits/stdc++.h>
using namespace std;

const int Mod = 1e9 + 7;

long long ans[1000002] = {0, 1, 5};

int main()
{
    int t, n;
    long long p = 6;
    for (int i=4; i<=1000001; ++i) {
        ans[i-1] = (i * p) % Mod - 1;
        p = ans[i-1] + 1;
    }

    cin >> t;

    while (t--) {
        cin >> n;
        cout << ans[n] << endl;
    }

    return 0;
}

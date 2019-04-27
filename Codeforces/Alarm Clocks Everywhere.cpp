#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    long long x, f;

    cin >> n >> m;

    cin >> f >> x;
    long long g = x-f, l = x;

    for (int i=3; i<=n; ++i) {
        cin >> x;
        g = __gcd(g, x-l);
        l = x;
    }

    for (int i=1; i<=m; ++i) {
        cin >> x;
        if (g%x == 0) {
            puts("YES");
            cout << f << " " << i << endl;
            return 0;
        }
    }

    puts("NO");
    return 0;
}

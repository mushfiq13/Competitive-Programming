#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 1e6;;

    cin >> n;
    for (int i=1; i*i<=n; ++i)
        if (n%i == 0)
            ans = min (ans, 2*(i+n/i));

    cout << ans << endl;

    return 0;
}

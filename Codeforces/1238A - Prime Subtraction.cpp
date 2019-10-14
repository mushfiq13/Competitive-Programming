#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    ll x, y;

    cin >> t;
    while (t--) {
        cin >> x >> y;
        if (x-y != 1) puts("YES");
        else puts("NO");
    }
    return 0;
}

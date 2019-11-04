#include <bits/stdc++.h>
using namespace std;

int main() {
    int q, a, b, n, s;

    cin >> q;
    while (q--) {
        cin >> a >> b >> n >> s;
        int taken = n * min (s/n, a);
        if (s - taken <= b) puts("YES");
        else puts("NO");
    }

    return 0;
}

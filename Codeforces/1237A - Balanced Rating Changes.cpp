#include <bits/stdc++.h>
using namespace std;

const int MAX = 13845 + 10;

int main() {
    int n, x;

    cin >> n;
    int add = -1;
    for (int i=1; i<=n; ++i) {
        cin >> x;
        if (x % 2 == 0) cout << x/2 << endl;
        else {
            x += add;
            cout << x/2 << endl;
            add *= -1;
        }
    }

    return 0;
}

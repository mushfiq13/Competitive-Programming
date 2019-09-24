#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000 + 10;
const int MIN = -1e7;;

int main() {
    int n, ans = MIN;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        int sq = sqrt(x);
        if (sq*sq != x) ans = max (ans, x);
    }
    cout << ans << endl;
    return 0;
}

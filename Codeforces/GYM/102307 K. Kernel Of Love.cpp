#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1e5 + 10;

ll ans[MAX];

int main() {
    int t, n;

    ans[3] = 2;
    for (int i=3; i<=MAX; i+=3) {
        ans[i+1] = ans[i+2] = ans[i]+1;
        ans[i+3] = ans[i+2] + 1;
    }

    cin >> t;
    while (t--) {
        cin >> n;
        cout << ans[n] << endl;
    }

    return 0;
}

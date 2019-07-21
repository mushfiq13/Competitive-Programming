#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e6 + 10;

ll w[MAX];

int main() {
    string s;

    cin >> s;

    for (int i=1; s[i]; ++i)
        w[i] = s[i] == 'v' && s[i-1] == 'v' ? 1 + w[i-1] : w[i-1];

    ll ans = 0, n = s.size();
    w[n] = w[n-1];
    for (int i=2; s[i]; ++i) {
        if (s[i] == 'o')
            ans += (w[n] - w[i+1]) * (w[i-1] - w[0]);
    }

    cout << ans << endl;

    return 0;
}

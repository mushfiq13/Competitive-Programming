#include <bits/stdc++.h>
using namespace std;

const int MAX = 2000 + 10;

int a[MAX];
map<int, int> f;

int main() {
    int n;

    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        ++f[a[i]] ;
    }

    int ans = MAX;
    for (int i=1; i<=n; ++i) {
        if (f[a[i]] == 1) continue;
        map<int, int> mp;
        int tmp = 0;
        for (int j=1; j<i; ++j) {
            ++mp[a[j]] ;
            if (mp[a[j]] > 1) {
                tmp = a[j];
                break;
            }
        }
        if (mp[a[i]] == 2 || mp[tmp] == 2) continue;
        for (int j=n; j>=i; --j) {
            ++mp[a[j]];
            if (mp[a[j]] == 2) {
                ans = min (ans, j-i+1);
                break;
            }
        }
    }

    if (ans == MAX) ans = 0;
    cout << ans << endl;

    return 0;
}

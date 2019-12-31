#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAX = 1e5 + 10;

int a[MAX];
pii b[MAX];

bool cmp(pii x, pii y) {
    if (x.first == y.first)
        return x.second < y.second;
    return x.first < y.first;
}

int main() {
    int t, n;

    cin >> t;
    while (t--) {
        cin >> n;

        for (int i=1; i<=n; ++i) {
            cin >> a[i];
            b[i] = {a[i], i};
        }

        sort(b+1, b+n+1, cmp);

        ll id = n;
        ll ans = 0, sum = 0;
        for (int i=1; i<=n && id>0; ++i) {
            b[i].first -= sum;
            ans += id * b[i].first;
            sum += b[i].first;
            id = b[i].second;
            bool flag = false;
            while (i<=n && b[i].second >= id)
                ++i, flag = 1;
            --id;
            if (flag) --i;
        }

        cout << ans << endl;
    }

    return 0;
}

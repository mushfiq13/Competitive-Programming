#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int, int> mii;

int dd[3] = {3, 2, 1};

vi get_ID (vi v, mii f) {
    int mx = 0;
    for (int q : v)
        if (f[q] > mx) mx = f[q];
    vi ans;
    for (int q: v)
        if (f[q] == mx) ans.push_back(q);
    return ans;
}

int main() {
    int n, d, x;

    while (cin >> n, n) {
        int mx = 0;
        mii f, tie[3];
        while (n--) {
            cin >> d;
            for (int i=0; i<d; ++i) {
                cin >> x;
                f[x] += dd[i];
                tie[i][x] += dd[i];
                if (f[x] > mx) mx = f[x];
            }
        }

        vi ans;
        for (mii::iterator it=f.begin(); it!=f.end(); ++it) {
            if (it->second == mx) ans.push_back(it->first);
        }

        ans = get_ID (ans, tie[0]);
        ans = get_ID (ans, tie[1]);

        sort(ans.begin(), ans.end());
        for (int i=0; i<ans.size(); ++i) {
            if (i) putchar(' ');
            printf("%d", ans[i]);
        }
        puts("");
    }

    return 0;
}

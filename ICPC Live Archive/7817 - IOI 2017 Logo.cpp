#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef map<int, int> mii;

int dd[3] = {3, 2, 1};

vi get_ID (vi v, mii f) {
    if (v.size() == 1) return v;
    int mx = 0;
    for (int q : v) {
        if (f[q] > mx) mx = f[q];
    }
    vi v2;
    for (int q: v) {
        if (f[q] == mx) v2.push_back(q);
    }
    return v2;
}

int main() {
    int n, d, x;

    while (cin >> n, n) {
        int mx = 0;
        vi v;
        mii f, tie[3];
        while (n--) {
            cin >> d;
            for (int i=0; i<d; ++i) {
                cin >> x;
                if (!f[x]) v.push_back(x);
                f[x] += dd[i];
                tie[i][x] += dd[i];
                if (f[x] > mx) mx = f[x];
            }
        }

        vi v2;
        for (int q : v) {
            if (f[q] == mx) v2.push_back(q);
        }

        v = get_ID (v2, tie[0]);
        v = get_ID (v, tie[1]);

        sort(v.begin(), v.end());
        for (int i=0; i<v.size(); ++i) {
            if (i) putchar(' ');
            printf("%d", v[i]);
        }
        puts("");
    }

    return 0;
}

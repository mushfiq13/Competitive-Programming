#include <bits/stdc++.h>
using namespace std;

const int MAX = (int)1e5 + 99;
const int INF = (int)1e9 + 99;

struct data {
    int v, l, r;
};

int ar[MAX];
int Log[MAX];
data SpT[MAX][(int)log2(MAX) + 1];

void computeLog() {
    Log[1] = 0;
    for (int i=2; i<MAX; ++i)
        Log[i] = Log[i>>1] + 1;
}

data combine(data a, data b) {
    data ans;

    if (a.v == b.v) {
        if (a.v > 1) ans = a;
        else {
            int d1 = a.r - a.l + 1;
            int d2 = b.r - b.l + 1;
            if (a.r+1 == b.l) ans = {a.v, a.l, b.r};
            else if (d1 >= d2) ans = a;
            else ans = b;
        }
    }
    else if (a.v < b.v) ans = a;
    else ans = b;

    return ans;
}

void buildSparseT(int n) {
    for (int i=0; i<n; ++i)
        SpT[i][0] = {ar[i], i, i};

    for (int j=1; j <= Log[n]; ++j)
        for (int i=0; i + (1<<j) <= n; ++i)
            SpT[i][j] = combine(SpT[i][j-1], SpT[i + (1<<(j-1))][j-1]);
}

data query(int L, int R) {
    data ans = {INF, 0, 0};
    for (int j = Log[R-L+1]; j>=0; --j) {
        if ((1<<j) <= R-L+1) {
            ans = combine(ans, SpT[L][j]);
            L += 1 << j;
        }
    }
    return ans;
}

int main() {
    int t, n, q;

    computeLog();

    cin >> t;
    for (int Case=1; Case<=t; ++Case) {
        cin >> n >> q;
        for (int i=0; i<n; ++i)
            cin >> ar[i];

        buildSparseT(n);

        printf("Case %d:\n", Case);
        while (q--) {
            int l, r;
            cin >> l >> r;
            --l, --r;
            data ans = query(l, r);
            if (ans.v > 1)
                printf("%d %d %d\n", ans.v, ans.l+1, ans.l+1);
            else if (ans.v == 0)
                printf("0 %d %d\n", l+1, r+1);
            else
                printf("%d %d %d\n", ans.v, ans.l+1, ans.r+1);
        }
    }

    return 0;
}

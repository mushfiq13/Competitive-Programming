#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 99;
const int INF = 1e9 + 99;

int ar[MAX];
int Log[MAX];
int SpT[MAX][(int)log2(MAX)+1];

void computeLog() {
    Log[1] = 0;
    for (int i=2; i<MAX; ++i)
        Log[i] = Log[i>>1] + 1;
}

void buildSparseT(int n) {
    for (int i=0; i<n; ++i)
        SpT[i][0] = ar[i];

    for (int j=1; j <= Log[n]; ++j)
        for (int i=0; i + (1<<j) <= n; ++i)
            SpT[i][j] = min(SpT[i][j-1], SpT[i + (1<<(j-1))][j-1]);
}

int getMin(int L, int R) {
    int j = Log[R-L+1];
    return min(SpT[L][j], SpT[R - (1<<j) + 1][j]);
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

        printf("Scenario #%d:\n", Case);
        while (q--) {
            int l, r;
            cin >> l >> r;
            --l, --r;
            cout << getMin(l, r) << endl;
        }
    }
    return 0;
}

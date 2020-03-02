#include <bits/stdc++.h>
using namespace std;

const int MAX = 5e4 + 99;
const int INF = 1e9 + 99;

int ar[MAX];
int Log[MAX];
int SpT[MAX][(int)log2(MAX)+1];

void buildSparseT(int n) {
    Log[1] = 0;
    for (int i=2; i<=n; ++i)
        Log[i] = Log[i>>1] + 1;

    for (int i=0; i<n; ++i)
        SpT[i][0] = ar[i];

    for (int j=1; j <= Log[n]; ++j)
        for (int i=0; i + (1<<j) <= n; ++i)
            SpT[i][j] = max(SpT[i][j-1], SpT[i + (1<<(j-1))][j-1]);
}

int getMax(int L, int R) {
    int j = Log[R-L+1];
    return max(SpT[L][j], SpT[R - (1<<j) + 1][j]);
}

int main() {
    int n, m;

    cin >> n >> m;
    for (int i=0; i<n; ++i)
        cin >> ar[i];

    buildSparseT(n);

    int cnt = 0;
    while (m--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        if (r-l < 2)
            ++cnt;
        else if (getMax(l+1, r-1) <= ar[l])
            ++cnt;
    }

    cout << cnt << endl;
    return 0;
}

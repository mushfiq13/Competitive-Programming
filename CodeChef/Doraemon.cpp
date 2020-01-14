#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> A, d1;
vector<int> d2;

int main() {
    int t, n, m;

    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        A.clear();
        A.resize(n+10);
        d1.clear();
        d1.resize(n+10);
        for (int i=0; i<n; ++i)
            A[i].resize(m+10), d1[i].resize(m+10);

        d2.clear();
        d2.resize(n+10);

        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                scanf("%d", &A[i][j]);
            }
        }

        for (int i=0; i<n; ++i) {
            for (int f=0, l=0, r=-1; f<m; f++) {
                int k = (f>r) ? 1 : min(d1[i][l+r-f], r-f+1);
                while (0 <= f-k && f+k < m && A[i][f-k] == A[i][f+k]) {
                    k++;
                }
                d1[i][f] = k--;
                if (f + k > r) {
                    l = f - k;
                    r = f + k;
                }
            }
        }

        long long ans = 0;
        for (int i=0; i<m; ++i) {
            for (int f=0; f<n; ++f)
                d2[f] = 0;
            for (int f=0, l=0, r=-1; f<n; f++) {
                int k = (f>r) ? 1 : min(d2[l+r-f], r-f+1);
                while (0 <= f-k && f+k < n && A[f-k][i] == A[f+k][i]) {
                    k++;
                }
                d2[f] = k--;
                if (f + k > r) {
                    l = f - k;
                    r = f + k;
                }
                ans += min(d1[f][i], d2[f]);
            }
        }

        printf("%lld\n", ans);
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAX = 51;

int a[MAX][MAX];
bool b[MAX][MAX];

int main() {
    int n, m;

    cin >> n >> m;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }

    vector<pair<int, int>> v;
    for (int i=1; i<n; ++i) {
        for (int j=1; j<m; ++j) {
            if (a[i][j] && a[i][j+1] && a[i+1][j] && a[i+1][j+1]) {
                b[i][j] = b[i][j+1] = b[i+1][j] = b[i+1][j+1] = 0;
                v.push_back (make_pair (i, j));
            }
        }
    }

    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=m; ++j) {
            if (b[i][j]) {
                puts("-1");
                return 0;
            }
        }
    }

    cout << v.size() << endl;
    for (pair<int, int> p: v)
        printf("%d %d\n", p.first, p.second);

    return 0;
}

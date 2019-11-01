#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000 + 10;
const int INF = 1e9;

int fx[4] = {1, -1, 0, 0};
int fy[4] = {0, 0, 1, -1};
string cell[MAXN];

int bfs (int n, int m) {
    deque<pair<int, int>> q;
    vector<vector<int>> d (n, vector<int> (m, INF));

    q.push_back ({0, 0});
    d[0][0] = 0;
    while (!q.empty()) {
        int sx = q.front().first, sy = q.front().second;
        q.pop_front();
        if (sx == n-1 && sy == m-1) return d[sx][sy];
        for (int i=0; i<4; ++i) {
            int tx = sx + fx[i];
            int ty = sy + fy[i];
            if (tx>=0 && tx<n && ty>=0 && ty<m) {
                int len = cell[sx][sy] == cell[tx][ty] ? 0 : 1;
                if (d[tx][ty] > d[sx][sy]+len) {
                    d[tx][ty] = d[sx][sy] + len;
                    if (len) q.push_back ({tx, ty});
                    else q.push_front ({tx, ty});
                }
            }
        }
    }

    return d[n-1][m-1];
}

int main() {
    int test, n, m;

    scanf("%d", &test);
    for (int Case=1; Case<=test; ++Case) {
        scanf("%d %d", &n, &m);
        for (int i=0; i<n; ++i)
            cin >> cell[i];
        printf("Case %d: %d\n", Case, bfs (n, m));
    }
}

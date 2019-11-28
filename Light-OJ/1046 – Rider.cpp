#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

static char cell[12][12];
const int fx[] = {+1, +1, +2, +2, -1, -1, -2, -2};
const int fy[] = {+2, -2, +1, -1, +2, -2, +1, -1};

pair<int,int> bfs (const int r, const int c, const int sx, const int sy) {
    int tot_move = 0, count_rider = 0;;
    queue<pair<int,int>> q;
    vector<vector<int>> d (r, vector<int> (c, INF));

    q.push ({sx, sy});
    d[sx][sy] = 0;
    if (cell[sx][sy] != '.') count_rider = 1;
    while (!q.empty()) {
        int vx = q.front().first, vy = q.front().second;
        q.pop();
        for (int i=0; i<8; ++i) {
            int tx = vx + fx[i];
            int ty = vy + fy[i];
            if (tx>=0 && tx<r && ty>=0 && ty<c && d[tx][ty] == INF) {
                d[tx][ty] = d[vx][vy] + 1;
                if (cell[tx][ty] != '.') {
                    int k = cell[tx][ty] - '0';
                    tot_move += d[tx][ty]/k + (bool)(d[tx][ty]%k);
                    ++count_rider;
                }
                q.push ({tx, ty});
            }
        }
    }

    return {tot_move, count_rider};
}

int solve (const int m, const int n) {
    int tot_rider = 0;
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
            if (cell[i][j] != '.')
                ++tot_rider;

    int res = INF;
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j) {
            pair<int,int> ans = bfs (m, n, i, j);
            if (ans.second == tot_rider)
                res = min (res, ans.first);
        }

    return res==INF ? -1 : res;
}

int main() {
    static int test, m, n;

    scanf("%d", &test);
    for (int Case=1; Case<=test; ++Case) {
        scanf("%d %d", &m, &n);
        getchar();
        for (int i=0; i<m; ++i)
            fgets(cell[i], n*n, stdin);

        printf ("Case %d: %d\n", Case, solve(m, n));
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int MAXM = 105;

bool vis[MAXN][MAXM];
static int grid[MAXN][MAXM];
static int dx[8], dy[8];

pair<int, int> dfs (const int r, const int c, const int m, const int n, const int x, const int y) {
    vis[x][y] = 1;

    int Count = 0;
    int id = (m == n || !m || !n) ? 4 : 8;
    for (int i=0; i<id; ++i) {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx>=0 && tx<r && ty>=0 && ty<c && grid[tx][ty] == 1)
            ++Count;
    }

    pair<int, int> ans;
    if (Count&1) ans = {0, 1};
    else ans = {1, 0};
    for (int i=0; i<id; ++i) {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx>=0 && tx<r && ty>=0 && ty<c && !vis[tx][ty] && grid[tx][ty] == 1) {
            pair<int, int> t = dfs (r, c, m, n, tx, ty);
            ans.first += t.first;
            ans.second += t.second;
        }
    }

    return ans;
}

pair<int,int> solve (const int r, const int c, const int m, const int n) {
    if (m && n && m != n) {
        dx[0] = dx[1] = m; dx[4] = dx[5] = -m;
        dx[2] = dx[3] = n; dx[6] = dx[7] = -n;
        dy[0] = dy[4] = n; dy[1] = dy[5] = -n;
        dy[2] = dy[6] = m; dy[3] = dy[7] = -m;
    } else if (!m || !n) {
        dx[0] = dx[1] = dy[2] = dy[3] = 0;
        dx[2] = dy[0] = m+n;
        dx[3] = dy[1] = -(m+n);
    } else {
        dx[0] = dx[1] = dy[0] = dy[3] = m;
        dx[2] = dx[3] = dy[2] = dy[1] = -n;
    }

    return dfs (r, c, m, n, 0, 0);
}

int main (int argv, char ** argc) {
    static int test, r, c, m, n, w;

    scanf("%d", &test);
    for (static int Case=1; Case<=test; ++Case) {
        scanf("%d %d %d %d", &r, &c, &m, &n);
        scanf("%d", &w);

        for (int i=0; i<r; ++i)
            for (int j=0; j<c; ++j)
                grid[i][j] = 1, vis[i][j] = 0;

        while (w--) {
            int xi, yi;
            scanf("%d %d", &xi, &yi);
            grid[xi][yi] = -1;
        }

        pair<int,int> ans = solve (r, c, m, n);
        printf ("Case %d: %d %d\n", Case, ans.first, ans.second);
    }

    return 0;
}

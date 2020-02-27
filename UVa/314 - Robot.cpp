#include <bits/stdc++.h>
using namespace std;

const int INF = (int)1e9 + 99;

struct data {
    int r, c, dir, w;
};

bool used[55][55][5];
bool block[55][55];
int dr[] = {1, 0,-1,0};
int dc[] = {0,-1, 0,1};

int getDir(char ch) {
    if (ch == 's') return 0;
    if (ch == 'w') return 1;
    if (ch == 'n') return 2;
    return 3;
}

int bfs(int n, int m, int sx, int sy, int tx, int ty, int dir) {
    if (sx == tx && sy == ty) return 0;
    if (block[sx][sy] || sx<=0 || sx>=n || sy<=0 || sy>=m) return -1;

    queue<data> q;

    for (int i=0; i<=n; ++i)
        for (int j=0; j<=m; ++j)
            for (int k=0; k<5; ++k)
                used[i][j][k] = 0;

    q.push({sx, sy, dir, 0});
    used[sx][sy][dir] = 1;

    while (!q.empty()) {
        int vx = q.front().r;
        int vy = q.front().c;
        int dir = q.front().dir;
        int w = q.front().w;
        q.pop();

        if (vx == tx && vy == ty) return w;

        for (int j=1; j<=3; ++j) {
            int fx = vx + dr[dir] * j;
            int fy = vy + dc[dir] * j;
            if (fx > 0 && fx<n && fy>0 && fy<m) {
                if (block[fx][fy]) break;
                if (!used[fx][fy][dir]) {
                    used[fx][fy][dir] = 1;
                    q.push({fx, fy, dir, w+1});
                }
            }
        }

        if (!used[vx][vy][(dir+1)%4]) {
            used[vx][vy][(dir+1)%4] = 1;
            q.push({vx, vy, (dir+1)%4, w+1});
        }

        if (!used[vx][vy][(dir+3)%4]) {
            used[vx][vy][(dir+3)%4] = 1;
            q.push({vx, vy, (dir+3)%4, w+1});
        }
    }

    return -1;
}

int main() {
    int n, m;

    while (scanf("%d %d", &n, &m)) {
        if (!n && !m) return 0;

        for (int i=0; i<=n; ++i)
            for (int j=0; j<=m; ++j)
                block[i][j] = 0;

        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                int x;
                scanf("%d", &x);
                if (x)
                block[i][j] = block[i][j+1] = block[i+1][j] = block[i+1][j+1] = x;
            }
        }

        int sx, sy, tx, ty;
        string dir;
        cin >> sx >> sy >> tx >> ty >> dir;

        int ans = bfs(n, m, sx, sy, tx, ty, getDir(dir[0]));

        printf("%d\n", ans);
    }

    return 0;
}

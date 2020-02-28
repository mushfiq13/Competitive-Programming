#include <bits/stdc++.h>
using namespace std;

struct data {
    int x, y, w;
};

bool block[210][210];
bool vis[210][210];
int dr[] = {1, 0,-1,0};
int dc[] = {0,-1, 0,1};

void dfs(int r, int c, int vx, int vy, int sx, int sy, int l) {
    vis[vx][vy] = 1;
    block[vx][vy] = 1;
    for (int i=0; i<4; ++i) {
        int tx = vx + dr[i];
        int ty = vy + dc[i];
        if (tx>0 && tx<=r && ty>0 && ty<=c && !vis[tx][ty]) {
            if ((sx-tx)*(sx-tx) + (sy-ty)*(sy-ty) <= l*l) {
                vis[tx][ty] = 1;
                dfs(r, c, tx, ty, sx, sy, l);
            }
        }
    }
}

void bfs(int r, int c) {
    if (block[1][1] || block[r][c]) {
        puts("Impossible.");
        return;
    }

    queue<data> q;

    for (int i=1; i<=r; ++i)
        for (int j=1; j<=c; ++j)
            vis[i][j] = 0;

    q.push({1, 1, 0});
    vis[1][1] = 1;

    while (!q.empty()) {
        int vx = q.front().x;
        int vy = q.front().y;
        int w = q.front().w;
        q.pop();

        if (vx == r && vy == c) {
            printf("%d\n", w);
            return;
        }

        for (int i=0; i<4; ++i) {
            int tx = vx + dr[i];
            int ty = vy + dc[i];
            if (tx>0 && tx<=r && ty>0 && ty<=c && !vis[tx][ty] && !block[tx][ty]) {
                vis[tx][ty] = 1;
                q.push({tx, ty, w+1});
            }
        }
    }

    puts("Impossible.");
}

int main() {
    int r, c, n, m;

    while (cin >> r >> c) {
        if (!r && !c) return 0;

        for (int i=1; i<=r; ++i)
            for (int j=1; j<=c; ++j)
                block[i][j] = 0;

        cin >> m;
        while (m--) {
            int x, y;
            cin >> x >> y;
            block[x][y] = 1;
        }

        cin >> n;
        while (n--) {
            int x, y, l;
            cin >> x >> y >> l;
            for (int i=1; i<=r; ++i)
                for (int j=1; j<=c; ++j)
                    vis[i][j] = 0;
            dfs(r, c, x, y, x, y, l);
        }

        bfs(r, c);
    }
}

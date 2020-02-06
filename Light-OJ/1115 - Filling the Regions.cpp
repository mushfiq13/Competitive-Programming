#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> vis;
static char s[55][55];
int dr[] = {0,1, 0,-1};
int dc[] = {1,0,-1, 0};

void doNotFill(int sx, int sy, int n, int m, char c) {
    if (vis[sx][sy]) return;
    vis[sx][sy] = 1;
    for (int i=0; i<4; ++i) {
        int tx = sx + dr[i];
        int ty = sy + dc[i];
        if (tx>=0 && tx<n && ty>=0 && ty<m && !vis[tx][ty] && c != s[tx][ty]) {
            doNotFill(tx, ty, n, m, c);
        }
    }
}

void doFill(int n, int m, char c) {
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            if (!vis[i][j]) s[i][j] = c;
}

int main(int argc, char **argv) {
    static int test, n, m;

    scanf("%d", &test);
    for (int Case=1; Case<=test; ++Case) {
        scanf("%d %d", &n, &m);
        for (int i=0; i<n; ++i) {
            scanf("%s", &s[i]);
        }

        for (char c='A'; c<='Z'; ++c) {
            vis = vector<vector<bool>> (n, vector<bool>(m, 0));
            for (int i=0; i<m; ++i) {
                if (s[0][i] != c) doNotFill(0, i, n, m, c);
                if (s[n-1][i] != c) doNotFill(n-1, i, n, m, c);
            }
            for (int i=0; i<n; ++i) {
                if (s[i][0] != c) doNotFill(i, 0, n, m, c);
                if (s[i][m-1] != c) doNotFill(i, m-1, n, m, c);
            }
            doFill(n, m, c);
        }

        printf("Case %d:\n", Case);
        for (int i=0; i<n; ++i)
            printf("%s\n", s[i]);
    }

    return 0;
}

/*
2

7 10
..........
..ABCDEF..
..G....H..
..I....J..
..K....L..
..MNOPQR..
..........

9 10
FGGGGGGDHH
F.BBBBBD.H
F.B...BD.H
FBB...BD.E
FBBBBBBD.E
CCCCCCCC.E
..C....C.E
..CCCCCCCE
..........
*/

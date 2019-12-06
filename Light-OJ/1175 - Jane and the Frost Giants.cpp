#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MAX = 200 + 10;

struct Node {
    int x, y, j;
};

static char s[MAX][MAX];
int dr[4] = {0, 0,1,-1};
int dc[4] = {1,-1,0, 0};

int bfs (const int& r, const int& c) {
    queue<Node> q;
    vector<vector<int>> d (r, vector<int> (c, INF));

    int jr, jc;
    for (int i=0; i<r; ++i)
        for (int j=0; j<c; ++j)
            if (s[i][j] == 'F')
                q.push ({i, j, 0}), d[i][j] = 0;
            else if (s[i][j] == 'J')
                jr = i, jc = j;

    q.push ({jr, jc, 1});
    d[jr][jc] = 0;
    while (!q.empty()) {
        int vx = q.front().x, vy = q.front().y, isJ = q.front().j;
        q.pop();
        for (int i=0; i<4; ++i) {
            int tx = dr[i] + vx;
            int ty = dc[i] + vy;
            if (isJ && (tx<0 || tx>=r || ty<0 || ty>=c))
                return d[vx][vy]+1;
            if (tx>=0 && tx<r && ty>=0 && ty<c && s[tx][ty] != '#' && d[tx][ty] > d[vx][vy]+1) {
                d[tx][ty] = d[vx][vy] + 1;
                q.push ({tx, ty, isJ});
            }
        }
    }

    return -1;
}

int main(int argc, char ** argv) {
    static int test, r, c;

    scanf("%d", &test);
    for (int Case=1; Case<=test; ++Case) {
        scanf("%d %d", &r, &c);
        for (int i=0; i<r; ++i)
            scanf(" %s", s[i]);

        printf("Case %d: ", Case);
        int ans = bfs (r, c);
        if (ans == -1) printf("IMPOSSIBLE\n");
        else printf("%d\n", ans);
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int MAX = 55;
typedef long long ll;
typedef pair<int , int> pii;

struct info {
    int x, y, Count;
    info() {}
    info(int x, int y, int Count)
        : x(x), y(y), Count(Count) {}
};

vector<info> lake;

int n, m;
int vis[MAX][MAX];
char s[MAX][MAX];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool cmp (info a, info b) {
    return a.Count < b.Count;
}

int dfs (int r, int c) {
    int cnt = 0;
    for (int i=0; i<4; ++i) {
        int u = r + dx[i];
        int v = c + dy[i];
        if (u >= 0 && u < n && v >= 0 && v < m && !vis[u][v] && s[u][v] == '.') {
            vis[u][v] = 1;
            ++cnt ;
            cnt += dfs(u, v);
        }
    }
    return cnt;
}

void fill_cell (int r, int c) {
    s[r][c] = '*';
    for (int i=0; i<4; ++i) {
        int x = r + dx[i];
        int y = c + dy[i];
        if (s[x][y] == '.')
            fill_cell (x, y);
    }
}

int main()
{
    int k;

    scanf("%d %d %d", &n, &m, &k);
    getchar();
    for (int i=0; i<n; ++i)
        gets(s[i]);

    for (int i=0; i<m; ++i) {
        if (!vis[0][i] && s[0][i] == '.')
            vis[0][i] = 1, dfs(0, i);
        if (!vis[n-1][i] && s[n-1][i] == '.')
            vis[n-1][i] = 1, dfs(n-1, i);
    }

    for (int i=0; i<n; ++i) {
        if (!vis[i][0] && s[i][0] == '.')
            vis[i][0] = 1, dfs(i, 0);
        if (!vis[i][m-1] && s[i][m-1] == '.')
            vis[i][m-1] = 1, dfs(i, m-1);
    }

    for (int i=1; i<n-1; ++i)
        for (int j=1; j<m-1; ++j)
            if (!vis[i][j] && s[i][j] == '.') {
                vis[i][j] = 1;
                int cnt = dfs(i, j) + 1;
                lake.push_back(info(i, j, cnt));
            }

    int Min = 0;
    if (k < lake.size()) {
        sort (lake.begin(), lake.end(), cmp);
        for (int i=0, sz=lake.size(); k<sz; ++i, ++k) {
            fill_cell(lake[i].x, lake[i].y);
            Min += lake[i].Count;
        }
    }

    printf("%d\n", Min);
    for (int i=0; i<n; ++i)
        puts(s[i]);

    return 0;
}

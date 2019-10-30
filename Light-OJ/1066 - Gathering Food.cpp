#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9;

string s[12];
int d[12][12];
int vis[12][12];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs (int n, char ch) {
    int r=-1, c;
    queue<pii> q;
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            vis[i][j] = d[i][j] = 0;

    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (s[i][j] == ch) r = i, c = j;

    if (r == -1) return -1;
    s[r][c] = '.';
    vis[r][c] = 1;
    q.push(make_pair(r, c));
    while (!q.empty()) {
        r = q.front().first;
        c = q.front().second;
        q.pop();
        for (int i=0; i<4; ++i) {
            int x = dx[i] + r;
            int y = dy[i] + c;
            if (x<n && y<n && x>=0 && y>=0 && !vis[x][y] && (s[x][y] == '.' || s[x][y] == ch+1)) {
                q.push(make_pair(x,y));
                vis[x][y] = 1;
                d[x][y] = d[r][c] + 1;
                if (s[x][y] == ch+1)
                    return d[x][y];
            }
        }
    }

    return -1;
}

int main() {
    int test, n;

    scanf("%d", &test);
    for (int Case=1; Case<=test; ++Case) {
        scanf("%d", &n);

        char hig = 'A';
        for (int i=0; i<n; ++i) {
            cin >> s[i];
            for (int j=0; j<n; ++j)
                if (s[i][j] >= 'A' && s[i][j] <= 'Z')
                    hig = max (s[i][j], hig);
        }

        int ans = 0;
        for (char ch='A'; ch<hig; ++ch) {
            int t = bfs (n, ch);
            if (t == -1) { ans = -1; break; }
            ans += t;
        }

        if (ans == -1)
            printf("Case %d: Impossible\n", Case);
        else
            printf("Case %d: %d\n", Case, ans);
    }

    return 0;
}

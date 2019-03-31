#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

typedef pair <int,int> PII;
char s[500][501];
int ans[500][500];
int fx[] = {-1,0,1,0};
int fy[] = {0,-1,0,1};

int bfs(int n, int m)
{
    queue <PII> q;
    PII temp[n*m];
    int vis[n][m] = {};

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (s[i][j]=='#' || vis[i][j])
                continue;
            int x=i, y=j, cont=0, r=0;

            q.push(make_pair(x,y));
            vis[x][y] = 1;
            if (s[x][y] == 'C')
                cont = 1;

            temp[r].first = x;
            temp[r].second = y;
            ++r;

            while(!q.empty()) {
                PII u = q.front();
                q.pop();
                for (int k=0; k<4; ++k) {
                    x = u.first + fx[k];
                    y = u.second + fy[k];
                    if (x>=0 && x<n && y>=0 && y<m && s[x][y]!='#' && !vis[x][y]) {
                        vis[x][y] = 1;
                        if (s[x][y] == 'C')
                            ++cont;
                        temp[r].first = x;
                        temp[r].second = y;
                        ++r;
                        q.push(make_pair(x,y));
                    }
                }
            }

            for (int k=0; k<r; ++k)
                ans[temp[k].first][temp[k].second] = cont;
        }
    }
}

int main()
{
    int t, n, m, q, cs=0;

    scanf("%d", &t);

    while(t--) {
        scanf("%d%d%d", &n, &m, &q);
        scanf("%d", &q);

        for (int i=0; i<n; ++i) {
            scanf(" %s", s[i]);
            for (int j=0; j<m; ++j)
                ans[i][j] = 0;
        }

        bfs(n,m);

        printf("Case %d:\n", ++cs);
        while(q--) {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%d\n", ans[x-1][y-1]);
        }
    }

    return 0;
}

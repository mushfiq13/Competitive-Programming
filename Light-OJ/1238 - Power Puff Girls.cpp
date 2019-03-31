#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

typedef pair <int,int> PII;
char s[20][21];
int fx[] = {-1,0,1,0};
int fy[] = {0,-1,0,1};

int bfs(int n, int m, int x, int y)
{
    queue <PII> q;
    int dist [n][m] = {};

    q.push(make_pair(x,y));
    dist[x][y] = 1;

    while(!q.empty()) {
        PII u = q.front();
        q.pop();
        for (int k=0; k<4; ++k) {
            x = u.first + fx[k];
            y = u.second + fy[k];
            if (x>=0 && x<n && y>=0 && y<m && s[x][y]!='#'
                && s[x][y]!='m' && !dist[x][y]) {
                dist[x][y] = dist[u.first][u.second]+1;
                if (s[x][y] == 'h')
                    return dist[x][y]-1;
                q.push(make_pair(x,y));
            }
        }
    }
}

int main()
{
    int t, n, m, cs=0;

    scanf("%d", &t);

    while(t--) {
        scanf("%d%d", &n, &m);

        for (int i=0; i<n; ++i)
            scanf(" %s", s[i]);

        int res = 0, cont = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (s[i][j]=='a' || s[i][j]=='b' || s[i][j]=='c') {
                    int temp = bfs(n,m,i,j);
                    if (temp>res)
                        res = temp;
                    ++cont;
                    if (cont == 3) break;
                }
            }
            if (cont == 3) break;
        }

        printf("Case %d: %d\n", ++cs, res);
    }

    return 0;
}

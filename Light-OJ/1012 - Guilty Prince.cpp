#include <iostream>
#include <cstdio>
using namespace std;

char s[20][21];
int w, h, cont;
int vis[20][20];

void dfs(int i, int j)
{
    if (i<0 || i>=h || j<0 || j>=w || s[i][j]=='#' || vis[i][j]) return;
    vis[i][j] = 1;
    ++cont;
    dfs(i-1,j);
    dfs(i,j-1);
    dfs(i+1,j);
    dfs(i,j+1);
}

int main()
{
    int t, cs=0;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &w, &h);
        int r, c;
        for (int i=0; i<h; i++) {
            cin >> s[i];
            for (int j=0; j<w; ++j) {
                vis[i][j] = 0;
                if (s[i][j] == '@') {r=i; c=j;}
            }
        }

        cont = 0;
        dfs(r,c);

        printf("Case %d: %d\n", ++cs, cont);
    }

    return 0;
}

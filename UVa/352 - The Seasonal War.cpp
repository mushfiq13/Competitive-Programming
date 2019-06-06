#include <bits/stdc++.h>
using namespace std;

const int MAX = 26;

bool vis[MAX][MAX];
string s[MAX];

int fx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int fy[] = {-1, 0, 1, 1, -1, -1, 0, 1};

void dfs (int r, int c, int n) {
    for (int k=0; k<8; ++k) {
        int x = r+fx[k], y = c+fy[k];
        if (x>=0 && x<n && y>=0 && y<n && s[x][y] == '1' && !vis[x][y]) {
            vis[x][y] = 1;
            dfs (x, y, n);
        }
    }
}

int main() {
    int n, cs=0;

    while (~scanf("%d", &n)) {
        for (int i=0; i<n; ++i) {
            cin >> s[i];
            for (int j=0; j<n; ++j)
                vis[i][j] = 0;
        }

        int Count = 0;
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                if (s[i][j] == '1' && !vis[i][j]) {
                    ++Count ;
                    dfs (i, j, n);
                }

        printf("Image number %d contains %d war eagles.\n", ++cs, Count);
    }

    return 0;
}

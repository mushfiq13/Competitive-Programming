#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;

int a[MAX][MAX];
int b[5][5] = {
                {0, 0, 0, 0, 0},
                {0, 8, 9, 1,13},
                {0, 3,12, 7, 5},
                {0, 0, 2, 4,11},
                {0, 6,10,15,14}
               };

int main() {
    int n;

    cin >> n;
    int add = 0;
    for (int x=1; x<=n; x+=4) {
        for (int y=1; y<=n; y+=4) {
            for (int pos = 0; pos < 4; ++pos) {
                a[x][y+pos] = b[1][pos+1] + add;
                a[x+1][y+pos] = b[2][pos+1] + add;
                a[x+2][y+pos] = b[3][pos+1] + add;
                a[x+3][y+pos] = b[4][pos+1] + add;
            }
            add += 16;
        }
    }

    for (int x=1; x<=n; ++x) {
        for (int y=1; y<=n; ++y) {
            if (y > 1) putchar(' ');
            printf("%d", a[x][y]);
        }
        puts("");
    }

    return 0;
}

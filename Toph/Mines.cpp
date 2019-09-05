#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e5 + 10;

int main() {
    int r, c;
    string s[15];

    cin >> r >> c;
    for (int i=0; i<r; ++i)
        cin >> s[i];

    for (int i=0; i<r; ++i) {
        for (int j=0; j<c; ++j) {
            if (s[i][j] == '*') {
                putchar('*');
                continue;
            }
            int cnt = 0;
            if (i-1>=0 && j-1>=0 && s[i-1][j-1] == '*')
                ++cnt;
            if (i-1>=0 && s[i-1][j] == '*')
                ++cnt;
            if (i-1>=0 && j+1<c && s[i-1][j+1] == '*')
                ++cnt;
            if (j-1>=0 && s[i][j-1] == '*')
                ++cnt;
            if (j+1<c && s[i][j+1] == '*')
                ++cnt;
            if (i+1<r && j-1>=0 && s[i+1][j-1] == '*')
                ++cnt;
            if (i+1<r && s[i+1][j] == '*')
                ++cnt;
            if (i+1<r && j+1<c && s[i+1][j+1] == '*')
                ++cnt;
            if (cnt)
                printf("%d", cnt);
            else
                printf(".");
        }
        puts("");
    }

    return 0;
}


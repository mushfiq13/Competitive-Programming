#include <stdio.h>

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, -2, -1, 1, 2};

int main() {
    int t, r, c;
    scanf("%d", &t);
    for (int cs=1; cs<=t; ++cs) {
        scanf("%d %d", &r, &c);
        int ans = 0;
        for (int i=0; i<8; ++i)
            if (r+dx[i]>=1 && r+dx[i]<=8 && c+dy[i]>=1 && c+dy[i]<=8)
                ++ans;
        printf("Case %d: %d\n", cs, ans);
    }
    return 0;
}

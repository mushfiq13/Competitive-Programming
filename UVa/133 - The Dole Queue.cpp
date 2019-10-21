#include <bits/stdc++.h>
using namespace std;

const int MAX = 20 + 10;

map<int, int> f;

int get_x (int n, int x) {
    if (x>n) x = 1;
    while (f[x]) { ++x; if(x>n) x=1;}
    return x;
}

int get_y (int n, int y) {
    if (!y) y=n;
    while (f[y]) { --y; if(!y) y=n;}
    return y;
}

int main() {
    int n, m, k;

    while (cin >> n >> k >> m) {
        if (!n && !m && !k) return 0;

        f.clear();
        int x = 1, y = n;
        vector<int> ans;
        while (true) {
            x = get_x (n, x);
            for (int i=2; i<=k; ++i) {
                x = get_x (n, x+1);
            }
            ans.push_back(x);
            if (ans.size() == n) { f[x]=1; break; }

            y = get_y (n, y);
            for (int i=2; i<=m; ++i) {
                y = get_y (n, y-1);
            }
            f[x] = 1;
            if (x == y) continue;
            f[y] = 2;
            ans.push_back(y);
            if (ans.size() == n) break;
        }

        for (int i=0; i<n; ++i) {
            if (i && f[ans[i-1]] == 1 && f[ans[i]] == 1) putchar(',');
            printf("%3d", ans[i]);
            if (i && i<n-1 && f[ans[i]] == 2) putchar(',');
        }
        puts("");
    }
}

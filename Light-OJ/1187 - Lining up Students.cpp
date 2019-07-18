#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int a[MAX];
int seg[4 * MAX];

void build (int v, int L, int R) {
    if (L == R) {
        seg[v] = 1;
        return;
    }
    int mid = (L + R) / 2;
    build (v*2, L, mid);
    build (v*2+1, mid+1, R);
    seg[v] = seg[v*2] + seg[v*2+1];
}

int find_kth (int v, int L, int R, int k) {
    if (L == R) {
        seg[v] = 0;
        return L;
    }
    int mid = (L + R) / 2;
    int ans;
    if (k <= seg[v*2])
        ans = find_kth (v*2, L, mid, k);
    else
        ans = find_kth (v*2+1, mid+1, R, k-seg[v*2]);
    seg[v] = seg[v*2] + seg[v*2+1];
    return ans;
}

int main() {
    int t, n;

    scanf("%d", &t);
    for (int cs = 1; cs <= t; ++cs) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        build (1, 1, n);
        int ans;
        for (int i = n; i; --i) {
            ans = find_kth (1, 1, n, i - a[i]);
        }
        printf("Case %d: %d\n", cs, ans);
    }

    return 0;
}

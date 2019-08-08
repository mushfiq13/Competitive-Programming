#include <bits/stdc++.h>
using namespace std;

const int MAX = 5e5 + 10;

int a[MAX], par[MAX];
int seg[4 * MAX];
map<int, int> mp;

int find_set (int v) {
    return par[v] = par[v] == v ? v : find_set (par[v]);
}

void update (int v, int L, int R, int pos, int x) {
    if (L == R) {
        seg[v] = x;
        return;
    }
    int mid = (L + R) >> 1;
    if (pos <= mid)
        update (v*2, L, mid, pos, x);
    else
        update (v*2+1, mid+1, R, pos, x);
    seg[v] = seg[v*2] + seg[v*2+1];
}

int find_kth (int v, int L, int R, int l, int r, int k) {
    if (L == R)
        return L;
    int mid = (L + R) >> 1;
    if (k <= seg[v*2])
        return find_kth (v*2, L, mid, l, min(r, mid), k);
    else
        return find_kth (v*2+1, mid+1, R, max(l, mid+1), r, k-seg[v*2]);
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    for (int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        par[i] = i;
    }

    int l=0, r=0;
    for (int i = n; i >= 1; --i) {
        if (mp[a[i]]) {
            update (1, 1, n, mp[a[i]], 0);
            par[mp[a[i]]-1] = mp[a[i]];
        }
        mp[a[i]] = i;
        update (1, 1, n, i, 1);
        int rgt = find_kth (1, 1, n, 1, n, k);
        rgt += find_set (rgt) - rgt;
        if (rgt-i+1 >= r-l+1)
            l = i, r = rgt;
    }

    printf("%d %d\n", l, r);

    return 0;
}

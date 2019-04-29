// Segment Tree

#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000001

struct info {
    int lb, rb, ans;
    info() {}
    info(int lb_, int rb_, int ans_) : lb(lb_), rb(rb_), ans(ans_) {}
};

string s;
info seg[4*SIZE];

info combine (info l, info r)
{
    int tmp = min (l.lb, r.rb);
    int ans = l.ans + r.ans + tmp;
    int lb = l.lb + r.lb - tmp;
    int rb = l.rb + r.rb - tmp;
    return info (lb, rb, ans);
}

void build (int node, int L, int R)
{
    if (L == R) {
        seg[node] = s[L-1] == '(' ? info(1,0,0) : info(0,1,0);
        return;
    }
    int mid = (L + R) / 2;
    build (node*2, L, mid);
    build (node*2+1, mid+1, R);
    seg[node] = combine (seg[node*2], seg[node*2+1]);
}

info query (int node, int L, int R, int l, int r)
{
    if (l > r)
        return info (0, 0, 0);
    if (L == l && R == r)
        return seg[node];
    int mid = (L + R) / 2;
    return combine (
        query (node*2, L, mid, l, min(r, mid)),
        query (node*2+1, mid+1, R, max(l, mid+1), r)
    );
}

int main()
{
    int m, l, r;

    cin >> s >> m;
    int n = s.size();
    build (1, 1, n);

    while (m--) {
        scanf("%d %d", &l, &r);
        printf("%d\n", query (1, 1, n, l, r).ans * 2);
    }

    return 0;
}

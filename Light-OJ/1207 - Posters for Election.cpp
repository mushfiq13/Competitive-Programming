#include <bits/stdc++.h>
using namespace std;

const int Max = 2e5 + 5;

bool flag;
int ans;
int seg[4*Max], u[Max>>1], v[Max>>1];

void update (int node, int L, int R, int l, int r)
{
    if (l > r)
            return;
    if (seg[node]) return;
    if (L == l && R == r) {
            if (flag) {
                flag = false; ++ans;
            }
            seg[node] = 1;
            return;
    }
    int mid = (L + R) / 2;
    update (node * 2, L, mid, l, min (r, mid));
    update (node * 2 + 1, mid+1, R, max (l, mid+1), r);
    if (seg[node*2] && seg[node*2+1])
        seg[node] = 1;
}

int main (int argc, char **argv)
{
    int t, n, cs = 0;

    scanf("%d", &t);

    while (t--) {
            scanf("%d", &n);
            for (int i=1; i<=8*n; ++i)
                    seg[i] = 0;
            for (int i=1; i<=n; ++i)
                    scanf("%d %d", &u[i], &v[i]);
            ans = 0;
            for (int i=n; i>=1; --i) {
                flag = true;
                update (1, 1, 2*n, u[i], v[i]);
            }
            printf("Case %d: %d\n", ++cs, ans);
    }

    return 0;
}

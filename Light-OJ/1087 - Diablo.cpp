#include <bits/stdc++.h>
using namespace std;

#define MAX 2*100001

int ar[MAX];
int seg[4*MAX];
int id[4*MAX];

void build (int node, int L, int R)
{
    if (L == R) {
            seg[node] = ar[L] ? 1 : 0;
            id[node] = ar[L];
            return;
    }
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    build(lf, L, mid);
    build(rt, mid+1, R);
    seg[node] = seg[lf] + seg[rt];
}

void update (int node, int L, int R, int pos, int Id)
{
    if (L == R) {
            seg[node] = 1;
            id[node] = Id;
            return;
    }
    int mid = (L + R)/2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    if (pos <= mid)
            update (lf, L, mid, pos, Id);
    else
            update (rt, mid+1, R, pos, Id);
    seg[node] = seg[lf] + seg[rt];
}

void get_kth (int node, int L, int R, int k)
{
    if (L == R) {
        printf("%d\n", id[node]);
        seg[node] = 0;
        id[node] = 0;
        return;
    }
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    if (seg[lf] >= k)
        get_kth (lf, L, mid, k);
    else
        get_kth (rt, mid+1, R, k-seg[lf]);
    seg[node] = seg[lf] + seg[rt];
}

int main()
{
    int t, n, m, q, x, cs=0;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &q);

        m = n + q;
        for (int i=n+1; i<=m; ++i)
            ar[i] = 0;

        for (int i=1; i<=n; ++i)
            scanf("%d", &ar[i]);
        build (1, 1, m);

        printf("Case %d:\n", ++cs);
        for (int i=n; q--; ) {
            char ch;
            scanf(" %c %d", &ch, &x);
            if (ch == 'c') {
                if (x > seg[1])
                    puts("none");
                else
                    get_kth(1, 1, m, x);
            }
            else
                update(1, 1, m, ++i, x);
        }
    }

    return 0;
}

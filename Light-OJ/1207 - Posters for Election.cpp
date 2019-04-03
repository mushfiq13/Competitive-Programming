#include <cstdio>
#include <iostream>
using namespace std;

#define SIZE 2*100005

int map[4*SIZE];
int seg[4*SIZE];

void update (int node, int L, int R, int l, int r, int ith)
{
    if (l > r)
            return;
    if (L == l && R == r) {
            seg[node] = ith;
            return;
    }
    int mid = (L + R) / 2;
    update (node * 2, L, mid, l, min (r, mid), ith);
    update (node * 2 + 1, mid+1, R, max (l, mid+1), r, ith);
}

int query (int node, int L, int R, int ith)
{
    ith = max (ith, seg[node]);
    if (L == R) {
            if (ith && map[ith] == 0) {
                    map[ith] = 1;
                    return 1;
            }
            return 0;
    }
    int mid = (L + R) / 2;
    return query (node * 2, L, mid, ith)
            + query (node * 2 + 1, mid+1, R, ith);
}

int main (int argc, char **argv)
{
    int t, n, u, v, cs = 0;

    scanf("%d", &t);

    while (t--) {
            scanf("%d", &n);
            for (int i=1; i<=8*n; ++i)
                    seg[i] = map[i] = 0;

            for (int i=1; i<=n; ++i) {
                    scanf("%d %d", &u, &v);
                    update (1, 1, 2*n, u, v, i);
            }

            printf("Case %d: %d\n", ++cs, query (1, 1, 2*n, 0));
    }

    return 0;
}

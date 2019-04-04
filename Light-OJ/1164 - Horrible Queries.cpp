#include <cstdio>
#include <iostream>
using namespace std;
 
typedef long long pll;
 
#define SIZE 100001
 
struct data {
    pll sum;
    pll prop;
    data () {}
    data (int v, int x)
            : sum(v), prop(x) {}
} seg[4*SIZE];
 
void update (int node, int L, int R, int l, int r, int add)
{
    if (l > r)
            return;
    if (L == l && R == r) {
            seg[node].sum += add * (r - l + 1);
            seg[node].prop += add;
            return;
    }
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    update (lf, L, mid, l, min (r, mid), add);
    update (rt, mid+1, R, max (l, mid+1), r, add);
    seg[node].sum = seg[lf].sum + seg[rt].sum + seg[node].prop * (R - L + 1);
}
 
pll query (int node, int L, int R, int l, int r, pll carry)
{
    if (l > r)
            return 0;
    if (L == l && R == r)
            return seg[node].sum + carry * (r - l + 1);
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    return
            query (lf, L, mid, l, min (r, mid), carry + seg[node].prop)
            + query (rt, mid+1, R, max (l, mid+1), r, carry + seg[node].prop);
}
 
int main (int argc, char **argv)
{
    int t, n, c, m, x, y, v, cs=0;
 
    scanf("%d", &t);
 
    while (t--) {
            scanf("%d %d", &n, &c);
 
            for (int i=1; i<=4*n; ++i)
                    seg[i] = data (0, 0);
 
            printf("Case %d:\n", ++cs);
            while (c--) {
                    scanf("%d %d %d", &m, &x, &y);
                    ++x, ++y;
                    if (m == 0) {
                            scanf("%d", &v);
                            update (1, 1, n, x, y, v);
                    }
                    else
                            printf("%lld\n", query (1, 1, n, x, y, 0));
            }
    }
 
    return 0;
}

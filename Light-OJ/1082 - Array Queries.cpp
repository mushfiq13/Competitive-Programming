#include <cstdio>
#include <iostream>

using namespace std;

#define MAX 100001

int ar[MAX];
int tree[4*MAX];

void build( int at, int L, int R )
{
    if (L == R) {
        tree[at] = ar[L];
        return;
    }
    int mid = (L+R) / 2;
    build(at*2,L,mid);
    build(at*2+1,mid+1,R);
    tree[at] = tree[at*2]>tree[at*2+1] ? tree[at*2+1]
                : tree[at*2];
}

int query( int at, int L, int R, int l, int r )
{
    if (L>=l && R<=r)
        return tree[at];
    if (L>r || R<l) return 100005;
    int mid = (L+R) / 2;
    int x = query(at*2,L,mid,l,r);
    int y = query(at*2+1,mid+1,R,l,r);
    return x>y ? y : x;
}

int main()
{
    int t, n, q, cs=0;

    scanf("%d", &t);

    while(t--) {
        scanf("%d %d", &n, &q);

        for (int i=1; i<=n; ++i)
            scanf("%d", &ar[i]);

        build(1,1,n);

        printf("Case %d:\n", ++cs);
        while(q--) {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%d\n", query(1,1,n,l,r));
        }
    }

    return 0;
}

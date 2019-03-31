#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 100001

char s[SIZE+1];
int tree[4*SIZE];

void build (int at, int L, int R)
{
    tree[at] = 0;
    if (L == R) {
        tree[at] = s[L-1]-'0';
        return;
    }
    int mid = (L+R) / 2;
    build(at*2,L,mid);
    build(at*2+1,mid+1,R);
}

void update (int at, int L, int R, int l, int r)
{
    if (L == l && R == r) {
        tree[at] ^= 1;
        return;
    }
    int mid = (L + R) / 2;
    if (mid >= l)
        update (at*2, L, mid, l, min (r, mid));
    if (r >= mid+1)
        update (at*2+1, mid+1, R, max (l, mid+1), r);
}

int query (int at, int L, int R, int pos)
{
    if (L == R)
        return tree[at];
    int mid = (L + R) / 2;
    if (pos <= mid)
        return tree[at] ^ query (at*2, L, mid, pos);
    else
        return tree[at] ^ query (at*2+1, mid+1, R, pos);
}

int main (int argc, char **argv)
{
    int t, n, q, i, j, cs=0;
    char ch;

    scanf("%d", &t);

    while (t--) {
        scanf(" %s", s);
        n = strlen(s);

        build (1, 1, n);

        printf("Case %d:\n", ++cs);

        scanf("%d", &q);
        while (q--) {
            scanf(" %c %d", &ch, &i);
            if (ch == 'I') {
                scanf("%d", &j);
                update (1, 1, n, i, j);
            }
            else
                printf("%d\n", query (1, 1, n, i));
        }
    }

    return 0;
}

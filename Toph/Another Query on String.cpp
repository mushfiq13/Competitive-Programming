#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

#define SIZE 100000

int ar[SIZE+1];
int seg[4*SIZE][26];

void build (int node, int L, int R)
{
    if (L == R) {
            seg[node][ar[L]] = 1;
            return;
    }
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    build (lf, L, mid);
    build (rt, mid+1, R);
    for (int i=0; i<26; ++i)
        seg[node][i] = seg[lf][i] + seg[rt][i];
}

void update (int node, int L, int R, int pos, int new_val)
{
    --seg[node][ar[pos]];
    ++seg[node][new_val];
    if (L == R) {
            ar[pos] = new_val;
            return;
    }
    int mid = (L + R) / 2;
    if (pos <= mid)
            update (node * 2, L, mid, pos, new_val);
    else
            update (node * 2 + 1, mid+1, R, pos, new_val);
}

int query (int node, int L, int R, int l, int r, int x)
{
    if (l > r)
            return 0;
    if (L == l && R == r)
            return seg[node][x];
    int mid = (L + R) / 2;
    return query (node * 2, L, mid, l, min (mid, r), x)
            + query (node * 2 + 1, mid + 1, R, max (mid+1, l), r, x);
}

int main (int argc, char **argv)
{
    int n, m, t, x, y;
    char s[SIZE+1], ch;

    scanf("%d %d %s", &n, &m, s);

    for (int i=0; s[i]; ++i)
        ar[i+1] = s[i]-'a';

    build (1, 1, n);

    while (m--) {
            scanf("%d %d", &t, &x);
            if (t == 1) {
                    scanf(" %c", &ch);
                    update (1, 1, n, x, ch-'a');
            }
            else {
                    scanf("%d %c", &y, &ch);
                    printf("%d\n", query (1, 1, n, x, y, ch-'a'));
            }
    }

    return 0;
}

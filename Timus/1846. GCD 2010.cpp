#include <bits/stdc++.h>
using namespace std;

#define SIZE 100001

int ar[SIZE];
int seg[4*SIZE];
map <int, vector <int> > mp;

void update (int node, int L, int R, int pos, int v)
{
    if (L == R) {
            seg[node] = v;
            return;
    }
    int mid = (L + R)/2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    if (pos <= mid)
            update (lf, L, mid, pos, v);
    else
            update (rt, mid+1, R, pos, v);
    seg[node] = __gcd (seg[lf], seg[rt]);
}

int main()
{
    int q, n, zero = 0;
    char ch;

    scanf("%d", &q);
    for (int i=1; i<=q; ++i) {
        scanf(" %c %d", &ch, &n);
        if (ch == '+') {
            update (1, 1, q, i, n);
            mp[n].push_back(i);
            if (zero < 0) zero = 0;
            if (n == 0) ++zero ;
        }
        else {
            update (1, 1, q, mp[n].back(), 0);
            mp[n].pop_back();
            if (n == 0) --zero ;
        }
        if (seg[1] == 0 && zero == 0)
            puts("1");
        else
            printf("%d\n", seg[1]);
    }

    return 0;
}

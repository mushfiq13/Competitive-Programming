#include <bits/stdc++.h>
using namespace std;

const int Max = 1e5 + 10;
typedef struct Data data;
typedef long long ll;

struct Data {
    int lf, rt;
};

data node[Max];

void link (int a, int b)
{
    node[a].rt = b;
    node[b].lf = a;
}

void Swap (int x, int y)
{
    int xlf = node[x].lf, xrt = node[x].rt;
    int ylf = node[y].lf, yrt = node[y].rt;
    if (node[x].rt != y && node[x].lf != y) {
        link (y, xrt);
        link (ylf, x);
        link (xlf, y);
        link (x, yrt);
    }
    else if (node[y].rt != x) {
        link (xlf, y);
        link (x, yrt);
        link(y, x);
    }
    else {
        link (ylf, x);
        link (y, xrt);
        link(x, y);
    }
}

void shift_left (int x, int y)
{
    if (node[x].rt == y) return;
    link (node[x].lf, node[x].rt);
    link (node[y].lf, x);
    link (x, y);
}

void shift_right (int x, int y)
{
    if (node[y].rt == x) return;
    link (node[x].lf, node[x].rt);
    link (x, node[y].rt);
    link (y, x);
}

int main()
{
    ll n;
    int m, cs=0;

    while (~scanf("%lld %d", &n, &m)) {
        for (int i=0; i<=n+1; ++i) {
                node[i].lf = i-1;
                node[i].rt = i+1;
        }

        int rev = 0;
        for (int i=1; i<=m; ++i) {
                int c, x, y;
                scanf("%d", &c);
                if (c == 4)
                        rev ^= 1;
                else {
                        scanf("%d %d", &x, &y);
                        if (c == 1) {
                            if (rev == 0) shift_left(x, y);
                            else shift_right(x, y);
                        }
                        else if (c == 2) {
                            if (rev == 0) shift_right(x, y);
                            else shift_left(x, y);
                        }
                        else
                            Swap(x, y);
                }
        }

        ll sum = 0;
        for (int i=node[0].rt; i <= n; i = node[node[i].rt].rt)
            sum += i;
        if (rev && n%2==0)
            sum = (n * (n+1) >> 1) - sum;

        printf("Case %d: %lld\n", ++cs, sum);
    }

    return 0;
}

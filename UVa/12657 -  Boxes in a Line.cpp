#include <bits/stdc++.h>
using namespace std;

const int Max = 1e5 + 10;
typedef struct info Node;
typedef long long ll;

struct info {
    int v;
    Node *lf, *rt;
    info() {}
    info(int v) : v(v), lf(NULL), rt(NULL) {}
};

Node *node[Max];

void link (Node *x, Node *y)
{
    x->rt = y;
    y->lf = x;
}

void shift_left (Node *x, Node *y)
{
    if (x->rt == y) return;
    link (x->lf, x->rt);
    link (y->lf, x);
    link (x, y);
}

void shift_right (Node *x, Node *y)
{
    if (y->rt == x) return;
    link (x->lf, x->rt);
    link (x, y->rt);
    link (y, x);
}

void Swap (Node *x, Node *y)
{
    Node *xlf = x->lf, *xrt = x->rt;
    Node *ylf = y->lf, *yrt = y->rt;
    if (x->rt != y && x->lf != y) {
        link (y, xrt);
        link (ylf, x);
        link (xlf, y);
        link (x, yrt);
    }
    else if (y->rt != x) {
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

int main()
{
    ll n;
    int m, cs=0;

    while (~scanf("%lld %d", &n, &m)) {
        for (int i=0; i<=n+1; ++i)
            delete node[i];

        for (int i=0; i<=n+1; ++i)
            node[i] = new Node(i);
        node[0]->rt = node[1];
        node[n+1]->lf = node[n];
        for (int i=1; i<=n; ++i) {
            node[i]->rt = node[i+1];
            node[i]->lf = node[i-1];
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
                    if (rev == 0) shift_left(node[x], node[y]);
                    else shift_right(node[x], node[y]);
                }
                else if (c == 2) {
                    if (rev == 0) shift_right(node[x], node[y]);
                    else shift_left(node[x], node[y]);
                }
                else
                    Swap(node[x], node[y]);
            }
        }

        ll sum = 0;
        for (Node *curr = node[0]->rt; curr != NULL && curr != node[n+1]; curr = curr->rt) {
            sum += curr->v;
            if (curr->rt != NULL)
                curr = curr->rt;
        }
        if (rev && n%2 == 0)
            sum = (n * (n+1) >> 1) - sum;

        printf("Case %d: %lld\n", ++cs, sum);
    }

    return 0;
}

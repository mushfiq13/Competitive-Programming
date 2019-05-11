#include <bits/stdc++.h>
using namespace std;

const int Max = 1e5 + 10;
typedef struct Data data;

struct Data {
    int v;
    data *lf, *rt;
};

data *root, *tail, *idx[Max];

data*create_data (int val, data *left, data *right)
{
    data *new_data = new data;
    new_data->v = val;
    new_data->lf = left;
    new_data->rt = right;
    return new_data;
}

void link_left_right (data *node)
{
    data *left = node->lf, *right = node->rt;
    if (node == root) {
        root = right;
        root->lf = NULL;
    }
    else if (node == tail) {
        tail = left;
        tail->rt = NULL;
    }
    if (left != NULL) {
        left->rt = right;
        if (right != NULL)
            right->lf = left;
    } else if (right != NULL)
         right->lf = NULL;
    node->lf = node->rt = NULL;
}

void shift_left (data *x, data *y)
{
    if (x->rt == y) return;
    link_left_right(x);
    if (y->lf != NULL) {
        y->lf->rt = x;
        x->lf = y->lf;
    } else root = x;
    x->rt = y;
    y->lf = x;
}

void shift_right (data *x, data *y)
{
    if (y->rt == x) return;
    link_left_right(x);
    if (y->rt != NULL) {
        y->rt->lf = x;
        x->rt = y->rt;
    } else tail = x;
    x->lf = y;
    y->rt = x;
}

void Swap (data *x, data *y)
{
    if (x->rt == y) {// x and y are adjacent
        if (x->lf == NULL) root = y;
        if (y->rt == NULL) tail = x;
        x->rt = y->rt;
        if (y->rt != NULL)
            y->rt->lf = x;
        y->lf = x->lf;
        if (x->lf != NULL)
            x->lf->rt = y;
        x->lf = y;
        y->rt = x;
    }
    else if (y->rt == x) {// x and y are adjacent
        if (y->lf == NULL) root = x;
        if (x->rt == NULL) tail = y;
        y->rt = x->rt;
        if (x->rt != NULL)
            x->rt->lf = y;
        x->lf = y->lf;
        if (y->lf != NULL)
            y->lf->rt = x;
        y->lf = x;
        x->rt = y;
    }
    else {  // not adjacent
        data *left = y->lf, *right = y->rt;

        // firstly, move y to x
        if (x->lf != NULL)
            x->lf->rt = y;
        else
            root = y;
        if (x->rt == NULL)
            tail = y;
        y->lf = x->lf;
        y->rt = x->rt;
        if (x->rt != NULL)
            x->rt->lf = y;

        // now, move x to y
        if (right != NULL)
            right->lf = x;
        else
            tail = x;
        if (left == NULL)
            root = x;
        if (left != NULL)
            left->rt = x;
        x->lf = left;
        x->rt = right;
    }
}

int main()
{
    int n, m, cs=0;

    while (~scanf("%d %d", &n, &m)) {
        for (int i=1; i<=n; ++i)
            delete idx[i];

        root = create_data(1, NULL, NULL);
        data *curr = root, *prev;
        for (int i=2; i<=n; ++i) {
            curr->rt = create_data (i, curr, NULL);
            idx[i-1] = curr;
            curr = curr->rt;
        }
        tail = curr;
        idx[n] = curr;

        int rev = 0;
        for (int i=1; i<=m; ++i) {
            int c, x, y;
            scanf("%d", &c);
            if (c == 4)
                rev ^= 1;
            else {
                scanf("%d %d", &x, &y);
                if (c == 1) {
                    if (rev == 0)
                        shift_left(idx[x], idx[y]);
                    else
                        shift_right(idx[x], idx[y]);
                }
                else if (c == 2) {
                    if (rev == 0)
                        shift_right(idx[x], idx[y]);
                    else
                        shift_left(idx[x], idx[y]);
                }
                else
                    Swap(idx[x], idx[y]);
            }
        }

        long long sum = 0;
        if (rev == 0)
            for (curr = root; curr != NULL; curr = curr->rt) {
                sum += curr->v;
                if (curr->rt != NULL)
                    curr = curr->rt;
            }
        else
            for (curr = tail; curr != NULL; curr = curr->lf) {
                sum += curr->v;
                if (curr->lf != NULL)
                    curr = curr->lf;
            }

        printf("Case %d: %lld\n", ++cs, sum);
    }

    return 0;
}

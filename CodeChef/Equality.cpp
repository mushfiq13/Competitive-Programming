#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int A[MAX];
int inc[MAX], decr[MAX];
int rgt1[MAX], lef1[MAX];
int rgt2[MAX], lef2[MAX];

int main() {
    int n, q;

    scanf("%d %d", &n, &q);
    for (int i=1; i<=n; ++i)
        scanf("%d", &A[i]);

    int cnt = 0;
    for (int i=1; i<=n; ) {
        int l = i, r = i+1;
        while (r <= n && A[r-1] < A[r])
            ++r;
        if (r-l > 1) ++cnt;
        while (l < r) {
            inc[l] = cnt;
            rgt1[l] = r;
            lef1[l] = i-1;
            ++l;
        }
        i = r;
    }

    cnt = 0;
    for (int i=1; i<=n; ) {
        int l = i, r = i+1;
        while (r <= n && A[r-1] > A[r])
            ++r;
        if (r-l > 1) ++cnt;
        while (l < r) {
            decr[l] = cnt;
            rgt2[l] = r;
            lef2[l] = i-1;
            ++l;
        }
        i = r;
    }

    for (int i=0; i<q; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);

        int c1 = 0;
        if (rgt1[l]-l>1) ++c1;
        if (r-lef1[r]>1) ++c1;
        c1 += inc[lef1[r]] - inc[rgt1[l]-1];

        int c2 = 0;
        if (rgt2[l]-l>1) ++c2;
        if (r-lef2[r]>1) ++c2;
        c2 += decr[lef2[r]] - decr[rgt2[l]-1];

        if (c1 == c2) puts("YES");
        else puts("NO");
    }

    return 0;
}

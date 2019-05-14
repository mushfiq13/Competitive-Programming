#include <bits/stdc++.h>
using namespace std;

#define SIZE 2*100005

int seg[4*SIZE];

void update (int node, int L, int R, int l, int r)
{
    if (l > r)
            return;
    if (L == l && R == r) {
            seg[node] += 1;
            return;
    }
    int mid = (L + R) >> 1;
    update (node*2, L, mid, l, min (r, mid));
    update (node*2+1, mid+1, R, max (l, mid+1), r);
}

int query (int node, int L, int R, int pos)
{
    if (L == R)
            return seg[node];
    int mid = (L + R) >> 1;
    if (pos <= mid)
        return seg[node] + query (node*2, L, mid, pos);
    else
        return seg[node] + query (node*2+1, mid+1, R, pos);
}

int main (int argc, char **argv)
{
    int t, n, q, x, y, cs = 0;
    int segment[SIZE>>1][2], points[SIZE>>1];
    scanf("%d", &t);

    while (t--) {
        for (int i=0; i<=4*SIZE; ++i)
            seg[i] = 0;

        vector <int> v;
        scanf("%d %d", &n, &q);

        for (int i=1; i<=n; ++i) {
            scanf("%d %d", &x, &y);
            v.push_back(x) ;
            v.push_back(y) ;
            segment[i][0] = x;
            segment[i][1] = y;
        }

        for (int i=1; i<=q; ++i) {
            scanf("%d", &x);
            points[i] = x;
            v.push_back(x);
        }

        sort(v.begin(), v.end());
        map <int, int> mp;

        int m=1;
        for (vector<int>::iterator it=v.begin(); it!=v.end(); ++it)
            if (!mp[*it])
                mp[*it] = m++;

        for (int i=1; i<=n; ++i)
            update(1, 1, m, mp[segment[i][0]], mp[segment[i][1]]);
        printf("Case %d:\n", ++cs);
        for (int i=1; i<=q; ++i)
            printf("%d\n", query(1, 1, m, mp[points[i]]));
    }

    return 0;
}

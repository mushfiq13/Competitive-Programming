#include <bits/stdc++.h>
using namespace std;

const int Max = 1e5 + 5;
typedef pair<int, int> pii;

int answer[Max];
int a[Max], seg[4*Max];
map <int, int> mp;
vector <pii> qu[Max];

void update (int node, int L, int R, int l, int r, int v)
{
    if (R < l || L > r) return;
    if (L >= l && R <= r) {
        seg[node] = v;
        return;
    }
    int mid = (L + R) >> 1;
    update (node*2, L, mid, l, r, v);
    update (node*2+1, mid+1, R, l, r, v);
    seg[node] = seg[node*2] + seg[node*2+1];
}

int get_dis (int node, int L, int R, int l, int r)
{
    if (R < l || L > r) return 0;
    if (L >= l && R <= r) return seg[node];
    int mid = (L + R) >> 1;
    return get_dis (node*2, L, mid, l, r)
            + get_dis (node*2+1, mid+1, R, l, r);
}

int main()
{
    int t, n, q, cs = 0;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &q);

        for (int i=1; i<=4*n; ++i) {
            seg[i] = 0;
            if (i <= n) {
                scanf("%d", &a[i]);
                qu[i].clear();
            }
        }

        for (int i=1; i<=q; ++i) {
            int l, r;
            scanf("%d %d", &l, &r);
            qu[r].push_back(make_pair(l,i));
        }

        mp.clear();
        for (int i=1; i<=n; ++i) {
            if (!mp[a[i]]) {
                mp[a[i]] = i;
                update (1, 1, n, i, i, 1);
            } else {
                update (1, 1, n, mp[a[i]], mp[a[i]], 0);
                mp[a[i]] = i;
                update (1, 1, n, i, i, 1);
            }
            for (vector<pii>::iterator it=qu[i].begin(); it != qu[i].end(); ++it) {
                answer[it->second] = get_dis(1, 1, n, it->first, i);
            }
        }

        printf("Case %d:\n", ++cs);
        for (int i=1; i<=q; ++i) {
            printf("%d\n", answer[i]);
        }
    }

    return 0;
}

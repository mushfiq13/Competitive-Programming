#include <bits/stdc++.h>
using namespace std;

const int Max = 1e5 + 5;

struct query {
    int l, r, idx;
    query() {}
    query(int l, int r, int idx)
        : l(l), r(r), idx(idx) {}
};

vector <query> qu[Max];
int answer[Max];
int a[Max], par[Max];

int find_set (int v)
{
    return par[v] = par[v] == v ? v : find_set (par[v]);
}

int main()
{
    int t, n, q, cs=0;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &q);
        for (int i=1; i<=n; ++i) {
            par[i] = i;
            qu[i].clear();
        }
        for (int i=1; i<=n; ++i)
            scanf("%d", &a[i]);
        for (int i=1; i<=q; ++i) {
            int l, r;
            scanf("%d %d", &l, &r);
            qu[r].push_back(query(l, r, i));
        }
        stack <int> s;
        for (int i = 1; i <= n; ++i) {
            while (!s.empty() && a[s.top()] > a[i]) {
                par[s.top()] = i;
                s.pop();
            }
            s.push(i);
            for (query v : qu[i]) {
                answer[v.idx] = a[find_set(v.l)];
            }
        }
        printf("Case %d:\n", ++cs);
        for (int i=1; i<=q; ++i) {
            printf("%d\n", answer[i]);
        }
    }

    return 0;
}

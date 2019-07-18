#include <bits/stdc++.h>
using namespace std;

const int MAX = 305;
typedef pair<int, int> pii;

int par[MAX], Size[MAX];

int find_set (int v) {
    return par[v] = par[v] == v ? v : find_set (par[v]);
}

bool cmp (pii a, pii b) {
    return a.first < b.first;
}

int main() {
    int n, m, a[MAX];

    scanf("%d", &n);

    for (int i=1; i<=n; ++i) {
        scanf("%d", &a[i]);
        par[i] = i, Size[i] = 1;
    }

    for (int i=1; i<=n; ++i) {
        int u = find_set(i);
        string s;
        cin >> s;
        for (int j=0; s[j]; ++j) {
            if (s[j] == '1') {
                int v = find_set(j+1);
                if (u != v) {
                    if (Size[u] < Size[v])
                        swap (u, v);
                    par[v] = u;
                    Size[u] += Size[v];
                }
            }
        }
    }

    for (int i=1; i<=n; ++i) {
        int p = find_set (i);
        if (Size[p] > 1) {
            vector<pii> v;
            for (int j=i; j<=n; ++j) {
                if (find_set(j) == p) {
                    v.push_back(make_pair(a[j], j));
                    Size[j] = 1;
                }
            }
            vector<pii> v2(v);
            sort (v2.begin(), v2.end(), cmp);
            for (int j=0, sz=v2.size(); j<sz; ++j)
                a[v[j].second] = v2[j].first;
        }
    }

    for (int i=1; i<=n; ++i) {
        if (i > 1) putchar(' ');
        printf("%d", a[i]);
    }
    puts("");

    return 0;
}

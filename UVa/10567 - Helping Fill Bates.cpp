#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 + 10;

pair<int,int> a[MAX];

bool cmp (pair<int,int> x, pair<int,int> y) {
    if (x.first == y.first) return x.second < y.second;
    return x.first < y.first;
}

int BS (int v, int last_pos, int l, int h) {
    int pos = -1;
    while (l <= h) {
        int m = (l + h) >> 1;
        if (a[m].first == v) {
            if (a[m].second > last_pos) {
                pos = a[m].second;
                h = m-1;
            } else
                l = m+1;
        } else if (a[m].first > v)
            h = m-1;
        else
            l = m+1;
    }
    return pos;
}

int main() {
    static int q, n;
    static string s;

    cin >> s;
    for (int i=0; s[i]; ++i) {
        a[i] = {s[i]-'A', i};
    }

    n = s.size();
    sort (a, a+n, cmp);

    scanf("%d", &q);
    while (q--) {
        cin >> s;
        int st=-1, ed=-1, pos = -1;
        for (char c : s) {
            pos = BS (c-'A', pos, 0, n-1);
            if (pos == -1) break;
            if (st == -1) st = pos;
            else ed = pos;
        }
        if (pos == -1) puts("Not matched");
        else printf("Matched %d %d\n", st, ed);
    }

    return 0;
}

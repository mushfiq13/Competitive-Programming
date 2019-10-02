#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

const int MAX = 1e5 + 10;

int ar[MAX+1];
bool seg[4*MAX][26];

vi combine (vi a, vi b) {
    vi ans (26);
    for (int i=0; i < 26; ++i)
        if (b[i] || a[i])
            ans[i] = 1;
    return ans;
}

void build (int node, int L, int R) {
    if (L == R) {
        seg[node][ar[L]] = 1;
        return;
    }
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    build (lf, L, mid);
    build (rt, mid+1, R);
    for (int i=0; i<26; ++i)
        seg[node][i] = seg[lf][i] ? 1 : seg[rt][i] ? 1 : 0;
}

void update (int node, int L, int R, int pos, int new_val) {
    if (L == R) {
        seg[node][ar[pos]] = 0;
        ar[pos] = new_val;
        seg[node][new_val] = 1;
        return;
    }
    int mid = (L + R) / 2;
    int lf = node * 2;
    int rt = node * 2 + 1;
    if (pos <= mid)
        update (lf, L, mid, pos, new_val);
    else
        update (rt, mid+1, R, pos, new_val);
    for (int i=0; i<26; ++i)
        seg[node][i] = seg[lf][i] ? 1 : seg[rt][i] ? 1 : 0;
}

vi query (int node, int L, int R, int l, int r) {
    vi v(26);
    if (l > r)
        return v;
    if (L == l && R == r) {
        for (int i=0; i<26; ++i)
            v[i] = seg[node][i];
        return v;
    }
    int mid = (L + R) / 2;
    return combine (
        query (node * 2, L, mid, l, min (mid, r)),
        query (node * 2 + 1, mid + 1, R, max (mid+1, l), r)
    );
}

int main (int argc, char **argv) {
    string s;
    char ch;
    int q, c, l, r, pos;

    cin >> s >> q;

    for (int i=0; s[i]; ++i)
        ar[i+1] = s[i]-'a';

    int n = s.size();
    build (1, 1, n);

    while (q--) {
        cin >> c;
        if (c == 1) {
            cin >> pos >> ch;
            update (1, 1, n, pos, ch-'a');
        }
        else {
            cin >> l >> r;
            vi ans = query (1, 1, n, l, r);
            int cnt = 0;
            for (int i=0; i<26; ++i)
                if (ans[i]) ++cnt;
            printf("%d\n", cnt);
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MAX = 250000 + 10;

struct data {
    ll delta, cnt;
};

ll x;
ll C[4*MAX];
ll seg[4*MAX];
data A[4*MAX];
data B[4*MAX];

ll get_sum (ll n, ll a, ll b) {
    return n * (a + b) / 2;
}

void push (int v, int L, int R) {
    int mid = (L + R) / 2;
    int lf = v * 2;
    int rt = v * 2 + 1;
    int a = mid-L+1;
    int b = R-mid;

    if (C[v] != MAX) {
        seg[lf] = C[v] * a;
        seg[rt] = C[v] * b;
        C[lf] = C[rt] = C[v];
        C[v] = MAX;
        A[lf] = A[rt] = {0, 0};
        B[lf] = B[rt] = {0, 0};
    }
    if (A[v].cnt) {
        seg[lf] += A[v].delta * a + A[v].cnt * get_sum (a, 1, a);
        seg[rt] += (A[v].delta + a * A[v].cnt) * b + A[v].cnt * get_sum (b, 1, b);
        A[lf].delta += A[v].delta;
        A[rt].delta += A[v].delta + a * A[v].cnt;
        A[lf].cnt += A[v].cnt;
        A[rt].cnt += A[v].cnt;
        A[v] = {0, 0};
    }
    if (B[v].cnt) {
        seg[lf] += (B[v].delta + b * B[v].cnt) * a + B[v].cnt * get_sum (a, 1, a);
        seg[rt] += B[v].delta * b + B[v].cnt * get_sum (b, 1, b);
        B[lf].delta += B[v].delta + b * B[v].cnt;
        B[rt].delta += B[v].delta;
        B[lf].cnt += B[v].cnt;
        B[rt].cnt += B[v].cnt;
        B[v] = {0, 0};
    }
    seg[v] = seg[lf] + seg[rt];
}

void update (int v, int L, int R, int l, int r, char ch) {
    if (l > R || L > r) return;
    if (L >= l && R <= r) {
        ll k = R-L+1;
        if (ch == 'A') {
            ++A[v].cnt;
            A[v].delta += L-l;
            seg[v] += (L-l) * k + get_sum(k, 1, k);
        } else if (ch == 'B') {
            ++B[v].cnt;
            B[v].delta += r-R;
            seg[v] += (r-R) * k + get_sum(k, 1, k);
        } else {
            C[v] = x;
            seg[v] = k * x;
            A[v] = B[v] = {0, 0};
        }
        return;
    }
    if (A[v].cnt || B[v].cnt || C[v] != MAX)
        push (v, L, R);
    int mid = (L + R) / 2;
    int lf = v * 2;
    int rt = v * 2 + 1;
    update (lf, L, mid, l, r, ch);
    update (rt, mid+1, R, l, r, ch);
    seg[v] = seg[lf] + seg[rt];
}

ll get_s (int v, int L, int R, int l, int r) {
    if (l > r) return 0;
    if (L == l && R == r)
        return seg[v];
    if (A[v].cnt || B[v].cnt || C[v] != MAX)
        push (v, L, R);
    int mid = (L + R) / 2;
    return get_s (v*2, L, mid, l, min (r, mid))
            + get_s (v*2+1, mid+1, R, max (l, mid+1), r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char ch;
    int t, n, st, nd;

    scanf("%d", &t);
    for (int cs = 1; cs <= t; ++cs) {
        scanf("%d", &n);

        for (int i=1; i < 4*MAX; ++i) {
            seg[i] = 0;
            C[i] = MAX;
            A[i] = {0, 0};
            B[i] = {0, 0};
        }

        printf("Case %d:\n", cs);
        for (int i=0; i<n; ++i) {
            x = 0;
            getchar();
            scanf("%c %d%d", &ch, &st, &nd);
            if (ch == 'C')
                scanf("%lld", &x);
            if (ch != 'S')
                update (1, 1, MAX-1, st, nd, ch);
            else
                printf("%lld\n", get_s (1, 1, MAX-1, st, nd));
        }
    }

    return 0;
}

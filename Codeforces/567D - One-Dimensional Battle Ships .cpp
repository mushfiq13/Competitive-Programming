#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5 + 10;
typedef pair<int,int> pii;

int par[MAX], Size[MAX];
int q[MAX], mp[MAX];

void make_set (int n) {
    for (int i=1; i<=n; ++i) {
        if (par[i] != -1) {
            par[i] = i, Size[i] = 1;
            if (par[i-1] != -1)
                par[i-1] = i, Size[i] += Size[i-1];
        }
    }
}

int find_set (int v) {
    return par[v] = par[v] == v ? v : find_set (par[v]);
}

pii countShips (int v, int a) {
    int p = find_set(v);
    int ship = Size[p] / a;
    int space =  ship * a + (ship - 1);
    while (space > Size[p] && ship) {
        --ship ;
        space =  ship * a + (ship - 1);
    }
    mp[p] = ship;
    return make_pair(p, ship);
}

int main() {
    int n, m, k, a;

    cin >> n >> k >> a;
    cin >> m;
    for (int i=1; i<=m; ++i) {
        cin >> q[i];
        par[q[i]] = -1;
    }

    make_set (n);

    int Count = 0;
    for (int i=1; i<=n; ++i) {
        if (par[i] == -1) continue;
        pii t = countShips(i, a);
        Count += t.second;
        i = t.first;
    }

    if (Count >= k) {
        puts("-1");
    } else {
        for (int i=m; i>=1; --i) {
            par[q[i]] = q[i];
            Size[q[i]] = 1;
            if (par[q[i]-1] != -1 && q[i]-1 > 0) {
                Count -= mp[q[i]-1];
                mp[q[i]-1] = 0;
                par[q[i]-1] = find_set(q[i]);
                Size[q[i]] += Size[q[i]-1];
            }
            if (par[q[i]+1] != -1 && q[i]+1 <= n) {
                int p = find_set(par[q[i]+1]);
                Count -= mp[p];
                mp[p] = 0;
                par[q[i]] = p;
                Size[p] += Size[q[i]];
            }
            pii t = countShips(q[i], a);
            Count += t.second;
            if (Count >= k) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}

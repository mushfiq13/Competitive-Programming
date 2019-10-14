#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll INF = 1e12;

ll get_value (char ch) {
    if (ch <= '9') return ch-'0';
    return ch-'A'+10;
}

ll getBase10 (ll base, string y) {
    ll n = 0, power = 1;
    for (int i=(int) y.length()-1; i>=0; --i) {
        n += get_value(y[i]) * power;
        power *= base;
        if (n > INF || (i && power>INF)) return -1;
    }
    return n;
}

int getLowerBase (string y) {
    int b = 0;
    for (int i=0; y[i]; ++i)
        b = max (b, (int)get_value(y[i]));
    return max (2, b+1);
}

int main() {
    string y;
    int t, n, B;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);

        set<ll> canbe;
        ll x = -1;
        bool hasAnswer = true;

        for (int i=1; i<=n; ++i) {
            cin >> B >> y;
            if (!hasAnswer) continue;
            map<ll, bool> f;
            if (B == -1) {
                bool found = false;
                for (int base=getLowerBase(y); base<=36; ++base) {
                    ll tmp = getBase10 (base, y);
                    if (tmp == -1) break;
                    if (i == 1) canbe.insert(tmp);
                    else f[tmp] = 1;
                    found = 1;
                }
                if (!found) { hasAnswer = false; continue; }
            }
            else {
                ll tmp = getBase10 (B, y);
                if (tmp == -1 || (x>-1 && x != tmp)) { hasAnswer = false; continue; }
                x = tmp;
                if (i == 1) canbe.insert(tmp);
                else f[tmp] = 1;;
            }

            if (i == 1) continue;
            set<ll> s;
            for (auto it=canbe.begin(); it!=canbe.end(); ++it)
                if (f[*it]) s.insert(*it);;
            canbe = s;
            if (canbe.size() == 0) hasAnswer = false;
        }

        if (!hasAnswer) { puts("-1"); continue; }

        ll ans = x != -1 ? x : INF+1;
        if (x == -1)
        for (auto it=canbe.begin(); it!=canbe.end(); ++it) {
            ans = min (ans, *it);
        }

        printf("%lld\n", ans);
    }

    return 0;
}

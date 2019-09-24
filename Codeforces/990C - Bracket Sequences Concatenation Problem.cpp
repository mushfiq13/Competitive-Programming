#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 3e5 + 10;

map<ll, ll> pos, neg;

int main() {
    int n;
    ll ans = 0;
    string s;

    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> s;
        stack<char> stk;
        ll v = 0;
        for (int j=0; s[j]; ++j) {
            if (stk.size() && stk.top() == '(' && s[j] == ')')
                stk.pop();
            else
                stk.push(s[j]);
        }
        if (v != MAX) {
            bool l=false, r=false;
            while (!stk.empty()) {
                if (stk.top() == '(') { ++v; l = true; }
                else { v += -1; r = true; }
                stk.pop();
            }
            if (l && r) continue;
        }
        if (v < 0) { v *= -1; ans += pos[v]; ++neg[v]; }
        else { ans += neg[v]; ++pos[v]; }
    }

    ans += 2 * ((pos[0]-1) * (1+pos[0]-1) >> 1) + pos[0];
    cout << ans << endl;
    return 0;
}

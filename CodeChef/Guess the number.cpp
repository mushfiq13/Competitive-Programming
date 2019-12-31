#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    ll a, m;

    cin >> t;
    while (t--) {
        cin >> a >> m;

        /*
        ll n = 1e9 + 1, l = 1, h = n;
        while (l <= h) {
            ll mid = (l + h) >> 1;
            if (mid < m-a*mid)
                l = mid+1;
            else if (a*mid > m)
                h = mid-1;
            else
                n = min(n, mid), h = mid-1;
        }

        vector<ll> ans;
        while (n*a < m) {
            ll d = m - a*n;
            // check here the n, d
            // if n is an answer then, d should be divisor of m and n.
            //cout << n <<" "<<d<< endl;
            if (n%d == 0)
                ans.push_back(n);
            ++n;
        }

        int r = ans.size();
        cout << r << endl;
        for (int i=0; i<r; ++i) {
            if (i) putchar(' ');
            cout << ans[i];
        }
        puts("");
        */

        vector<ll> div;
        for (ll i=1; i*i <= m; ++i) {
            if (m%i == 0)
                div.push_back(i), div.push_back(m/i);
        }

        sort(div.begin(), div.end());

        vector<ll> ans;
        for (int i=div.size()-1; i>=0; --i) {
            ll d = div[i];
            ll n = (m-d) / a;
            if ((m-d)%a) continue;
            if (n<=0 || d<=0 || n<m-a*n || a*n > m) continue;
            if (n%d == 0)
                ans.push_back(n);
        }

        int r = ans.size();
        cout << r << endl;
        for (int i=0; i<r; ++i) {
            if (i) putchar(' ');
            cout << ans[i];
        }
        puts("");
    }

    return 0;
}
